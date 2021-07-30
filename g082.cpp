#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 50001
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,a,b;
    while(cin>>n>>m){
        bool section[MAX]={false};
        vector<pair<int,int> > cmd;
        bool error=false;
        while(m--){
            cin>>a>>b;
            if(section[a])
                error=true;
            section[a]=true;
            cmd.push_back({a,b});
        }
        if(error)
            cout<<"Yes\n";
        else {
        bool ismove=true;
        while(ismove){
            ismove=false;
            for(int i=0;i<cmd.size();i++){
                if(section[cmd[i].second]==false){
                    section[cmd[i].first]=false;
                    section[cmd[i].second]=true;
                    cmd.erase(cmd.begin()+i);
                    ismove=true;
                }
                else if(cmd[i].first==cmd[i].second){
                    cmd.erase(cmd.begin()+i);
                    ismove=true;
                }
            }
        }
        if(cmd.empty())
            cout<<"No\n";
        else cout<<"Yes\n";
        }
    }
}
