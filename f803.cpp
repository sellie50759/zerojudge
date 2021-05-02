#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAX 10000000
bool notprime[MAX]={1,1};
vector<int> prime;
void init(int n){
    for(int i=2;i<n;i++){
        if(!notprime[i]){
            prime.push_back(i);
            for(int j=2*i;j<n;j+=i)
                notprime[j]=true;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,temp;
    cin>>n>>m;
    prime.reserve(665000);
    init(n);
    while(m--){
        cin>>temp;
        cout<<lower_bound(prime.begin(),prime.end(),temp)-prime.begin()+1<<"\n";
    }
}
