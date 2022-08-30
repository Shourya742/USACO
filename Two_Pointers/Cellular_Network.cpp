#include<bits/stdc++.h>
using namespace std;
bool check(vector<long long>& arr,vector<long long>& brr,int n,int m,long long x)
{
    int curr=0;
    for(int i=0;i<n;i++)
    {
        while(curr<m && !(arr[i]>=brr[curr]-x && arr[i]<=brr[curr]+x))
        {
            curr++;
        }
    }
    return curr!=m;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<long long> brr(m);
    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
    }
    sort(brr.begin(),brr.end());
    long long l=0;
    long long r=1e10;
    long long ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(arr,brr,n,m,mid))
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