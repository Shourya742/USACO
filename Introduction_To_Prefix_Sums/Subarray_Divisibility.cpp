#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long* arr=new long long[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    map<long long ,long long> m;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        m[(sum%n+n)%n]++;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(m[i]>1)
        {
            ans+=(m[i]*(m[i]-1))/2;
        }
    }
    ans+=m[0];
    cout<<ans<<endl;
}