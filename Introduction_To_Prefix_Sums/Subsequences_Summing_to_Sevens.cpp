#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("div7.in","r",stdin);
	freopen("div7.out","w",stdout);
    int n;
    cin>>n;
    vector<long long> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
        arr[i]%=7;
    }
    long long ans=0;
    map<long long,long long> m;
    for(long long i=1;i<=n;i++)
    {
        //cout<<i<<" "<<arr[i]<<endl;
        if(m.find((arr[i])%7)!=m.end())
        {
            //cout<<i<<" "<<arr[i]<<endl;
            ans=max(ans,i-m[(arr[i])%7]);
        }
        if(m.find(arr[i])==m.end())
        {
            m[arr[i]]=i;
        }
    }
    cout<<ans<<endl;
}