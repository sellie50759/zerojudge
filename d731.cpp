#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 100000
bool comp(int &a,int &b){
    return abs(a)>abs(b);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> ivec;
    int t,n,temp;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>temp;
            ivec.push_back(temp);
        }
        sort(ivec.begin(),ivec.end(),comp);
        int ans1=0,ans2=0;//ans1 藍在底層 ans2 紅在底層
        bool need1=true,need2=false;//true為需要正數 false為需要負數
        for(int i=0;i<ivec.size();i++){
            if(ivec[i]>0){
                if(need1){
                    ans1++;
                    need1=!need1;
                }
                if(need2){
                    ans2++;
                    need2=!need2;
                }
            }
            else {
                if(!need1){
                    ans1++;
                    need1=!need1;
                }
                if(!need2){
                    ans2++;
                    need2=!need2;
                }
            }
        }
        cout<<max(ans1,ans2)<<"\n";
        ivec.clear();
    }
}





