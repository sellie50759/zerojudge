#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    vector<ll> seq;
    ll n,m;
    seq.push_back(0);
    seq.push_back(1);
    seq.push_back(2);
    for(int i=2;seq.back()<=1e18;i++)
        seq.push_back(seq[i]+seq[i-1]+seq[i-2]);
    while(cin>>n>>m){
        cout<<upper_bound(seq.begin(),seq.end(),m)-lower_bound(seq.begin(),seq.end(),n)<<"\n";
    }
}
