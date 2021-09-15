#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 1000
int node[MAX];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,a,l,r;
    while(cin>>n>>k){
        map<int,pair<int,int> > relation;
        for(int i=0;i<n;i++){
            cin>>a>>l>>r;
            relation[a]={l,r};
        }
        node[0]=k;
        for(int i=0;i<n;i++){
            int num=1;
            if(relation[i].first !=-1)
                num++;
            if(relation[i].second !=-1)
                num++;
            if(relation[i].first !=-1)
                node[relation[i].first]=node[i]/num;
            if(relation[i].second !=-1)
                node[relation[i].second]=node[i]/num;
            node[i]=node[i]/num+node[i]%num;
        }
        for(int i=0;i<n;i++)
            cout<<node[i]<<" ";
        cout<<"\n";
    }
}
