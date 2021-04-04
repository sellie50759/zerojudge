#include <iostream>
#include <string>
#include <set>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    int ans=1,temp;
    vector<int> prime;
    prime.push_back(2);
    bool error=false;
    for(int i=3;prime.size() !=1005;i+=2){
        for(int j=0;j<prime.size();j++){
            if(i%prime[j]==0){
                error=true;
                break;
            }
        }
        if(error)
            error=false;
        else prime.push_back(i);
    }
    const int mod=76543;
    int now=0;
    while(cin>>temp){
        while(temp--){
            ans*=prime[now];
            ans%=mod;
        }
        now++;
    }
    cout<<ans<<"\n";
}














