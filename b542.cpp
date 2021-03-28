#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define pi 3.14159
int main(){
    int n;
    double sum1,sum2,temp;
    while(cin>>n){
        sum1=0,sum2=0;
        while(n--){
            cin>>temp;
            temp/=2;
            sum1+=temp*temp*pi;
        }
        cin>>n;
        while(n--){
            cin>>temp;
            temp/=2;
            sum2+=temp*temp*pi;
        }
        //cout<<sum1<<" "<<sum2<<"\n";
        printf("%.2f\n",abs(sum1-sum2));
    }
}
