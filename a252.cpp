#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
#define MAX 105
int LCS[MAX][MAX][MAX];
int main() {
    string s,t,r;
    while(cin>>s>>t>>r){
        for(int i=0;i<s.size();i++)
            LCS[i][0][0]=0;
        for(int i=0;i<t.size();i++)
            LCS[0][i][0]=0;
        for(int i=0;i<r.size();i++)
            LCS[0][0][i]=0;
        for(int i=1;i<=s.size();i++){//將二維改成三維的模式 跟c001是一樣的解法
            for(int j=1;j<=t.size();j++){
                for(int k=0;k<=r.size();k++){
                    if(s[i-1]==t[j-1]&&t[j-1]==r[k-1])
                        LCS[i][j][k]=LCS[i-1][j-1][k-1]+1;
                    else LCS[i][j][k]=max(max(LCS[i-1][j][k],LCS[i][j-1][k]),LCS[i][j][k-1]);
                }
            }
        }
        cout<<LCS[s.size()][t.size()][r.size()]<<"\n";
    }
}
