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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> ivec;
    vector<ll>::iterator it;
    ivec.push_back(1);
    for(int j=1;ivec.back()<=2147483647;j++)
        ivec.push_back(ivec.back()+2*j+1);
    ll l;
    while(cin>>l){
        it=upper_bound(ivec.begin(),ivec.end(),l);
        it--;
        if(*it==l){
            int num=it-ivec.begin();
            for(int i=1;i<=num+1;i++)
                cout<<i<<" ";
            for(int i=num;i>=1;i--)
                cout<<i<<" ";
            cout<<"\n";
        }
        else {
            int num=it-ivec.begin(),val=l-*it,temp=num+1;
            map<int,int> deletenum;
            while(val){
                if(val-temp>=0){
                    val-=temp;
                    deletenum[temp]++;
                }
                else temp--;
            }
            for(int i=1;i<=num+1;i++){
                cout<<i<<" ";
                while(deletenum.count(i)&&deletenum[i]){
                    cout<<i<<" ";
                    deletenum[i]--;
                }
            }
            for(int i=num;i>=1;i--)
                cout<<i<<" ";
            cout<<"\n";
        }
    }
}
/*
用greedy的想法，如果l剛好等於1+2+3+...+n+n-1+n-2+...+1的話，
1+2+3+...+n+n-1+n-2+...+1必定是最佳解，那如果不等於l的話，
最佳解就是去找一個最大的n使得1+2+3+...+n+n-1+n-2+...+1小於l，
除了這個之外，還要去加上l跟1+2+3+...+n+n-1+n-2+...+1之間的差值，
阿差值如果要讓步數最小的話，就只能從n開始插入新的數。
*/


