#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x;
    cin>>n>>x;
    long long* arr=new long long[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    map<long long ,long long> m;
    long long curr=0;
    long long count=0;
    for(int i=0;i<n;i++)
    {
        curr+=arr[i];
        if(curr==x)
            count++;
        if(m.find(curr-x)!=m.end())
        {
            count+=m[curr-x];
        }
        m[curr]++;
    }
    cout<<count<<endl;
}