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
    int cnt[26]={0},q,temp;
    vector<int> ivec;
    string s,t;
    cin>>s;
    cin>>t;
    for(int i=0;i<t.size();i++)
        cnt[t[i]-'A']++;
    ivec.push_back(0);
    for(int i=0;i<s.size();i++)
        ivec.push_back(cnt[s[i]-'A']+ivec.back());
    cin>>q;
    while(q--){
        cin>>temp;
        cout<<s[lower_bound(ivec.begin(),ivec.end(),temp)-ivec.begin()-1]<<"\n";
    }
}
