#include <iostream>
#include <string>
#include <set>
#include<vector>
using namespace std;
typedef long long ll;
bool notprime[130000]={1,1};
void init(){
    for(int i=2;i<130000;i++){
        if(!notprime[i]){
            for(int j=2;i*j<130000;j++){
                notprime[i*j]=true;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,ans;
    init();
    while(cin>>n){
        ans=0;
        for(int i=3;i<=n-2;i+=2){
            if(notprime[i]==false&&notprime[i+2]==false)
                ans++;
            else if(notprime[i+2])
                i+=2;
        }
        cout<<ans<<"\n";
    }
}




