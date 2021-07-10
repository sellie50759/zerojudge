#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define pi 3.14159
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q,temp;
    while(cin>>n>>q){
        vector<int> ivec(n);
        for(int i=0;i<n;i++)
            cin>>ivec[i];
        while(q--){
            cin>>temp;
            if(binary_search(ivec.begin(),ivec.end(),temp))
                cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

}



