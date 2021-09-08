#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 1000005
#define INT_MAX 2147483647
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,temp;
    vector<int> ivec;
    map<int,int> mi;
    while(cin>>n){
        vector<ll> presum;
        int min=INT_MAX,mini=-1,left=0,right=n;
        while(n--){
            cin>>temp;
            ivec.push_back(temp);
        }
        presum.push_back(0);
        for(int i=0;i<ivec.size();i++){
            mi[ivec[i]]=i;
            presum.push_back(ivec[i]+presum.back());
        }
        mini=mi.begin()->second;
        while(right-left !=1){
            if(presum[mini]-presum[left]<=presum[right]-presum[mini+1])
                left=mini+1;
            else right=mini;
            while(mi.begin()->second<left||mi.begin()->second>=right)
                mi.erase(mi.begin());
            mini=mi.begin()->second;
        }
        cout<<ivec[left]<<"\n";
        ivec.clear();
        presum.clear();
        mi.clear();
    }
}
