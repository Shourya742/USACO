#include<bits/stdc++.h>
using namespace std;
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}
int n,m;
long long mat[1005][1004];
long long ways[1005][1005];
vector<pair<int,int>> v;
bool visited[1004][1004];
int dx[]={-1,1,0,0};
int dy[] = {0,0,-1,1};
void dfs(int x,int y,int mid)
{
   
    visited[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];
        if(!visited[X][Y] && X>=1 && X<=n && Y>=1 && Y<=m && abs(mat[X][Y]-mat[x][y])<=mid)
        {
            dfs(X,Y,mid);
        }
    }
}
bool check(long long x)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            visited[i][j]=false;
        }
    }
    dfs(v[0].first,v[0].second,x);
    
    for(auto x: v)
    {
        if(!visited[x.first][x.second])
            return false;
    }
    return true;
}
int main()
{
    setIO("ccski");
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>ways[i][j];
            if(ways[i][j])
                v.push_back({i,j});
        }
    }
    long long l=0;
    long long r=1e9;
    long long ans=1e18;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}