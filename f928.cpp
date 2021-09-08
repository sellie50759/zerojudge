#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 1005
vector<int> bomb;
int n;
void boom(int t){
    if(t>=0&&t<bomb.size()){
        int val=bomb[t];
        bomb[t]=0;
        if(val==2){
            boom(t-1);
            boom(t+1);
        }
        else if(val>=3){
            boom(t-val);
            boom(t+val);
            boom(t-2*val);
            boom(t+2*val);
        }
    }
}
int main() {
    int t;
    while(cin>>n){
        bomb.resize(n);
        for(int i=0;i<n;i++)
            cin>>bomb[i];
        cin>>t;
        boom(t);
        for(int i=0;i<n;i++)
            cout<<bomb[i]<<" ";
        cout<<"\n";
        bomb.clear();
    }
}
