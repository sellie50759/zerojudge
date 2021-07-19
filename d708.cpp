#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define pi 3.14159
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll temp,ans=0;
    cin>>n;
    n--;
    int arr[1000][128]={0};
    while(n--){
        cin>>temp;
        ans^=temp;
    }
    cout<<ans<<"\n";

}
/*
參考解題報告的寫法 https://zerojudge.tw/ShowThread?postid=24263&reply=0

用下列d578的寫法執行效率會比較快
#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define pi 3.14159
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin>>n;
        n--;
        getline(cin,s);
        int arr[1000][128]={0};
        while(n--){
            getline(cin,s);
            for(int i=0;i<s.size();i++)
                arr[i][s[i]]++;
        }
        string ans;
        for(int i=0;i<1000;i++){
            for(int j=0;j<128;j++){
                if(arr[i][j]%2){
                   ans+=char(j);
                   break;
                }
            }
        }
        cout<<ans<<"\n";

}
*/
