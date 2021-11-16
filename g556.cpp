#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#define MAX 10005
const int mod=998244353;
vector<vector<ll> > matrixmul(vector<vector<ll> > &a,vector<vector<ll> > &b){  // 矩陣乘法
    vector<vector<ll> > ans(a.size(),vector<ll>(b[0].size()));
    if(!a.empty()&&!b.empty()&&!b[0].empty()&&a[0].size()==b.size()){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                for(int k=0;k<b[0].size();k++){
                    ans[i][k]+=a[i][j]*b[j][k];
                    ans[i][k]%=mod;
                }
            }
        }
    }
    else {
        cout<<"error\n";
    }
    return ans;
}
int fastmul(ll n){  // 矩陣快速冪
    vector<vector<ll> > trans={{1,1,1},{1,0,0},{0,0,1}},ans={{2},{1},{1}};
    while(n){
        if(n&1)
            ans=matrixmul(trans,ans);
        trans=matrixmul(trans,trans);
        n>>=1;
    }
    return ans[0][0];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)
            cout<<"1\n";
        else if(n==2)
            cout<<"2\n";
        else cout<<fastmul(n-2)<<"\n";
    }


}
/*
答案的遞迴公式f(n)=f(n-1)+f(n-2)+1
可以寫出轉移矩陣
[1,1,1]
[1,0,0]
[0,0,1]
初始矩陣
[2]
[1]
[1]
然後f(1)=1,f(2)=2，所以想要求f(3)就只要拿轉移矩陣跟初始矩陣做乘法就可得到，也就是
[1,1,1]   [2]   [4]
[1,0,0] * [1] = [2]
[0,0,1]   [1]   [1]
4就是f(3)
最後再用矩陣快速冪的原理即可將時間複雜度縮到logn
*/






