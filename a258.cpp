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
#define MAX 31
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t,m,a,b;
    cin>>t;
    while(t--){
        cin>>m>>a>>b;
        if(__gcd(a,m) !=1)
            cout<<"No inverse, gcd(a,m)="<<__gcd(a,m)<<"\n";
        else {
            ll c;
            for(int i=1;i<m;i++){//用暴力求模反元素
                if((i*a)%m==1){
                    c=i;
                    break;
                }
            }
            ll d=-b*c;
            d+=(abs(d/m)+1)*m;
            d%=m;
            cout<<c<<" "<<d<<"\n";
        }
    }

}
/*
把1式合併到2式
=> x ≡ cax + bc +d mod m
代表這兩種情況必定成立
1.c是a的模反元素
2.d ≡ -bc mod m
之後就是用暴力法求模反元素C(較好的方法是用擴展歐基里得算法)
有了c之後就可求d
*/
