#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
const int MOD=1e8+7;
#define MAX 10005
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        m<<=1;
        vector<int> ivec(n);
        int maxx=-1;
        for(int i=0;i<n;i++){
            cin>>ivec[i];
            maxx=max(maxx,ivec[i]);
        }
        int left=1,right=maxx;
        while(left<right){
            int mid=(left+right)/2;
            ll cnt=0;
            for(int i=0;i<n;i++)
                cnt+=ivec[i]/mid;
            if(cnt<m)
                right=mid-1;
            else {
                if(left==mid)
                    left=mid+1;
                else left=mid;
            }
        }
        cout<<left<<"\n";
    }

}







