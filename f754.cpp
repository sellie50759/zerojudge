#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 55
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
   int n,r=1;
   ll m,k;
   cin>>n;
   while(n--){
        cin>>m>>k;
        ll temp=m/k;
        cout<<"Case "<<r++<<" :\n";
        for(int i=1;i<k;i++)
            cout<<"第"<<i<<"位 : 拿"<<temp<<"元並說DD! BAD!\n";
        if(m%k==0)
            cout<<"第"<<k<<"位 : 拿"<<temp<<"元並說DD! BAD!\n";
        else cout<<"第"<<k<<"位 : 拿"<<m%k+temp<<"元並說DD! BAD!\n";
   }
}




