#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD=1e8+7;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    while(cin>>s){
        pair<int,int> sum={0,0};
        stack<pair<int,int> > sp;
        for(int i=s.size()-1;i>=0;i--){
            pair<int,int> temp={0,0};
            if(s[i] !='F'){
                while(i>=0&&s[i] !='F'){
                    if(i>=0&&s[i]=='A')
                        temp.second++,i--;
                    temp.first++;
                    i--;
                }
                sum.first+=temp.first,sum.second+=temp.second;
            }
            sp.push(sum);
        }
        while(!sp.empty()){
            cout<<sp.top().first<<" "<<sp.top().second<<"\n";
            sp.pop();
        }
    }
}
/*
從後算回前再反轉結果即可
*/


