#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
char board[9][9];
bool error=false;
int dir[4][2]={-1,0,1,0,0,1,0,-1};
bool isValid(int x,int y){
    return x>=0&&y>=0&&x<9&&y<9;
}
void dfs(int x,int y,char c){
    if(isValid(x,y)){
        if(board[y][x]=='.'){
            board[y][x]=c;
            for(int i=0;i<4;i++)
                dfs(x+dir[i][0],y+dir[i][1],c);
        }
        else if(board[y][x] !=c){
            error=true;
            return;
        }
    }
}
int main()
{
   for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)
        cin>>board[i][j];
   }
   for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(int k=0;k<4;k++){
                    if(isValid(j+dir[k][0],i+dir[k][1])&&board[i+dir[k][1]][j+dir[k][0]] !='.'){
                        dfs(j,i,board[i+dir[k][1]][j+dir[k][0]]);
                        break;
                    }
                }
                if(error){
                    cout<<"Wrong\n";
                    break;
                }
            }
        }
        if(error)
            break;
   }
   if(error==false){
        int B=0,W=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='B')
                    B++;
                else if(board[i][j]=='W')
                    W++;
                else {
                    error=true;
                    cout<<"Wrong\n";
                    break;
                }
            }
            if(error)
                break;
        }
        if(error==false){
            cout<<(B>W?"Black wins!!":"White wins!!")<<"\n";
            cout<<B<<":"<<W<<"\n";
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<board[i][j];
                }
                cout<<"\n";
            }
        }
   }
}
