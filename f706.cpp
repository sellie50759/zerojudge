#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
int main(){
    int h,m,s,t,minute;
    while(cin>>h>>m>>s>>t){
        minute=3600*h+60*m;
        minute+=t*5400;
        if(minute>129600)
            minute-=129600;
        else if(minute<0)
            minute+=129600;
        cout<<minute/3600<<":"<<((minute%3600)/60<10?"0":"")<<(minute%3600)/60<<":"<<(s<10?"0":"")<<s<<"\n";
    }
}
