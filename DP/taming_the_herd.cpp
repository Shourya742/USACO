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
    setIO("taming");
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long dp[n+1][n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<=n;k++)
            {
                dp[i][j][k]=1e18;
            }
        }
    }
    if(arr[0]==0)
    {
        dp[0][0][1]=0;
    }
    else
    {
        dp[0][0][1]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=1;k<=i+1;k++)
            {
                if(j<i)
                {
                    dp[i][j][k]=dp[i-1][j][k];
                }
                else
                {
                    for(int p=0;p<i;p++)
                    {
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][p][k-1]);
                    }
                }
                if(arr[i]!=(i-j))
                {
                    dp[i][j][k]++;
                }
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        long long val=1e18;
        for(int j=0;j<n;j++)
        {
            val=min(val,dp[n-1][j][k]);
        }
        cout<<val<<endl;
    }
}