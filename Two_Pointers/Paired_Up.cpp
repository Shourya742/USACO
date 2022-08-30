#include<bits/stdc++.h>
using namespace std;
bool check(vector<long long>& arr,long long x)
{
    long long n=arr.size();
    multiset<long long> s;

    for(auto y: arr)
    {
        s.insert(y);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s.find(arr[i])!=s.end())
        {
            s.erase(s.find(arr[i]));
            auto it=s.upper_bound(x-arr[i]);
            if(it==s.begin()){
                return false;
            }
            it--;
            s.erase(it);
        }
        else
        {
            continue;
        }
    }
    return true;
}
int main()
{
    freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
    int n;
    cin>>n;
    vector<pair<long long,long long>> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr.begin(),arr.end());
    int l=0;
    int r=n-1;
    long long ans=0;
    while(l<=r)
    {
        ans=max(ans,arr[l].first+arr[r].first);
        int curr=min(arr[l].second,arr[r].second);
        if(l==r)
        {
            curr/=2;
        }
        arr[l].second-=curr;
        arr[r].second-=curr;
        if(arr[l].second==0 && arr[r].second==0)
        {
            l++;
            r--;
        }
        else if(arr[l].second==0)
            l++;
        else if(arr[r].second==0)
            r--;
    }
    cout<<ans<<endl;
}