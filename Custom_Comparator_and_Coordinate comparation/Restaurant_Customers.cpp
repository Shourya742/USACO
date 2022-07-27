#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    vector<int> arr;
    vector<int> in;
    vector<int> out;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        in.push_back(a);
        out.push_back(b);
        arr.push_back(a);
        arr.push_back(b);
    }
    sort(arr.begin(),arr.end());
    vector<int> pre((int)arr.size()+2);
    for(auto x: in)
    {
        pre[upper_bound(arr.begin(),arr.end(),x)-arr.begin()]++;
    }
    for(auto x: out)
    {
        pre[upper_bound(arr.begin(),arr.end(),x)-arr.begin()+1]--;
    }
    for(int i=1;i<pre.size();i++)
    {
        pre[i]+=pre[i-1];
    }
    int mx=0;
    for(auto x: pre)
    {
        mx=max(mx,x);
    }
    cout<<mx<<endl;
}