#include<iostream>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
    ll a;
    int ans=2147483647;
    cin>>a;
    for(int i=a+1;i<=a*2;i++){
        if((1+i*a)%(i-a)==0&&i+(1+i*a)/(i-a)<ans)
            ans=i+(1+i*a)/(i-a);
    }
    cout<<ans<<"\n";
    /*b介於[a+1,a*2]
     由a=(bc-1)/(b+c)推出c=(1+ab)/(b-a)再窮舉
     */
}
