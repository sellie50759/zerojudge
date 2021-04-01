#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll digitsum(ll n){
    ll sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> prime;
    bool error=false;
    prime.push_back(2);
    for(int i=3;i<100000;i+=2){
        for(int j=0;prime[j]<=sqrt(i);j++){
            if(i%prime[j]==0){
                error=true;
                break;
            }
        }
        if(error)
            error=false;
        else prime.push_back(i);
    }
    int t,temp;
    cin>>t;
    while(t--){
        cin>>temp;
        for(ll i=temp+1;;i++){
            ll sum1=digitsum(i),sum2=0;
            temp=i;
            for(int j=0;j<prime.size();j++){
                int digit=digitsum(prime[j]);
                while(temp%prime[j]==0){
                    sum2+=digit;
                    temp/=prime[j];
                }
                if(temp<prime[j])
                    break;
            }
            if(temp==i)
                continue;
            if(temp !=1)
                sum2+=digitsum(temp);
            if(sum1==sum2&&!binary_search(prime.begin(),prime.end(),i)){
                cout<<i<<"\n";
                break;
            }
        }
    }
}





