#include<iostream>
#include<map>
using namespace std;
#define MAX 100005
int nodes[MAX];
int findRoot(int x){
    if(nodes[x] !=x)
        return nodes[x]=findRoot(nodes[x]);
    else return x;
}
int dsuUnion(int x,int y){
    nodes[findRoot(x)]=findRoot(y);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,a,b;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            nodes[i]=i;
        int ans=0;
        while(m--){
            cin>>a>>b;
            if(findRoot(a)==findRoot(b))
                ans++;
            else dsuUnion(a,b);
        }
        cout<<ans<<"\n";
    }
}
/*
藉由tag與觀察法得到只要輸入的兩個人處在同一個dsu集合內，他就會吃不到冰棒。
*/
