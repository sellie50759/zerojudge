#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
int main(){
    int n,m,temp;
    while(cin>>n>>m){
        int sum1=0,sum2=0;
        bool sign=false;
        if(n<=m){
            cout<<"No\n";
            sign=true;
        }
        while(n--){
            cin>>temp;
            sum1+=temp;
        }
        while(m--){
            cin>>temp;
            sum2+=temp;
        }
        if(sign==false){
            if(sum1<=sum2)
                cout<<"No\n";
            else cout<<"Yes\n";
        }
    }
}




