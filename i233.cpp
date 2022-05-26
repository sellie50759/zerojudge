#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
#define MAX 1005
typedef long long ll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,temp,q,l,r;
    while(cin>>n){
        ll sum=0;
        vector<ll> psum(1),ppsum(1);
        while(n--){
            cin>>temp;
            sum+=temp;
            psum.push_back(sum);
        }
        for(int i=1;i<psum.size();i++)
            ppsum.push_back(ppsum[i-1]+psum[i]);

        cin>>q;
        while(q--){
            cin>>l>>r;
            cout<<ppsum[r]-ppsum[l-1]-(r-l+1)*psum[l-1]<<"\n";
        }
    }
    return 0;
}

