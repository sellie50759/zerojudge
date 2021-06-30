#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 31
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,i;
    while(cin>>n>>k){
        vector<int> ivec(n),maxnumber;
        map<int,int> slidewindow;
        for(i=0;i<n;i++)
            cin>>ivec[i];
        if(k>=n){
            int maxx=ivec[0],minn=ivec[0];
            for(int i=1;i<n;i++)
                maxx=max(ivec[i],maxx),minn=min(ivec[i],minn);
            cout<<minn<<"\n";
            cout<<maxx<<"\n";
        }
        else {
        for(i=0;i<k;i++)
            slidewindow[ivec[i]]++;
        cout<<slidewindow.begin()->first<<" ";
        maxnumber.push_back((--slidewindow.end())->first);
        for(i=k;i<n-1;i++){
            slidewindow[ivec[i]]++;
            if(--slidewindow[ivec[i-k]]==0)
                slidewindow.erase(ivec[i-k]);
            cout<<slidewindow.begin()->first<<" ";
            maxnumber.push_back((--slidewindow.end())->first);
        }
        slidewindow[ivec.back()]++;
        if(--slidewindow[ivec[i-k]]==0)
            slidewindow.erase(ivec[i-k]);
        cout<<slidewindow.begin()->first<<"\n";
        maxnumber.push_back((--slidewindow.end())->first);
        for(int i=0;i<maxnumber.size()-1;i++)
            cout<<maxnumber[i]<<" ";
        cout<<maxnumber.back()<<"\n";
        }
    }


}
/*
這題我當初有想過可以當成一道題目出，不過沒想到已經有了。
解法就是用map把sliding window裡的值都存起來，因為map會自動幫你排序key，所以map.begin()跟--map.end()就是最小值與最大值
之後只要加入下一個元素跟刪除sliding window最前面的元素就完成移動了。
不過這題的測資有 k>n 的情況，要額外判斷。
*/

