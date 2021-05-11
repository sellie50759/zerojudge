#include<iostream>
using namespace std;
#define MAX 3005
typedef long long ll;
ll Map[MAX][MAX]={0};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,u;
    cin>>n>>u;//不可用while(cin>>n>>u) 測資後有多餘的東西
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>Map[i][j];
                if(Map[i][j]==-1)
                    Map[i][j]=2e9;
                Map[i][j]+=Map[i][j-1]+Map[i-1][j]-Map[i-1][j-1];//Map[i][j]代表(0,0)~(i,j)所有元素的加總
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=ans;j+k<=n&&i+k<=n;k++){
                    if(Map[i+k][j+k]-Map[i+k][j-1]-Map[i-1][j+k]+Map[i-1][j-1]<=u)
                        ans=k+1;
                    else break;
                }
            }
        }
        cout<<ans*ans<<"\n";
}



