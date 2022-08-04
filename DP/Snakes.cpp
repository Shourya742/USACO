#include<bits/stdc++.h>
using namespace std;
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}
int main()
{
    setIO("snakes");
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        int mx=0;
        for(int j=i;j<n;j++)
        {
            mx=max(mx,arr[j]);
            mat[i][j]=mx;
        }
    }
   
    vector<vector<int>> dp(n+1,vector<int>(403,1e9));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=(i+1)*mat[0][i];
    }
     for(int i=1;i<=k;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int l=0;l<i;l++)
            dp[i][j]=min(dp[i][j],dp[l][j-1]+(i-l)*mat[l+1][i]);
        }
    }
    cout<<dp[n-1][k]-sum<<endl;
}