#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<long long,long long> m;
        m[0]=1;
       
        vector<long long> arr(n+1);
        for(int i=1;i<=n;i++)
        {
            arr[i]=s[i-1]-'0';
            arr[i]+=arr[i-1];
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(m.find(arr[i]-i)!=m.end())
            {
                ans+=m[arr[i]-i];
            }
            m[arr[i]-i]++;
        }
        cout<<ans<<endl;
    }
}