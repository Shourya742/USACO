#include<bits/stdc++.h>
using namespace std;
char mat[1008][1004];
int visited[1004][1004];
int area[1000004];
int r;
int perimeter[1000005];
 int n;
void dfs(int x,int y,int curr)
{
    if(x<=0 || y<=0 || x>n || y>n || mat[x][y]=='.')
        return;
  ///  cout<<x<<" "<<y<<endl;
    visited[x][y]=curr;
    area[curr]++;
    if(visited[x-1][y]==0)
    dfs(x-1,y,curr);
    if(visited[x+1][y]==0)
    dfs(x+1,y,curr);
    if(visited[x][y+1]==0)
    dfs(x,y+1,curr);
    if(visited[x][y-1]==0)
    dfs(x,y-1,curr);
    
}
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}

int main()
{
       setIO("perimeter");

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(visited[i][j]==0 && mat[i][j]=='#')
            {
                dfs(i,j,++r);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(visited[i][j]!=0)
            {
                int now=visited[i][j];
                if(mat[i][j-1]!='#')
                    perimeter[now]++;
                if(mat[i-1][j]!='#')
                    perimeter[now]++;
                if(mat[i+1][j]!='#')
                    perimeter[now]++;
                if(mat[i][j+1]!='#')
                    perimeter[now]++;
            }
        }
    }
    int ar=0;
    int pr=0;
    
    for(int i=1;i<=r;i++)
    {
        if(area[i]>ar)
        {
            ar=area[i];
            pr=perimeter[i];
        }
        else if(area[i]==ar)
        {
            if(perimeter[i]<pr)
            {
                pr=perimeter[i];
            }
        }
    }
    cout<<ar<<" "<<pr<<endl;
}