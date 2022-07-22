#include<bits/stdc++.h>
using namespace std;
vector<int> edges[3002];
int dead[3002];
void dfs(int v,vector<int>& visited)
{
    visited[v]=true;
    for(auto x: edges[v])
    {
        if(!visited[x] && !dead[x])
        {
            dfs(x,visited);
        }
    }
}
int main()
{
    freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> visited(n+1);
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i,visited);
        }
    }
    if(count>1)
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        for(int i=1;i<=n;i++)
        {
            visited[i]=0;
        }
        dead[x]=1;
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && !dead[i])
            {
                dfs(i,visited);
                c++;
            }
        }
        if(c==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}