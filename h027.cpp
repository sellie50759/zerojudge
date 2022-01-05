#include <cmath>
#include<vector>
#include<iostream>
#include <cstdint>
#include<map>
#include <unordered_map>
using namespace std;
class Matrix{
    public:
        vector<vector<int> > m;
        Matrix(int rowLength,int colLength):m(rowLength,vector<int>(colLength)){};

};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int s,t,n,m,r;
    while(cin>>s>>t>>n>>m>>r){
        Matrix a(s,t),b(n,m);
        int asum=0;
        for(int i=0;i<s;i++){
            for(int j=0;j<t;j++){
                cin>>a.m[i][j];
                asum+=a.m[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>b.m[i][j];
            }
        }
        int rlimit=n-s+1,climit=m-t+1,cnt=0,ans=2147483647;
        for(int i=0;i<rlimit;i++){
            for(int j=0;j<climit;j++){
                int val=0;
                for(int k=0;k<s;k++){
                    for(int p=0;p<t;p++){
                        if(a.m[k][p] !=b.m[i+k][j+p])
                            val++;
                    }
                }
                if(val<=r){
                    cnt++;
                    int bsum=0;
                    for(int k=0;k<s;k++){
                        for(int p=0;p<t;p++){
                            bsum+=b.m[i+k][j+p];
                        }
                    }
                    ans=min(ans,abs(asum-bsum));
                }
            }
        }
        cout<<cnt<<"\n";
        if(cnt==0)
            cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }

}
/*
因為數值很小，所以直接窮舉所有子矩陣，然後計算相對應的結果
暴力解時間複雜度O(n*m*s*t)
*/







