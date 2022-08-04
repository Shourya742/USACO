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
        setIO("time");
    long long n,m,c;
    cin>>n>>m>>c;
    vector<long long> cost(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
    }
    vector<pair<long long,long long>> arr(m);
    for(int i=0;i<m;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    
    
    vector<vector<long long>> dp(n+1,vector<long long>(1002,-1e12));
    dp[1][0]=0;
    long long ans=0;
    for(int t=1;t<=1000;t++)
    {
        for(auto x: arr)
        {
            int u=x.first;
            int v=x.second;
            dp[v][t]=max(dp[v][t],dp[u][t-1]+cost[u]);
        }
        ans=max(ans,dp[1][t] - c*t*t);
    }
    cout<<ans<<endl;
}