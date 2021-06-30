#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 30
int n,m;
bool dir[2][2]={-1,0,1,0};
bool isValid(int x,int y){
    return x>=0&&y>=0&&y<n&&x<m;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    bool matrix[MAX][MAX];
    char c;
    while(cin>>m>>n){
        bool error=false;
        string s(m,'-');
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                if(c=='O')
                    matrix[i][j]=true;
                else matrix[i][j]=false;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]){
                    for(int k=0;k<2;k++){
                        int nexty=i+dir[k][0],nextx=j+dir[k][1];
                        if(isValid(nextx,nexty)&&matrix[nexty][nextx]){
                            error=true;
                            break;
                        }
                    }
                    if(error)
                        break;
                }
            }
            if(error)
                break;
        }
        if(error)
            cout<<"ERROR\n";
        else {
            vector<char> cvec(n+1);
            for(int i=0;i<=n;i++){
                int nowx=0,nowy=i;
                while(nowx !=m){
                    if(isValid(nowx,nowy)&&matrix[nowy][nowx])
                        nowy++;
                    else if(isValid(nowx,nowy-1)&&matrix[nowy-1][nowx])
                        nowy--;
                    nowx++;
                }
                cvec[nowy]=i+'A';
            }
            for(int i=0;i<n;i++){
                cout<<char('A'+i)<<s<<cvec[i]<<"\n";
                cout<<" ";
                for(int j=0;j<m;j++){
                    if(matrix[i][j])
                        cout<<"|";
                    else cout<<" ";
                }
                cout<<" \n";
            }
            cout<<char('A'+n)<<s<<cvec.back()<<"\n";
            for(int i=0;i<m;i++)
                cout<<" ";
            cout<<"\n";
        }
    }


}
/*
基本上只要照著題目說明模擬即可，不過要小心這題的輸出格式。
*


