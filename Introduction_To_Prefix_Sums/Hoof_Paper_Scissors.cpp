#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
    int n;
    cin>>n;
    vector<vector<int>> arr(n+2,vector<int>(26));
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        arr[i][c-'A']++;
        for(int j=0;j<26;j++)
        {
            arr[i][j]+=arr[i-1][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        for(int j=0;j<26;j++)
        {
            mx=max(mx,arr[i-1][j]);
        }
        int mx2=0;
        for(int j=0;j<26;j++)
        {
            mx2=max(mx2,arr[n][j]-arr[i-1][j]);
        }
        ans=max(ans,mx+mx2);
    }
    cout<<ans<<endl;
}