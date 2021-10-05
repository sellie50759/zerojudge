#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD=1e8+7;
int fac[MOD];
ll modreverse(ll n){ //求模逆元，運用費馬小定理
    ll p=MOD-2;
    ll ans=1,val=n;
    while(p){
        if(p&1)
            ans=ans*val%MOD;
        val=val*val%MOD;
        p>>=1;
    }
    return ans;
}
ll c(ll n,ll m){
    if(n<m) //要加這行，因為n,m取模之後，n有機會小於m
        return 0;
    return fac[n]*modreverse(ll(fac[m])*fac[n-m]%MOD)%MOD;
}
ll Lucas(ll n, ll m){
         return m ? Lucas(n/MOD, m/MOD) * c(n%MOD, m%MOD) % MOD : 1;//结合上用逆元求组合数的代码
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    ll n,m;
    fac[0]=1;
    for(int i=1;i<MOD;i++)
        fac[i]=ll(fac[i-1])*i%MOD;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<<Lucas(n,m)<<"\n";
    }
}
/*
參考自這篇https://blog.nowcoder.net/n/a319954646a04960bd7b0ece43b4f3c6?from=nowcoder_improve
主要運用lucas定理和模逆元來快速求得c(n,m)%mod
*/
