#include<iostream>
#include<set>
#include<queue>
#include<vector>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,temp,ans=0;
    set<int> si;
    set<int>::iterator it;
    cin>>n;
    n--;
    cin>>temp;
    ans+=temp;
    si.insert(temp);
    //cout<<*si.begin()<<"\n";
    while(n--){
        cin>>temp;
        it=si.lower_bound(temp);
        if(it==si.end())
            ans+=abs(*(--it)-temp);
        else if(it==si.begin()){
            ans+=abs(*it-temp);
            //cout<<"*\n";
        }
        else {
            int a=abs(*it-temp),b=abs(*(--it)-temp);
            ans+=min(a,b);
        }
        si.insert(temp);
    }
    cout<<ans<<"\n";
}
