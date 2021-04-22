#include <iostream>
#include <string>
#include <set>
#include<vector>
#include <map>
#include<stack>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 100000000
int m,matrix[10005];
int calculateMAX(){
    stack<pair<int,int> > sp;
    int ans=0;
    sp.push({-1,0});
    for(int j=0;j<m;j++){
        if(sp.top().first<matrix[j])
            sp.push({matrix[j],j});
        else {
            int tempj;
            while(matrix[j]<sp.top().first){
                tempj=sp.top().second;
                ans=max(ans,sp.top().first*(j-sp.top().second));
                sp.pop();
            }
            if(matrix[j]>sp.top().first)
                sp.push({matrix[j],tempj});
        }
    }
    while(!sp.empty()){
        if(sp.top().first !=-1)
            ans=max(ans,sp.top().first*(m-sp.top().second));
        sp.pop();
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>matrix[i];
    cout<<calculateMAX()<<"\n";
}




