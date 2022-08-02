#include<bits/stdc++.h>
using namespace std;
vector<int> edges[100004];
vector<pair<long long ,long long>> points(100004);
vector<bool> visited(100004);
long long mn_x,mx_x,mn_y,mx_y;
void dfs(int v)
{
    // cout<<points[v].first<<" "<<points[v].second<<endl;
    visited[v]=true;
    mn_x=min(points[v].first,mn_x);
    mx_x=max(points[v].first,mx_x);
    mn_y=min(points[v].second,mn_y);
    mx_y=max(points[v].second,mx_y);
    for(auto x: edges[v])
    {
        if(!visited[x])
        {
            dfs(x);
        }
    }
}

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}



int main()
{
    setIO("fenceplan");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>points[i].first>>points[i].second;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    long long ans=1e18;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            mn_x=1e18;
            mx_x=-1e18;
            mn_y=1e18;
            mx_y=-1e18;
            dfs(i);
            ans=min(ans,2LL*(mx_x - mn_x )+2LL*(mx_y-mn_y));
            //cout<<endl;
        }
    }
    cout<<ans<<endl;
}