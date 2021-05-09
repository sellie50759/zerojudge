#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
typedef unsigned long long ull;
typedef vector<vector<__int128> > matrix;
/*
def MulMatrix(a, b, mod):
    matrix = [[0 for i in range(len(b[0]))] for j in range(2)]
    if len(b[0]) == 2:
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    matrix[i][k] += a[i][j] * b[j][k] % m
    else:
        for i in range(2):
            for j in range(2):
                for k in range(1):
                    matrix[i][k] += a[i][j] * b[j][k] % m
    return matrix
*/
matrix mulmatrix(matrix &a,matrix &b,__int128 mod){
    matrix c(2,vector<__int128>(b[0].size()));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<b[0].size();k++)
                c[i][k]+=a[i][j]*b[j][k]%mod;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<c[0].size();j++)
            c[i][j]%=mod;
    }
    return c;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ull n,m;
    //vector<vector<__int128> >
    while(cin>>n>>m){
        matrix base={{1,1},{1,0}},ans={{1},{1}};
        while(n){
            if(n&1)
                ans=mulmatrix(base,ans,m);
            base=mulmatrix(base,base,m);
            n>>=1;
        }
        cout<<ull(ans[1][0]%m)<<"\n";
    }
}
