#include<bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
int visited[100005];
vector<int> component[100004];
int co=0;
void dfs(int s)
{
    visited[s]=co;
    component[co].push_back(s);
    for(int x: edges[s])
    {
        if(visited[x]==0)
        {
            dfs(x);
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
        edges[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {co++;
            dfs(i);
        }
    }
   if(co-1==0)
   {
       cout<<0<<endl;
   }
    else
    {
        cout<<co-1<<endl;
        vector<pair<int,int>> v;
 
        for(int i=2;i<=co;i++)
        {
            if(component[i].size()>=0)
            {
                v.push_back({component[1][0],component[i][0]});
            }
            
        }
        for(auto x: v)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        
    }
}