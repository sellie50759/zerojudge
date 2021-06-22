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
    int n,m;
    while(cin>>n>>m){
        int dp[MAX][MAX]={0};//dp[i][j] 第i次傳球後，球在第j個人手上的方法數
        dp[0][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j-1>=1?j-1:n]+dp[i-1][j+1<=n?j+1:1];
            }
        }
        cout<<dp[m][1]<<"\n";
    }
}
