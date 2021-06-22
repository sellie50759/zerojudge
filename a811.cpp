#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 15
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--){//把每一個序列由小到大排序後，求兩個元素的差值之後取gcd即是答案
        cin>>n;
        vector<ll> lvec(n);
        for(int i=0;i<n;i++)
            cin>>lvec[i];
        sort(lvec.begin(),lvec.end());
        ll ans=lvec[1]-lvec[0];
        for(int i=1;i<n-1;i++)
            ans=__gcd(ans,lvec[i+1]-lvec[i]);
        cout<<ans<<"\n";
    }
}
