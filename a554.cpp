#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 100005
string itos(unsigned int val){
    string ans;
    while(val){
        if(val%16>=10)
            ans+=val%16-10+'a';
        else ans+=(val%16+'0');
        val/=16;
    }
    ans+="x0";
    reverse(ans.begin(),ans.end());
    return ans;
}
unsigned int stoi(string &s){
    unsigned int ans=0;
    for(int i=s.size()-1,j=1;i>=0;i--,j*=16){
        if(isdigit(s[i]))
            ans+=(s[i]-'0')*j;
        else ans+=(s[i]-'a'+10)*j;
    }
    return ans;
}
vector<string> SHA4(string s){
    vector<string> ans;
    unsigned int h0=0xdead,h1=0xcafe,h2=0xbeef,h3=0x3399,h4=0x7788;
    unsigned int a=h0,b=h1,c=h2,d=h3,e=h4;
    for(int i=0;i<5;i++){
        char p=s[i]-' ';
        unsigned int f=b+c,k=0x5a82;
        unsigned int temp=4*a+f+e+k+p;
        e=d;
        d=c;
        c=8*b;
        b=a;
        a=temp;
        cout<<hex<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
    }
    //cout<<"*\n";
    h0+=a,h1+=b,h2+=c,h3+=d,h4+=e;
    ans.push_back(itos(h0));
    ans.push_back(itos(h1));
    ans.push_back(itos(h2));
    ans.push_back(itos(h3));
    ans.push_back(itos(h4));
    return ans;
}
string antiSHA4(vector<string> &svec){
    string ans;
    unsigned int a=0xdead,b=0xcafe,c=0xbeef,d=0x3399,e=0x7788;
    unsigned int temp[5]={(stoi(svec[4])-0x7788)/8,(stoi(svec[3])-0x3399)/8,(stoi(svec[2])-0xbeef)/8,(stoi(svec[1])-0xcafe),stoi(svec[0])-0xdead};
    //由最後的a,b,c,d,e推出每層的temp的值，就可以從每層temp的值推原本的字串了
    for(int i=0;i<5;i++){
        unsigned int k=0x5a82;
        char p=temp[i]-4*a-b-c-k-e+' ';
        ans+=p;
        e=d;
        d=c;
        c=8*b;
        b=a;
        a=temp[i];
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    while(n--){
        vector<string> svec(5);
        for(int i=0;i<5;i++)
            cin>>svec[i];
        cout<<antiSHA4(svec)<<"\n";
    }
}

