#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#define MAX 10005
const int mod=998244353;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,temp;
    while(cin>>n>>m){
        vector<int> ivec(n);
        vector<int>::iterator it;
        for(int i=0;i<n;i++)
            cin>>ivec[i];
        sort(ivec.begin(),ivec.end());
        ll ans=0;
        while(m--){
            cin>>temp;
            it=lower_bound(ivec.begin(),ivec.end(),temp);
            if(it !=ivec.end())
                ans+=*it;
        }
        cout<<ans<<"\n";
    }


}
/*
1.每種壽司基本上可以視為無限量供應 -> 買過的不需要被刪除 -> 每個客人的購買都是獨立的
2.會以符合客人要求的壽司中品質最差的優先售出 -> 找剛好大於等於客人價格的那個壽司
由上述兩點，寫出的code如上
*/







