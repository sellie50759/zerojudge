#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
#define MAX 205
int matrix[MAX][MAX];
int n,m;
int calculateMAX(int i){
    stack<pair<int,int> > sp;//計算最大矩形面積 可參考c907
    int ans=0;
    sp.push({-1,0});
    for(int j=0;j<m;j++){
        if(sp.top().first<matrix[i][j])
            sp.push({matrix[i][j],j});
        else {
            int tempj;
            while(matrix[i][j]<sp.top().first){
                tempj=sp.top().second;
                ans=max(ans,sp.top().first*(j-sp.top().second));
                sp.pop();
            }
            if(matrix[i][j]>sp.top().first)
                sp.push({matrix[i][j],tempj});
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
   bool temp;
   while(cin>>n>>m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>temp;
                if(temp){
                    if(i !=0)
                        matrix[i][j]=1+matrix[i-1][j];
                    else matrix[i][j]=1;
                }
                else matrix[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,calculateMAX(i));
        cout<<ans<<"\n";
   }

}




