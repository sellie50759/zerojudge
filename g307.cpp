#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 100000
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,t,temp;
    while(cin>>n>>k>>t){
        vector<int> ans;
        for(int i=0;i<n;i++){
            int maxx=-1,minn=2147483647,sum=0;
            for(int j=0;j<k;j++){
                cin>>temp;
                maxx=max(maxx,temp);
                minn=min(minn,temp);
                sum+=temp;
            }
            sum-=maxx+minn;
            if(sum>=t*(k-2))
                ans.push_back(i);
        }
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<"\n";
        if(ans.empty())
            cout<<"A is for apple.\n";
        ans.clear();
    }
}
