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
vector<vector<long double> > matrixmul(vector<vector<long double> > &a,vector<vector<long double> > &b){
    vector<vector<long double> > ans(a.size(),vector<long double>(b[0].size()));
    if(!a.empty()&&!b.empty()&&!b[0].empty()&&a[0].size()==b.size()){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                for(int k=0;k<b[0].size();k++){
                    ans[i][k]+=a[i][j]*b[j][k];
                }
            }
        }
    }
    else {
        cout<<"error\n";
    }
    return ans;
}
int main() {
    ull t;
    long double a,b;
    while(cin>>t>>a>>b){//比照費式數列的矩陣快速冪寫出這題的狀態轉移矩陣。另外要提醒的是double不夠精準，long double才能達到題目所要的精度
        vector<vector<long double> > ans={{0},{1}};
        vector<vector<long double> > base={{1-b,a},{b,1-a}};
        while(t){
            if(t%2==1)
                ans=matrixmul(base,ans);
            base=matrixmul(base,base);
            t/=2;
        }
        cout<<fixed<<setprecision(2)<<ans[1][0]<<"\n";
    }

}
/*
狀態轉移方程式
[1-b,a] * [前一次失敗的機率] = [這次失敗的機率]
[b,1-a]   [前一次成功的機率]   [這次成功的機率]
得出以上方程式之後，用矩陣快速冪去算即可
*/
