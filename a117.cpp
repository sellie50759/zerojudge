#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
ll eval(pair<ll,ll> &a,pair<ll,ll> &b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        vector<pair<ll,ll> > pvec(n);
        for(int i=0;i<n;i++)
            cin>>pvec[i].first>>pvec[i].second;
        if(n==1)
            cout<<"0\n";
        else {
            ll ans=eval(pvec[1],pvec[0]);
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ans=min(ans,eval(pvec[i],pvec[j]));
                }
            }
            cout<<ans<<"\n";
        }
    }
}



