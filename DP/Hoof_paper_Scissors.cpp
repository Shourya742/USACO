#include<bits/stdc++.h>
using namespace std;
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}
long long dp[100005][3][25];
long long solve(int idx,int curr,int k,vector<int>& arr,int n)
{
    if(idx==n+1)
    {
        return 0;
    }
    if(dp[idx][curr][k]!=-1)
        return dp[idx][curr][k];
    long long ans=0;
    if(idx==0)
    {
        for(int i=0;i<3;i++)
        {
            ans=max(ans,solve(idx+1,i,k,arr,n));
        }
    }
    else
    {
        if(k>0)
        {
            if(arr[idx]==0 && curr == 2)
            {
                ans=max(ans,1+solve(idx+1,curr,k,arr,n));
            }
            else if(arr[idx]==1 && curr == 0)
            {
                ans=max(ans,1+solve(idx+1, curr,k,arr,n));
            }
            else if(arr[idx]==2 && curr==1)
            {
                ans=max(ans,1+solve(idx+1,curr,k,arr,n));
            }
            else
            {
                ans=max(ans,solve(idx+1,curr,k,arr,n));
                if(arr[idx]==0 )
                {
                    ans=max(ans,1+solve(idx+1,2,k-1,arr,n));
                    ans=max(ans,solve(idx+1,0,k-1,arr,n));
                    ans=max(ans,solve(idx+1,1,k-1,arr,n));
                }
                else if(arr[idx]==1)
                {
                    ans=max(ans,1+solve(idx+1,0,k-1,arr,n));
                    ans=max(ans,solve(idx+1,0,k-1,arr,n));
                    ans=max(ans,solve(idx+1,2,k-1,arr,n));
                }
                else if(arr[idx]==2)
                {
                    ans=max(ans,1+solve(idx+1,1,k-1,arr,n));
                    ans=max(ans,solve(idx+1,0,k-1,arr,n));
                    ans=max(ans,solve(idx+1,2,k-1,arr,n));
                }
            }
        }
        else
        {
             if(arr[idx]==0 && curr == 2)
            {
                ans=max(ans,1+solve(idx+1,curr,k,arr,n));
            }
            else if(arr[idx]==1 && curr == 0)
            {
                ans=max(ans,1+solve(idx+1, curr,k,arr,n));
            }
            else if(arr[idx]==2 && curr==1)
            {
                ans=max(ans,1+solve(idx+1,curr,k,arr,n));
            }
            else
            {
                ans=max(ans,solve(idx+1,curr,k,arr,n));
            }
        }
    }
    return dp[idx][curr][k]=ans;
}
int main()
{
    setIO("hps");
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='P')
        {
            arr[i]=0;
        }
        if(c=='H')
        {
            arr[i]=1;
        }
        if(c=='S')
        {
            arr[i]=2;
        }
    }
    long long ans=solve(0,0,k,arr,n);
    cout<<ans<<endl;
}