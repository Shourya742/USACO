#include<bits/stdc++.h>
using namespace std;
bool check(string& s,int n,int x,set<char>& m)
{
    multiset<char> d;
    for(int i=0;i<x;i++)
    {
        d.insert(s[i]);
    }
    int flag=1;
    if(d.size() >= m.size())
    for(auto y: m)
    {
        if(d.find(y)==d.end())
        {
            flag=0;
            break;
        }
    }
    else
        flag=0;
    if(flag)
        return true;
    for(int i=x;i<n;i++)
    {
        d.erase(d.find(s[i-x]));
        d.insert(s[i]);
        int f=1;
        if(d.size() >= m.size())
        {for(auto y: m)
        {
            if(d.find(y)==d.end())
            {
                f=0;
                break;
            }
        }}
        else
            f=0;
        if(f)
            return true;
    }
    return false;
}
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=1;
    int r=n;
    set<char> m;
    for(auto x: s)
        m.insert(x);
    int ans=1e9;
    vector<int> idx(200,-1);

    for(int i=0;i<n;i++)
    {
        idx[s[i]-'A']=i;
        int mn=1e9;
        int mx=-1e9;
        for(auto x: m)
        {
            mn=min(idx[x-'A'],mn);
            mx=max(idx[x-'A'],mx);
        }
        if(mn!=-1)
        {
            ans=min(ans,mx-mn+1);
        }
    }
    cout<<ans<<endl;
}