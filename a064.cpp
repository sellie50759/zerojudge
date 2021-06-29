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
    int n;
    bool sign=false;
    while(cin>>n){
        if(sign)
            cout<<"\n";
        sign=true;
        map<ll,ll> left;
        vector<ll> ivec(n);
        ll ans=0;
        for(int i=0;i<n;i++)
            cin>>ivec[i];
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                for(int c=0;c<n;c++){
                    left[ivec[a]*ivec[b]+ivec[c]]++;
                }
            }
        }
        for(int d=0;d<n;d++){
            for(int e=0;e<n;e++){
                for(int f=0;f<n;f++){
                    int val=ivec[d]*(ivec[e]+ivec[f]);
                    if(left.count(val)&&ivec[d])
                        ans+=left[val];
                }
            }
        }
        cout<<ans<<"\n";
    }


}
/*
把等式寫成a*b+c=d*(e+f)
這樣就可以先窮舉左邊的值，再算右邊的值有沒有等於左邊的值，如果等於的話答案就加上左邊的值出現的次數。
還有一點要注意，要額外判斷d的值有沒有等於0，等於0的話也不符合題目要求
*/
