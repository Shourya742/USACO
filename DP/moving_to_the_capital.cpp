#include<bits/stdc++.h>
using namespace std;
vector<int> dis(100004);
vector<int> edges[100004];
vector<bool> visited(100004);
int dp[100002];
void dfs(int v)
{
    visited[v]=true;
    dp[v]=dis[v];
    for(auto x: edges[v])
    {
        if(!visited[x] && dis[x]>dis[v])
        {
            dfs(x);
        }
        if(dis[x]>dis[v])
            dp[v]=min(dp[v],dp[x]);
        else
            dp[v]=min(dp[v],dis[x]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            edges[i].clear();
            dp[i]=1e9;
            visited[i]=false;
            dis[i]=1e9;
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a].push_back(b);
        }
        queue<int> q;
        dis[1]=0;
        q.push(1);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto x: edges[it])
            {
                if(dis[x]>dis[it]+1)
                {
                    dis[x]=dis[it]+1;
                    q.push(x);
                }
            }
        }
        dp[1]=0;
        dfs(1);
        for(int i=1;i<=n;i++)
        {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
}