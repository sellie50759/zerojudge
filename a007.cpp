#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
typedef unsigned long long ull;
#define MAX 65536
int prime[MAX]={0},primecnt=0;
bool notprime[MAX]={true,true};
void init(){
    for(int i=2;i<MAX;i++){
        if(!notprime[i]){
            prime[primecnt++]=i;
            for(int j=2;i*j<MAX;j++){
                notprime[i*j]=true;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    int n;
    while(cin>>n){
        bool error=false;
        int r=lower_bound(prime,prime+primecnt,sqrt(n))-prime;
        for(int i=0;i<r;i++){
            if(n%prime[i]==0){
                error=true;
                break;
            }
        }
        if(error)
            cout<<"非質數\n";
        else cout<<"質數\n";
    }
}
