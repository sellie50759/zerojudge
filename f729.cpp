#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t,a,mb;
    string b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        mb=0;
        for(ll i=b.size()-1,j=1;i>=0;i--,j<<=3,j%=MOD-1)//by 費馬小定理 
            mb+=((b[i]-'0')*j)%(MOD-1);
        ll base=a,ans=1;
        while(mb){
            if(mb&1){
                ans*=base;
                ans%=MOD;
            }
            base=base*base%MOD;
            mb>>=1;
        }
        cout<<ans<<"\n";
    }
}




