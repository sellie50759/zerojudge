#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
#define MAX 35
int mypow(int x,int y){
    int ans=1;
    for(int i=0;i<y;i++){
        ans*=x;
        ans%=10000;
    }
    return ans;
}
int stoi(string &s){
    int ans=0;
    if(s.size()<=2){
        for(int i=s.size()-1,j=1;i>=0;i--,j*=10)
            ans+=(s[i]-'0')*j;
        return ans;
    }
    else {
        for(int i=s.size()-1,j=1;i>=s.size()-2;i--,j*=10)
            ans+=(s[i]-'0')*j;
        return ans;
    }
}
int main() {
    int sum=0;
    string s;
    vector<int> ivec;
    for(int i=1;i<=100;i++){
        sum+=mypow(i,i);
        sum%=10000;
        //cout<<sum%10<<"\n";
        ivec.push_back(sum%10);
    }
    while(cin>>s){
        if(s=="0")
            break;
        cout<<ivec[(stoi(s)-1)%20]<<"\n";
    }
}

