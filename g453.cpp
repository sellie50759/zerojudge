#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD=1e8+7;
#define MAX 205
int trans(string s){
    if(s.size()>10||s.size()==10&&s>"2147483647")
        return 0;
    return stoi(s);
}
int stoi(string &s){
    int ans=0;
    for(int i=s.size()-1,j=1;i>=0;i--,j*=10)
        ans+=(s[i]-'0')*j;
    return ans;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
   int n;
   cin>>n;
   while(n--){
     string s;
     cin>>s;
     int n=s.size();
     ll ans=0,dp[MAX];
     for(int i=0;i<n;i++){
        dp[i]=0;
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            ll val=trans(s.substr(j,i-j+1));
            if(j>=1)
                dp[i]=max(dp[i],dp[j-1]+val);
            else dp[i]=max(dp[i],val);
        }
     }
     cout<<dp[s.size()-1]<<"\n";
   }
}
