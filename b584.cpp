#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 205
int n,m;
int main()
{
    int n,temp;
    while(cin>>n){
        if(n==0)
            break;
        vector<int> ivec;
        while(n--){
            cin>>temp;
            ivec.push_back(temp);
        }
        sort(ivec.begin(),ivec.end());
        if(ivec.size()==1||ivec.size()==2)
            cout<<ivec.back()<<"\n";
        else {
            int ans=0;
            while(ivec.size()>=4&&ivec[0]+ivec[ivec.size()-2]>2*ivec[1]){//在這個條件成立情況下最小跟次小的先過 最小回來 最大和次大再過 次小回來是最佳解
                ans+=ivec[0]+2*ivec[1]+ivec.back();
                ivec.pop_back();
                ivec.pop_back();
            }
            while(ivec.size()>2){//除此之外最大跟最小一起過 最小回來是最佳解
                ans+=ivec.back()+ivec[0];
                ivec.pop_back();
            }
            ans+=ivec[1];
            cout<<ans<<"\n";
        }
        ivec.clear();
    }
}
