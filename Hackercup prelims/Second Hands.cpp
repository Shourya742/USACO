#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int c=0;
    while(t--)
    {
        c++;
        int n,k;
        cin>>n>>k;
        map<int,int> m;
        int flag=0;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            m[arr[i]]++;
            if(m[arr[i]]>2)
                flag=1;
        }
        cout<<"Case #"<<c<<": ";
        if(n>2*k)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(flag)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        
    }
}