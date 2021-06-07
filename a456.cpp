#include<iostream>
#include<cmath>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> pick;
int n;
void dfs(int now,int slot){
    if(now==n){
        cout<<"{";
        for(int i=0;i<pick.size()-1;i++)
            cout<<pick[i]<<",";
        cout<<pick.back()<<"}\n";
        return ;
    }
    if(slot){
        pick.push_back(now+1);
        dfs(now+1,slot-1);
        pick.pop_back();
    }
    if(n-now>slot)
        dfs(now+1,slot);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<"{0}\n";
        for(int i=1;i<=n;i++)
            dfs(0,i);
    }
}

