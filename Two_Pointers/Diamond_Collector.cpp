#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("diamond.in","r",stdin);
	freopen("diamond.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int end=0;
    vector<int> right(n);
    for(int i=0;i<n;i++)
    {
        while(end<n && (arr[end]-arr[i])<=k )
            end++;
        right[i]=end-i;
    }
    vector<int> maxRight(n+1);
    for(int i=n-1;i>=0;i--)
    {
        maxRight[i]=max(maxRight[i+1],right[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,right[i]+maxRight[i+right[i]]);
    }
    cout<<ans<<endl;
}