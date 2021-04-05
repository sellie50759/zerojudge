#include <iostream>
#include <string>
#include <set>
#include<vector>
#include <map>
using namespace std;
typedef long long ll;
void print(set<int> &a){
    set<int>::iterator it;
    for(it=a.begin();it !=a.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
}
void del(set<int> &temp,set<int> &a){
    set<int>::iterator it;
    for(it=a.begin();it !=a.end();it++){
        if(temp.count(*it))
            temp.erase(*it);
    }
}
int main(){
    map<int,set<int> > around;
    set<int>::iterator it;
    around[1]={2,4};
    around[2]={1,3,5};
    around[3]={2,6};
    around[4]={1,5,7};
    around[5]={2,4,6,8};
    around[6]={3,5,9};
    around[7]={4,8};
    around[8]={5,7,9};
    around[9]={6,8};
   int t,n,a,b;
   cin>>t;
   while(t--){
        cin>>n>>a>>b;
        set<int> temp=around[n],sa=around[a],sb=around[b];
        del(temp,sa);
        if(temp.count(a))
            temp.erase(a);
        del(temp,sb);
        if(temp.count(b))
            temp.erase(b);
        if(temp.size()>0)
            print(temp);
        else cout<<"Empty\n";
   }

}












