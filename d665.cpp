#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 1000005
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,temp,ans=0;
    cin>>n;
    vector<int> ivec;
    ivec.reserve(MAX);
    while(n--){
        cin>>temp;
        ivec.push_back(temp);
    }
    for(int i=0;i<ivec.size()-1;i++)
        ans+=max(ivec[i],ivec[i+1]);
    cout<<ans<<"\n";
}
