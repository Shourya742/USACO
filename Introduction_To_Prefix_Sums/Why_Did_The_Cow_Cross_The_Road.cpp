#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("maxcross.in","r",stdin);
	freopen("maxcross.out","w",stdout);
    int n,k,b;
    cin>>n>>k>>b;
    vector<int> arr(n+1);
    for(int i=0;i<b;i++)
    {
        int x;
        cin>>x;
        arr[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        arr[i]+=arr[i-1];
    }
    int ans=1e9;
    for(int i=k;i<=n;i++)
    {
        ans=min(ans,arr[i]-arr[i-k]);
    }
    cout<<ans<<endl;
}