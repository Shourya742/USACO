#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> edges[1004];
vector<pair<long long,pair<long long,long long>>> e;
int par[10004];
int find(int x)
{
    if(par[x]==x)
        return x;
    return par[x]=find(par[x]);
}
int main()
{
    	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            long long w=(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
            edges[i].push_back({j,w});
            edges[j].push_back({i,w});
            e.push_back({w,{i,j}});
        }
    }
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
    }
    sort(e.begin(),e.end());
    long long mx=0;
    for(auto x: e)
    {
        int a=x.second.first;
        int b=x.second.second;
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            mx=max(mx,x.first);
            par[a]=b;
        }
    }
    cout<<mx<<endl;
}