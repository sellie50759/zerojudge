#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD=1e8+7;
#define MAX 10005
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    while(cin>>n>>k){
        vector<int> ivec(n),temp(k);
        int maxx=-1;
        for(int i=0;i<n;i++){
            cin>>ivec[i];
            maxx=max(maxx,ivec[i]);
        }
        if(k>=n){
            cout<<maxx<<"\n";
        }
        else {
            priority_queue<int,vector<int>,greater<int> > pq;
            int ans=0;
            maxx=-1;
            for(int i=0;i<k;i++)
                pq.push(ivec[i]);
            for(int i=k;i<n;){
                int val=pq.top();
                ans+=val;
                int j=0;
                while(!pq.empty()){
                    temp[j++]=pq.top()-val;
                    pq.pop();
                }
                for(j=0;j<k;j++){
                    if(temp[j])
                        pq.push(temp[j]);
                }
                while(i<n&&pq.size()<k)
                    pq.push(ivec[i++]);
            }
            while(!pq.empty()){
                maxx=max(maxx,pq.top());
                pq.pop();
            }
            ans+=maxx;
            cout<<ans<<"\n";
        }
    }
}
/*
就單純照著題意做即可，原本以為n,k<=10^6會tle，一直在想有沒有更好的方法，
後來直接做就過了。
*/





