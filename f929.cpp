#include<iostream>
#include<set>
#include<queue>
#include<vector>
using namespace std;
class Sheng{
    set<int> si;
    public:
    Sheng(vector<int> &temp){
        int n=temp.size();
        for(int i=0;i<n;i++)
            if(!temp[i])
                si.insert(i);
    }
    void push(int x){
        if(!si.empty()&&x)
            si.erase(si.begin());
    }
    void erase(int x){
        si.insert(x);
    }
    int get(){
        return si.empty()?-1:*si.begin();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,cmd,x;
    while(cin>>n){
        vector<int> ivec(n);
        for(int i=0;i<n;i++)
            cin>>ivec[i];
        Sheng s(ivec);
        cin>>m;
        while(m--){
            cin>>cmd;
            if(cmd==1){
                cin>>x;
                s.push(x);
            }
            else if(cmd==2){
                cin>>x;
                s.erase(x);
            }
            else {
                cout<<s.get()<<"\n";
            }
        }
    }
}
