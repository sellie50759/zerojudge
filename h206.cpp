#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
#include<fstream>
using namespace std;
typedef long long ll;
#define MAX 1005
vector<int> arr;
//order false 戰力低為強者
//      true  戰力高為強者
int divide(int l,int r,bool order){
    if(l==r)
        return arr[l];
    int mid=(l+r)/2;
    if(!order)
        return min(divide(l,mid,!order),divide(mid+1,r,!order));
    else return max(divide(l,mid,!order),divide(mid+1,r,!order));
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        arr.resize(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<divide(0,n-1,true)<<"\n";
    }

}





