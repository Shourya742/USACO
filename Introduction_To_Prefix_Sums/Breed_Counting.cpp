#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<vector<long long>> arr(n+1,vector<long long>(4));
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        arr[i][x]++;
        for(int j=0;j<=3;j++)
        {
            arr[i][j]+=arr[i-1][j];
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<arr[r][1]-arr[l-1][1]<<" "<<arr[r][2]-arr[l-1][2]<<" "<<arr[r][3]-arr[l-1][3]<<endl;
    }
}