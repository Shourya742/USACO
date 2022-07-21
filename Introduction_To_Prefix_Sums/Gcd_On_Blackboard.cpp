#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<int> suff(n+1);
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        suff[i]=arr[i];
        pre[i]=arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]=__gcd(arr[i],pre[i-1]);
    }
    for(int i=n-1;i>=1;i--)
    {
        suff[i]=__gcd(arr[i],suff[i+1]);
    }
    int ans=pre[n-1];
    for(int i=0;i<n-1;i++)
    {
        int left=pre[i];
        int right=suff[i+2];
        ans=max(ans,__gcd(left,right));
    }
    cout<<ans<<endl;
}