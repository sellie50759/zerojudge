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
    int n,m;
    string s;
    while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        getline(cin,s);
        int arr[1000][128]={0};
        int r=n*m-1;
        while(r--){
            getline(cin,s);
            for(int i=0;i<s.size();i++)
                arr[i][s[i]]++;
        }
        string ans;
        for(int i=0;i<1000;i++){
            for(int j=0;j<128;j++){
                if(arr[i][j]%m){
                   ans+=char(j);
                   break;
                }
            }
        }
        cout<<ans<<"\n";
    }

}
/*
參照inversion的寫法 https://home.gamer.com.tw/creationDetail.php?sn=4834322
*/
