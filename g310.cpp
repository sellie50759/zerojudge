#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 1000
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,temp;
    vector<int> x,y;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>temp;
            x.push_back(temp);
        }
        for(int i=0;i<n;i++){
            cin>>temp;
            y.push_back(temp);
        }
        int idx=0,ans=0;
        for(int i=0;i<n;i++){
            if(x[idx]<y[i]){
                idx++;
                ans++;
            }
        }
        cout<<ans<<"\n";
        x.clear();
        y.clear();
    }
}
