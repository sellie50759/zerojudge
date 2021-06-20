#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
#define MAX 1005
int LCS[MAX][MAX];
int main() {
    string s,t;
    int l;
    while(cin>>s>>t){
        for(int i=0;i<s.size();i++)
            LCS[i][0]=0;
        for(int i=0;i<t.size();i++)
            LCS[0][i]=0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1])//遞迴式
                    LCS[i][j]=LCS[i-1][j-1]+1;
                else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
        cin>>l;
        if(LCS[s.size()][t.size()]>=l)
            cout<<"kwa nini unaendesha\n";
        else cout<<"sitini na tisa\n";
    }
}
