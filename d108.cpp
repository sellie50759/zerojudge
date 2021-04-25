#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 205
int digit[10]={6,2,5,5,4,5,6,3,7,6};
int trans(int n){
    if(n==0)
        return digit[0];
    int ans=0;
    while(n){
        ans+=digit[n%10];
        n/=10;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        n-=4;
        int ans=0;
        for(int i=0;i<=1000;i++){//1000可過n<=24的測資
            for(int j=0;j<=1000;j++){
                if(trans(i)+trans(j)+trans(i+j)==n)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
