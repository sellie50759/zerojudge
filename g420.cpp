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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        vector<int> die(n),reward(n);
        for(int i=0;i<n;i++){
            cin>>die[i];
        }
        for(int i=0;i<n;i++){
            cin>>reward[i];
        }
        for(int i=0;i<n;i++){
            if(m-die[i]<0){
                cout<<i+1<<"\n";
                break;
            }
            m+=reward[i]-die[i];
        }
    }
}
/*
根據題意直接模擬即可
*/



