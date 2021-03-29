#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    set<int> si;
    int n,cmd,temp,l,r;
    cin>>n;
    while(n--){
        cin>>cmd;
        if(cmd==1){
            cin>>temp;
            si.insert(temp);
        }
        else {
            cin>>l>>r;
            si.erase(si.lower_bound(l),si.upper_bound(r));
        }
        if(si.size()==0)
            cout<<"0\n";
        else if(si.size()==1)
            cout<<"1 "<<*si.begin()<<"\n";
        else cout<<"2 "<<*si.begin()<<" "<<*(--si.end())<<"\n";
    }
}








