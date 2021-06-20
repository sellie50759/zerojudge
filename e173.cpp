#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
#define MAX 20
char board[MAX][MAX];
int n;
int dir[8][2]={-1,0,1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
bool isValid(int x,int y){
    return x>=0&&y>=0&&x<n&&y<n;
}
void Eye(int x,int y,int id){//1 正常 2 邊緣 3 角落
    int a=0,b=0;
    for(int i=0;i<4;i++){
            int nextx=x+dir[i][0],nexty=y+dir[i][1];
            if(isValid(nextx,nexty)){
                if(board[nexty][nextx]=='O')
                    a++;
                else if(board[nexty][nextx]=='X')
                    b++;
            }
    }
    if(id==1){
        if(a !=4&&b !=4)
            cout<<"Interesting...\n";
        else {
            for(int i=4;i<8;i++){
            int nextx=x+dir[i][0],nexty=y+dir[i][1];
            if(isValid(nextx,nexty)){
                if(board[nexty][nextx]=='O')
                    a++;
                else if(board[nexty][nextx]=='X')
                    b++;
            }
            }
            if(a>=7||b>=7)
                cout<<"Real!\n";
            else cout<<"Fake!\n";
        }
    }
    else if(id==2){
        if(a !=3&&b !=3)
            cout<<"Interesting...\n";
        else {
        for(int i=4;i<8;i++){
            int nextx=x+dir[i][0],nexty=y+dir[i][1];
            if(isValid(nextx,nexty)){
                if(board[nexty][nextx]=='O')
                    a++;
                else if(board[nexty][nextx]=='X')
                    b++;
            }
        }
            if(a==5||b==5)
                cout<<"Real!\n";
            else cout<<"Fake!\n";
        }
    }
    else {
       if(a !=2&&b !=2)
            cout<<"Interesting...\n";
        else {
        for(int i=4;i<8;i++){
            int nextx=x+dir[i][0],nexty=y+dir[i][1];
            if(isValid(nextx,nexty)){
                if(board[nexty][nextx]=='O')
                    a++;
                else if(board[nexty][nextx]=='X')
                    b++;
            }
        }
            if(a==3||b==3)
                cout<<"Real!\n";
            else cout<<"Fake!\n";
        }
    }
}
int main() {
    int t,x,y,r=1;
    while(cin>>n){
        if(n==0)
            break;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>board[i][j];
    }
    cin>>t;
    while(t--){
        cin>>x>>y;
        x--;
        y=n-y;
        if(board[y][x]=='.'){//要先確保眼的位置是沒有放棋子的
            int id;
            if(x==0&&y==0||x==0&&y==n-1||x==n-1&&y==0||x==n-1&&y==n-1)
                id=3;
            else if(x==0||y==0||x==n-1||y==n-1)
                id=2;
            else id=1;
            Eye(x,y,id);
        }
        else cout<<"Interesting...\n";
    }
    }
}
