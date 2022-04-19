#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define MOD 1000000007
vector<int> ivec;
int evaluate(int n){
    int ans=0;
    for(int i=0;i<ivec.size();i++){
        if(double(ivec[i])/n==ivec[i]/n)
            ans+=ivec[i]/n;
        else ans+=ivec[i]/n+1;
        if(n !=1)
            n--;
    }
    return ans;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,temp;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>temp;
            ivec.push_back(temp);
        }
        sort(ivec.begin(),ivec.end(),greater<int>());
        int l=1,r=1e6;
        while(l<r){
            int mid=(l+r)/2;
            if(evaluate(mid)<=mid)
                r=mid;
            else l=mid+1;
        }
        cout<<l<<"\n";
        ivec.clear();
    }
}
/*
做完所有檔案的時間可以寫成 sum = sigma i=0 to n-1 ceiling(Ai/(x-i)) n是A的大小 x是效率 Ai是陣列的第i項(0 indexed)
要使sum最小的話，Ai必須由大排到小。
我對x這個值binary search來找出最佳解，總共分兩種情況
1.sum>x
這個情況不符合題目對於解的限制，所以這個x一定不是最佳解，所以可以把這個x排除。=>l=mid+1
2.sum<=x
這個情況符合題目對於解的限制，可是不一定是題目的最佳解，因為最佳解需要越小越好，
可是其本身也有可能是最佳解，所以不能被忽略。=>r=mid
*/
