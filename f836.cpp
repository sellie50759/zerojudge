#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,temp;
    while(cin>>n){
        vector<int> ivec(n);
        for(int i=0;i<n;i++)
            cin>>ivec[i];
        sort(ivec.begin(),ivec.end());
        ll ans=1;//ans是目前可湊齊0到ans-1塊，只要任意值k大於ans代表ans塊一定湊不到，假設k小於等於ans的話，代表可用k來取代ans中的值，所以ans+k-1的所有值都可湊到
        for(int i=0;i<ivec.size();i++){
            if(ivec[i]>ans)
                break;
            else {
                ans+=ivec[i];
            }
        }
        cout<<ans<<"\n";
    }

}



