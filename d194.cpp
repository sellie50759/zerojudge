#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,temp;
    set<int> si;
    vector<int> ivec;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>temp;
            ivec.push_back(temp);
        }
        int ans=0;
        for(int i=0;i<ivec.size();i++){
            if(si.count(ivec[i])){
                int j;
                si.clear();
                for(j=i-1;ivec[i] !=ivec[j];j--)
                    si.insert(ivec[j]);
                si.insert(ivec[i]);
            }
            else {
                si.insert(ivec[i]);
                if(ans<si.size())
                    ans=si.size();
            }
        }
        cout<<ans<<"\n";
        si.clear();
        ivec.clear();
    }
}








