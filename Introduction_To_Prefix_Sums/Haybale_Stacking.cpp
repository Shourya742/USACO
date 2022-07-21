#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("maxcross.in","r",stdin);
	freopen("maxcross.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n+2);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }
    for(int i=1;i<=n;i++)
    {
        arr[i]+=arr[i-1];
    }
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        a.push_back(arr[i]);
    }
    sort(a.begin(),a.end());
    cout<<a[(n)/2]<<endl;
}