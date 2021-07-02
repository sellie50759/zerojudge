#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1; // 设置b=0时的特殊解
        y = 0;
        return a;
    }
    ll ans = exgcd(b, a % b, x, y);
    ll t = x; // 将x2, y2换算成x1, y1
    x = y;
    y = t - a / b * y;
    return ans;
}
ll invele(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    if(m < 0) m = -m;
    ll ans = x % m;
    if(ans <= 0) ans += m;
    return ans;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ull x,n;
    while(cin>>x>>n){
        if(x==0&&n==0)
            break;
        if(x==1)
            cout<<(n+1)%MOD<<"\n";
        else {
        ull val=n+1,ans=1,base=x;
        while(val){
            if(val&1)
                ans=ans*base%MOD;
            base=base*base%MOD;
            val>>=1;
        }
        ans--;
        if(ans<0)
            ans=MOD-1;
        cout<<(ans*invele(x-1,MOD))%MOD<<"\n";
        }
    }


}
/*
公式=(x^(n+1)-1)/(x-1)
用快速冪求出x^(n+1)之後，再將答案減一，之後乘x-1的模反元素，就是答案了。
*
