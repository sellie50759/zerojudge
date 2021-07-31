#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 50001
vector<int> ivec;
int findrt(int x){
    if(x==ivec[x])
        return x;
    else return ivec[x]=findrt(ivec[x]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
   int n,m,q,a,b;
   while(cin>>n>>m>>q){
        ivec.resize(n+1);
        for(int i=1;i<=n;i++)
            ivec[i]=i;
        while(m--){
            cin>>a>>b;
            if(findrt(a) !=findrt(b))
                ivec[findrt(b)]=findrt(a);
        }
        while(q--){
            cin>>a>>b;
            if(findrt(a)==findrt(b))
                cout<<":)\n";
            else cout<<":(\n";
        }

   }
}
/*
參考並查集的wiki https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86
*/


