#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 55
bool notprime[10005]={1,1};
vector<int> prime;
void init(){
    for(int i=2;i<=10000;i++){
        if(!notprime[i]){
            prime.push_back(i);
            for(int j=2;i*j<=10000;j++)
                notprime[i*j]=true;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    int n,temp;
    cin>>n;
    while(n--){
        cin>>temp;
        int maxx=-1,ans;
        for(int i=0;i<prime.size()&&temp>=prime[i];i++){
            if(temp%prime[i]>maxx){
                maxx=temp%prime[i];
                ans=prime[i];
            }
        }
        cout<<ans<<"\n";
    }
}




