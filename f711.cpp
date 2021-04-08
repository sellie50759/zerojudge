#include <iostream>
#include <string>
#include <set>
#include<vector>
#include <map>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 10000000
bool notprime[MAX]={1,1};
int prime[MAX],primeidx=0;
set<int> si;
string s;
void init(){
    for(int i=2;i<MAX;i++){
        if(!notprime[i]){
            prime[primeidx++]=i;
            for(int j=2;i*j<MAX;j++)
                notprime[i*j]=true;
        }
    }
}
inline int stoi(string &s){
    int ans=0;
    for(int i=s.size()-1,j=1;i>=0;i--,j*=10)
        ans+=(s[i]-'0')*j;
    return ans;
}
void pick(int idx,int k,string now){
    if(k==0){
        int temp;
        string origin=now;
        next_permutation(now.begin(),now.end());
        while(now !=origin){
            temp=stoi(now);
            if(binary_search(prime,prime+primeidx,temp))
                si.insert(temp);
            next_permutation(now.begin(),now.end());
        }
        temp=stoi(origin);
        if(binary_search(prime,prime+primeidx,temp))
            si.insert(temp);
        return ;
    }
    for(int i=idx;i<s.size();i++)
        pick(i+1,k-1,now+s[i]);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
   int t;
   cin>>t;
   while(t--){
        cin>>s;
        for(int i=1;i<=s.size();i++)
            pick(0,i,"");
        cout<<si.size()<<"\n";
        si.clear();
   }
}




