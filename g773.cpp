#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#define MAX 20
const int mod=998244353;
bool relations[MAX][MAX];
int ans=0,n;
vector<int> group;
void dfs(int idx){
    for(int i=idx;i<n;i++){
        bool flag=false;
        for(int j=0;j<group.size();j++){
            if(relations[i][group[j]]==1){
                flag=true;
                break;
            }
        }
        if(flag==false){
            group.push_back(i);
            ans=max(ans,int(group.size()));
            dfs(i+1);
            group.pop_back();
        }
    }
}
int main() {
   cin>>n;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>relations[i][j];
    }
   }
   dfs(0);
    cout<<ans<<"\n";

}

/*
因為n很小，使用dfs窮舉所有可能即可
*/






