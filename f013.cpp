#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
#define MAX 31
typedef long long ll;
typedef vector<vector<ll> > matrix;
vector<vector<ll> > matrixmul(vector<vector<ll> > &a,vector<vector<ll> > &b){  //輸入是兩個矩陣a,b，功能是回傳a*b的結果
    vector<vector<ll> > ans(a.size(),vector<ll>(b[0].size()));
    if(!a.empty()&&!b.empty()&&!b[0].empty()&&a[0].size()==b.size()){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                for(int k=0;k<b[0].size();k++){
                    ans[i][k]+=a[i][j]*b[j][k];
                    ans[i][k]%=MOD;
                }
            }
        }
    }
    else {
        cout<<"error\n";
    }
    return ans;
}
ostream& operator<<(ostream &out,matrix lval){
    int n=lval.size(),m=lval[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            out<<lval[i][j]<<" ";
        }
        out<<"\n";
    }
    return out;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<matrix> basis(MAX);
    vector<vector<ll> > table(MAX);
    for(int i=2;i<MAX;i++){
        vector<ll> temp(1);
        for(int j=0;j<i;j++)
            temp.push_back(1);
        ll sum=i;
        while(temp.size() !=5001){
            temp.push_back(sum);
            sum=((2*sum-temp[temp.size()-i-1])%MOD+MOD)%MOD;
        }
        table[i]=temp;
    }

    for(int i=2;i<MAX;i++){
        matrix temp;
        temp.push_back(vector<ll>(i,1));
        for(int j=0;j<i-1;j++){
            vector<ll> lvec(i);
            lvec[j]=1;
            temp.push_back(lvec);
        }
        basis[i]=temp;
    }


    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k<=5000)
            cout<<table[n][k]<<"\n";
        else {
            k-=n;
            matrix mat=basis[n],ans(n,vector<ll>(1,1));
            while(k){
                if(k&1)
                    ans=matrixmul(mat,ans);
                mat=matrixmul(mat,mat);
                k>>=1;
            }
            cout<<ans[0][0]<<"\n";
        }
    }
}
/*
每個費式數列的前5000項使用建表法
超過的部分使用矩陣快速冪來求出
*/
