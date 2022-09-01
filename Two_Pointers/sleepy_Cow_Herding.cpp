#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("herding.in","r",stdin);
	freopen("herding.out","w",stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int mnA=1e9;
    if(arr[n-2]-arr[0] == n-2 && arr[n-1]-arr[n-2]>2)
    {
        mnA=2;
    }
    else if(arr[n-1]-arr[1] == n-2 && arr[1]-arr[0] >2)
    {
        mnA=2;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            int j=0;
            while(j+1<n && arr[j+1]-arr[i] <n)
            {
                j++;
            }
           /// cout<<i<<" "<<j<<endl;
            mnA=min(mnA,n-(j-i+1));
            i=j;
        }
    }
    cout<<mnA<<endl;
    cout<<max(abs(arr[0]-arr[n-2]),abs(arr[1]-arr[n-1]))-(n-2)<<endl;
}