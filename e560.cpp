#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
#define MAX 205
int n,m;
int main()
{
   while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        vector<vector<bool> > matrix(n,vector<bool>(m));
        char c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                if(c=='1')
                    matrix[i][j]=true;
                else matrix[i][j]=false;
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){//從窮舉最大矩形由第i row開始
            vector<bool> nowrow(m,true);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++)
                    nowrow[k]=nowrow[k]&&!matrix[j][k];//用dp思想 每一個column由上到下只要有一個不是0不能計算進去
                int startcol;
                for(int k=0;k<m;k++){
                    startcol=k;
                    while(k<m&&nowrow[k])
                        k++;
                    ans=max(ans,(j-i+1)*(k-startcol));
                }
            }
        }
        cout<<ans<<"\n";
   }

}









