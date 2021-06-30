#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 31
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k,m,cmd,n,i;
    while(cin>>k>>m){
        map<int,set<int> > hashtable;
        map<int,set<int> >::iterator it;
        set<int>::iterator ir;
        while(k--){
            cin>>cmd;
            if(cmd==1){
                cin>>n;
                if(hashtable.count(n%m))
                    hashtable[n%m].insert(n);
                else {
                    set<int> temp;
                    temp.insert(n);
                    hashtable[n%m]=temp;
                }
            }
            else if(cmd==2){
                cin>>n;
                if(hashtable.count(n%m)&&hashtable[n%m].count(n))
                    hashtable[n%m].erase(n);
            }
            else {
                cout<<"===== s =====\n";
                for(it=hashtable.begin(),i=0;i<m;i++){
                    if(i/10>=10)
                        cout<<"["<<i<<"]:";
                    else if(i/10>=1)
                        cout<<"[0"<<i<<"]:";
                    else cout<<"[00"<<i<<"]:";
                    if(it !=hashtable.end()&&it->first==i){
                        for(ir=it->second.begin();ir !=it->second.end();ir++)
                            cout<<*ir<<" -> ";
                        it++;
                    }
                    cout<<"NULL\n";
                }
                cout<<"===== e =====\n";
            }
        }
    }


}
/*
使用map搭配set來模擬hashtable
*/


