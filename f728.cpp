#include <iostream>
#include <string>
#include <set>
#include<vector>
#include <map>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
#define MAX 10000000
int main()
{
    int k;
    double p;
    while(cin>>k){
        if(k==0){
            cout<<2<<"\n";
            continue;
        }
        p=1-double(k)/100;
        int ans=1;
        double now=1;
        for(int i=364;now>p;i--,ans++)
            now*=i/365.0;
        cout<<ans<<"\n";
    }
}
