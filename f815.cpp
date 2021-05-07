#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
ll eval(ll c,vector<int> &nums){
    ll ans=0;
    for(int i=0;i<nums.size();i++)
        ans+=nums[i]<c?(c-nums[i])*(c-nums[i]):0;
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll c;
    int n,temp;
    while(cin>>n>>c){
        vector<int> ivec(n);
        for(int i=0;i<n;i++)
            cin>>ivec[i];
        int left=0,right=2e7+1,count=right-left,it,step;
        while(count>0){
            it=left;
            step=count/2;
            it+=step;
            if(!(c<eval(it,ivec))){
                left=++it;
                count-=step+1;
            }
            else count=step;
        }
        left--;
        cout<<left<<"\n";
    }
}
