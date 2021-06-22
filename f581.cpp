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
#define MAX 15
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,temp,now=0;
    vector<int> ivec;
    vector<int>::iterator it;
    cin>>n>>m;
    ivec.push_back(0);
    while(n--){
        cin>>temp;
        ivec.push_back(ivec.back()+temp);
    }
    while(m--){//用前綴和去二分搜 複雜度O(m*logn)
        cin>>temp;
        it=lower_bound(ivec.begin()+now+1,ivec.end(),temp+ivec[now]);
        if(it==ivec.end())
            it=lower_bound(ivec.begin(),ivec.end(),temp-(ivec.back()-ivec[now]));
        now=it-ivec.begin();
    }
    cout<<now%(ivec.size()-1)<<"\n";
}
