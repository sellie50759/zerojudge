#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 55
int main()
{
    ll dp[10005]={0};
    dp[0]=1;
    dp[1]=0;
    int n;
    vector<int> coin;
    for(int i=1;i<=21;i++)
        coin.push_back(i*i*i);
    for(int i=0;i<21;i++){
        for(int j=coin[i];j<=10000;j++){
            dp[j]+=dp[j-coin[i]];
        }
    }
    while(cin>>n)
        cout<<dp[n]<<"\n";
}




