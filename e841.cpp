#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct point{
    bool isleft;
    int pos;
    int r;
    int s;
};
bool comp(point &a,point &b){
    if(a.pos==b.pos){
        if(a.isleft&&b.isleft)
            return false;
        else if(a.isleft&&!b.isleft)
            return true;
        else if(!a.isleft&&b.isleft)
            return false;
        else if(!a.isleft&&!b.isleft)
            return false;
    }
    else return a.pos<b.pos;
}
#define MAX 50001
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,p,q,r,s;
    vector<point> points;
    while(cin>>n>>m){
        while(m--){
            cin>>p>>q>>r>>s;
            point temp;
            temp.isleft=true;
            temp.pos=p;
            temp.r=r;
            temp.s=s;
            points.push_back(temp);
            temp.isleft=false;
            temp.pos=q;
            points.push_back(temp);
        }
        sort(points.begin(),points.end(),comp);
        ll x=0,y=1,ans=-1,ansi=-1; //x是金幣總數，y是金幣倍率
        for(int i=0;i<points.size();i++){
            if(points[i].isleft){
                if(points[i].r==1)
                    x+=points[i].s;
                else y*=points[i].s;
            }
            else {
                if(points[i].r==1)
                    x-=points[i].s;
                else y/=points[i].s;
            }
            if(ans<x*y){
                ansi=points[i].pos;
                ans=x*y;
            }
        }
        cout<<ansi<<" "<<ans<<"\n";
        points.clear();
    }


}
/*
參考inversion大大的這篇文
https://home.gamer.com.tw/artwork.php?sn=5249349
另外有一個我從這次題目複習到的小tip，c++sort的自訂比較函數如果要表示誰前誰後都一樣的話，
就要讓a跟b與b跟a比較都回傳false，之前有查過這個問題，可是又忘記了，藉由這次題目又再複習一次。
*/



