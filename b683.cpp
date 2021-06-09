#include<iostream>
using namespace std;
typedef unsigned long long ull;
#define MAX 35
int n,m,dir[4][2]={-1,0,1,0,0,-1,0,1},sum;
bool isring=false;
bool matrix[MAX][MAX];
bool isValid(int x,int y){
    return y<n&&x<m&&y>=0&&x>=0;
}
void dfs(int x,int y,bool isorigin){
    matrix[y][x]=true;
    sum++;
    for(int i=0;i<4;i++){
        if(isorigin){
            if(isValid(x+dir[i][0],y+dir[i][1])&&matrix[y+dir[i][1]][x+dir[i][0]]==false){
                dfs(x+dir[i][0],y+dir[i][1],false);
                //cout<<sum<<"\n";
                for(int j=0;j<4;j++){
                    if(isValid(x+dir[j][0],y+dir[j][1])){
                        if(matrix[y+dir[j][1]][x+dir[j][0]]==false){
                            isring=false;
                            dfs(x+dir[j][0],y+dir[j][1],false);
                        }
                    }
                }
            }
        }
        else if(isValid(x+dir[i][0],y+dir[i][1])&&matrix[y+dir[i][1]][x+dir[i][0]]==false)
                dfs(x+dir[i][0],y+dir[i][1],false);
    }
}
int main() {
    char c;
    while(cin>>n>>m){
        int X=0,Y=0;
        ull Z=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                if(c=='.')
                    matrix[i][j]=false;
                else matrix[i][j]=true;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==false){
                    sum=0;
                    isring=true;
                    int val=0;
                    for(int k=0;k<4;k++){
                        if(isValid(j+dir[k][1],i+dir[k][0])&&matrix[i+dir[k][0]][j+dir[k][1]]==false)
                            val++;
                    }
                    //cout<<i<<" "<<j<<" "<<val<<"\n";
                    if(val==2)
                        dfs(j,i,true);
                    else {
                        isring=false;
                        dfs(j,i,false);
                    }
                    if(isring){
                        X++;
                        Y+=sum;
                        Z*=sum;
                    }
                }
            }
        }
        cout<<X<<" "<<Y<<" "<<Z<<"\n";
    }
}

