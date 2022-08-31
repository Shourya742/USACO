#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> pre(26,vector<int>(n+1,-1e9));
    for(int i=0;i<26;i++)
    {
        char c='a'+i;
        for(int j=0;j<n;j++)
        {
            int count=0;
            int len=0;
            for(int k=j;k<n;k++)
            {
                len++;
                if(s[k]!=c)
                {
                    count++;
                }
                pre[i][count]=max(pre[i][count],len);
                if(s[k] == c)
                {
                    continue;
                }
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pre[i][j]=max(pre[i][j],pre[i][j-1]);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int m;
        cin>>m;
        char c;
        cin>>c;
        int curr=c-'a';
        cout<<pre[curr][m]<<endl;
    }
}