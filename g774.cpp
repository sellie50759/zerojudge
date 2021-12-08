#include<iostream>
#include<vector>
using namespace std;
#define MAX 2005
int dp[MAX][MAX];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        int cnt=n+m;
        vector<pair<int,int> > pvec(cnt);
        for(int i=0;i<cnt;i++)
            cin>>pvec[i].first>>pvec[i].second;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
            dp[i][0]=dp[i-1][0]+pvec[i-1].first;
        for(int j=1;j<=m;j++)
            dp[0][j]=dp[0][j-1]+pvec[j-1].second;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i-1][j]+pvec[i+j-1].first,dp[i][j-1]+pvec[i+j-1].second);
            }
        }
        cout<<dp[n][m]<<"\n";
    }
}
/*
用dp來解，令dp[i][j]為從前i+j個班級裡選出i個男生與j個女生的時間總和的最小值
得出dp[i][j]=min(dp[i-1][j]+第i+j個班級男生的跑步時間,dp[i][j-1]+第i+j個班級女生的跑步時間)
dp[n][m]即是題目所求。


另一種方式是greedy的作法，把每個班級男生時間減女生時間算出來之後排序，取前n小的班級當男生，
剩下的m個班級當女生，以下是實際的code

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 4005
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        vector<pair<int,int> > diff,pvec;
        int cnt=n+m,a,b,ans=0;
        for(int i=0;i<cnt;i++){
            cin>>a>>b;
            pvec.push_back(make_pair(a,b));
            diff.push_back(make_pair(a-b,i));
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<cnt;i++){
            int idx=diff[i].second;
            if(i<n)
                ans+=pvec[idx].first;
            else ans+=pvec[idx].second;
        }
        cout<<ans<<"\n";
    }
}
*/






