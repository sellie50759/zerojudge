#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int n,m;
bool Map[9][9];
bool isValid(int x,int y){
    return x<m&&x>=0&&y<n&&y>=0;
}
int dfs(int x,int y){//dfs 找同一行或同一列有沒有兩個卒，有就吃然後將吃到的總數量加一且繼續dfs下去，沒有的話就return 吃到的數量回去
    int sum=0;
    for(int i=0;i<4;i++){
        int nextx=x+dir[i][0],nexty=y+dir[i][1],cnt=0;
        for(;isValid(nextx,nexty);nextx+=dir[i][0],nexty+=dir[i][1]){
            if(Map[nexty][nextx])
                cnt++;
            if(cnt==2)
                break;
        }
        if(cnt==2){
            Map[nexty][nextx]=false;
            //cout<<nexty<<" "<<nextx<<"\n";
            sum=max(dfs(nextx,nexty)+1,sum);
            Map[nexty][nextx]=true;
        }
    }
    return sum;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                Map[i][j]=true;
        }
        Map[0][0]=false;
        cout<<dfs(0,0)<<"\n";
    }
}
