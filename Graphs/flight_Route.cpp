#include<bits/stdc++.h>
using namespace std;
vector<int> edges[200005];
vector<int> edgesT[200005];
bool visited[200004];
vector<int> order;
vector<int> v;
vector<vector<int>> comp;
void dfs(int v)
{
    visited[v]=true;
    for(int x: edges[v])
    {
        if(!visited[x])
        {
            dfs(x);
        }
    }
    order.push_back(v);
}
void dfs1(int x)
{
    visited[x]=true;
    v.push_back(x);
    for(auto u: edgesT[x])
    {
        if(!visited[u])
        {
            dfs1(u);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edgesT[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    memset(visited,false,sizeof(visited));
    reverse(order.begin(),order.end());
    for(auto x: order)
    {
        if(!visited[x])
        {
            dfs1(x);
            comp.push_back(v);
            v.clear();
        }
    }
   
    if(comp.size()==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        for(int i=1;i<comp.size();i++)
        {
            cout<<comp[i][0]<<" "<<comp[0][0]<<endl;
        }
    }
}