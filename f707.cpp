#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
bool comp(int a,int b){
    if(a%7==0&&b%7==0)
        return a%70>b%70;
    else if(a%7==0)
        return true;
    else if(b%7==0)
        return false;
    else return a%77<b%77;
}
int main(){
    int n,maxx=100001;
    while(cin>>n){
        if(n==0)
            break;
        if(comp(n,maxx))
            maxx=n;
    }
    cout<<maxx<<"\n";
}








