#include<bits/stdc++.h>
using namespace std;
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}


int main()
{
    setIO("teamwork");
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
    vector<long long> dp(n+1);
    for(int i=0;i<n;i++)
    {
         long long val=arr[i];
        for(int j=0;j<k;j++)
        {
            if(i-j>=0)
            {
               
                val=max(val,arr[i-j]);
             //   cout<<i-j<<" "<<i<<" "<<val<<" "<<val*(j+1)<<endl;
                if(i-j-1>=0)
                    dp[i]=max(dp[i],val*(j+1)+dp[i-j-1]);
                else
                {
                    dp[i]=max(dp[i],val*(j+1));
                }
            }
        }
    }
    cout<<dp[n-1]<<endl;
}