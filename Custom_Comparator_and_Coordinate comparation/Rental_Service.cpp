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
    setIO("rental");
    long long n,m,R;
    cin>>n>>m>>R;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++)
    {
        arr[i]+=arr[i-1];
    }
    vector<pair<long long,long long>> milk(m);
    for(int i=0;i<m;i++)
    {
        cin>>milk[i].second>>milk[i].first;
        
    }
    sort(milk.rbegin(),milk.rend());
    for(int i=0;i<m;i++)
    {
        milk[i].first*=milk[i].second;
    }
    for(int i=1;i<m;i++)
    {
        milk[i].first+=milk[i-1].first;
        milk[i].second+=milk[i-1].second;
    }
    vector<long long> rent(R);
    for(int i=0;i<R;i++)
    {
        cin>>rent[i];
    }
    sort(rent.rbegin(),rent.rend());
    for(int i=1;i<R;i++)
    {
        rent[i]+=rent[i-1];
    }
    long long val=0;
    
    for(int len=0;len<=n;len++)
    {
        long long ans=0;
        long long idx=len-1;
        //cout<<idx<<endl;
        int l=0;
        int r=m-1;
        int curr=-1;
        long long store=arr[n-1]-(len>0?arr[len-1]:0);
       // cout<<len<<" "<<store<<endl;
        while(l<=r)
        {
            int mid=(l+r)/2;
        
            if(milk[mid].second<=store)
            {
                curr=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(curr==-1)
        {
            if(idx>0)
            ans+=rent[min(R-1,idx)];
            val=max(ans,val);
            continue;
        }
        ans+=milk[curr].first;
        store-=milk[curr].second;
      
        if(curr+1<m)
        {
          
            ans+=store*((milk[curr+1].first-milk[curr].first)/(milk[curr+1].second-milk[curr].second));
        }
        
        if(idx>0 && idx<R)
        {
            ans+=rent[idx];
        }
        
        val=max(val,ans);
    }
    cout<<val<<endl;
    
}