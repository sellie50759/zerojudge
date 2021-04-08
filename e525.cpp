#include <iostream>
#include <string>
#include <set>
#include<vector>
#include <map>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 10000000
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool ispalindrome(string &s){
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i] !=s[j])
            return false;
    }
    return true;
}
string itos(int n){
    string ans;
    while(n){
        ans+='0'+n%10;
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int stoi(string &s){
    int sum=0;
    for(int i=s.size()-1,j=1;i>=0;i--,j*=10)
        sum+=(s[i]-'0')*j;
    return sum;
}
int main()
{
    int n;
    string s;
    cin>>n;
    while(n--){
        vector<string> palindrome;
        cin>>s;
        int year=stoi(s);
        if(year%4==0&&year%100 !=0||year%400==0)
            days[1]++;
        for(int i=0;i<12;i++){
            string temp;
            if(i<9){
                temp+=i+1+'0';
                for(int j=1;j<=days[i];j++){
                    if(j<10){
                        string v1=s+temp,v2=s+temp;
                        v1+='0';
                        v1+='0'+j;
                        v2+='0'+j;
                        //cout<<v2<<"\n";
                        if(ispalindrome(v2))
                            palindrome.push_back(v2);
                        if(ispalindrome(v1))
                            palindrome.push_back(v1);
                    }
                    else {
                        string v1=s+temp+itos(j);
                        //cout<<v1<<"\n";
                        if(ispalindrome(v1))
                            palindrome.push_back(v1);
                    }
                }
                temp.insert(temp.begin(),'0');
                for(int j=1;j<=days[i];j++){
                    if(j<10){
                        string v1=s+temp,v2=s+temp;
                        v1+='0';
                        v1+='0'+j;
                        v2+='0'+j;
                        //cout<<v2<<"\n";
                        if(ispalindrome(v2))
                            palindrome.push_back(v2);
                        if(ispalindrome(v1))
                            palindrome.push_back(v1);
                    }
                    else {
                        string v1=s+temp+itos(j);
                        if(ispalindrome(v1))
                            palindrome.push_back(v1);
                    }
                }
            }
            else {
                temp+=itos(i+1);
                for(int j=1;j<=days[i];j++){
                    if(j<10){
                        string v1=s+temp,v2=s+temp;
                        v1+='0';
                        v1+='0'+j;
                        v2+='0'+j;
                        if(ispalindrome(v2))
                            palindrome.push_back(v2);
                        if(ispalindrome(v1))
                            palindrome.push_back(v1);
                    }
                    else {
                        string v1=s+temp+itos(j);
                        if(ispalindrome(v1))
                            palindrome.push_back(v1);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<palindrome.size();i++)
            ans.push_back(stoi(palindrome[i]));
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<" ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        if(year%4==0&&year%100 !=0||year%400==0)
            days[1]--;
    }
}




