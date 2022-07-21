#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        arr[i]=s[i-1]-'0';
    }
    long long curr=1;
    for(int i=n;i>=1;i--)
    {
        arr[i]=(arr[i]*curr)%2019;
        curr=(curr*10)%2019;
    }
    for(int i=1;i<=n;i++)
    {
        arr[i]=(arr[i]+arr[i-1])%2019;
    }
    map<long long,long long> m;
    m[0]=1;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(m.find(arr[i])!=m.end())
        {
            ans=(ans+m[arr[i]]);
        }
        m[arr[i]]++;
    }
    cout<<ans<<endl;
}