#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}
int main()
{
    setIO("mountains");
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[i]={x-y,x+y};
    }
    sort(arr.begin(),arr.end(),cmp);
    int ans=0;
    int r=-1e9;
    for(int i=0;i<n;i++)
    {
        if(r<arr[i].second)
        {
            ans++;
            r=arr[i].second;
        }
    }
    cout<<ans<<endl;
}