#include<bits/stdc++.h>
using namespace std;
long long dp[200004][3][3];
long long solve(int idx,int f,int m,vector<int>& arr,int n)
{
    if(idx==n)
        return 0;
    long long ans=1e9;
    if(dp[idx][f][m]!=-1)
        return dp[idx][f][m];
    if(f==0)
    {
        if(m==0)
        {
            ans=min(ans,arr[idx]+solve(idx+1,0,m+1,arr,n));
        }
        else if(m==1)
        {
            ans=min(ans,solve(idx,1,0,arr,n));
            ans=min(ans,arr[idx]+solve(idx+1,0,m+1,arr,n));
        }
        else
        {
            ans=min(ans,solve(idx,1,0,arr,n));
        }
    }
    else
    {
        if(m==0)
        {
            ans=min(ans,solve(idx+1,1,m+1,arr,n));
        }
        else if(m==1)
        {
            ans=min(ans,solve(idx,0,0,arr,n));
            ans=min(ans,solve(idx+1,1,m+1,arr,n));
        }
        else
        {
            ans=min(ans,solve(idx,0,0,arr,n));
        }
    }
    return dp[idx][f][m]=ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long ans=solve(0,0,0,arr,n);
        cout<<ans<<endl;
    }
}