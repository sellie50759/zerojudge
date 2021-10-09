#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD=1e8+7;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,q,temp,cmd;
    cin>>t;
    while(t--){
        cin>>n>>q;
        map<vector<int>,bool> mv;
        map<vector<int>,bool>::iterator it;
        vector<int> weight;
        for(int i=0;i<n;i++){
            cin>>temp;
            weight.push_back(temp);
        }
        while(q--){
            cin>>cmd;
            if(cmd==1){
                vector<int> tv;
                for(int i=0;i<n;i++){
                    cin>>temp;
                    tv.push_back(temp);
                }
                if(mv.count(tv))
                    mv.erase(tv);
                else mv[tv]=true;
            }
            else {
                vector<int> start,end;
                for(int i=0;i<n;i++){
                    cin>>temp;
                    start.push_back(temp);
                }
                for(int i=0;i<n;i++){
                    cin>>temp;
                    end.push_back(temp);
                }
                int ans=0;
                for(it=mv.begin();it !=mv.end();it++){
                    bool error=false;
                    for(int i=0;i<n;i++){
                        if(it->first[i]<start[i]||it->first[i]>end[i]){
                            error=true;
                            break;
                        }
                    }
                    if(error==false)
                        ans++;
                }
                cout<<ans<<"\n";
            }
        }
    }
}
