/*James是個多才多藝的優秀青年，即將步入人生新階段的他，有許多不同的道路可以做選擇，恰好的是，最一開始的選擇都一定只有兩個選項，而每做完一個選擇之後，他就會面臨下一個選擇，他會不斷地做選擇，然後走下去。不過選擇不是無窮無盡的，最終，James會遇到兩種狀況，一是沒有新選擇了，二是人生只剩一個選擇，遇到前者James就會停下腳步，回顧他精彩的際遇，遇到後者時他會毫不猶豫選剩餘的那個選擇。

這種不斷做選擇的情況，可以用一個Binary Tree來表示，除此之外，本題的Binary Tree都是Complete Binary Tree，也就是這棵樹可以用一個陣列來表示，表示的方法可以參考https://imgur.com/a/A6r0goV，以下的講解也都是基於這張圖。

首先，James會站在樹根的位置，並擁有4單位的人生資產，此時他有兩個選擇，一是向左獲得另外9單位的資產，另一則是向右獲得8單位的資產，最終James只會在16、19、69、32、93、55其中一個葉節點停下腳步，他只要站在非葉節點，就會忍不住繼續做出選擇，往人生的下一個階段邁進。 

最後，我會給你一個整數T，我想請你幫James計算，他有幾條人生道路（從樹根到樹葉，且不走重複的點）上的人生資產總和大於等於T。

舉例來說，4到69這條人生道路的人生資產總和是4+9+17+69=99。
範例輸入 #1
8 
1 4 2 4 5 6 7 8
10
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
#define MAX 1000005
int tree[MAX],ans,t,n;
void dfs(int now,int sum){//應該有可以剪枝的方法，不過這題暴力做就過了
    if(now<n){
        sum+=tree[now];
        if(now*2+1>=n&&sum>=t)
            ans++;
        dfs(now*2+1,sum);
        dfs(now*2+2,sum);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int sum;
    cin>>n;
    sum=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>tree[i];
        sum+=tree[i];
    }
    cin>>t;
    if(sum<t)
        cout<<"0\n";
    else {
        dfs(0,0);
        cout<<ans<<"\n";
    }
}
