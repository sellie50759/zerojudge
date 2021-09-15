#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 100000
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,t,temp;
    bool b;
    while(cin>>n>>t){
        vector<int> ivec;
        vector<bool> sweet;
        for(int i=0;i<n;i++){
            cin>>temp;
            ivec.push_back(temp);
        }
        for(int i=0;i<n;i++){
            cin>>b;
            sweet.push_back(b);
        }
        int ans=0,val;
        while(ivec[t] !=-1){
            if(sweet[t])
                ans++;
            val=ivec[t];
            ivec[t]=-1;
            t=val;
        }
        cout<<ans<<"\n";
    }
}
