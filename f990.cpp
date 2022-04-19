#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define MOD 1000000007
typedef pair<int,int> point;
vector<point> points;
typedef long long ll;
#define MAX 50
double evalute(double x,double y){
    double ans=0;
    for(int i=0;i<points.size();i++){
        ans+=sqrt(pow(points[i].first-x,2)+pow(points[i].second-y,2));
    }
    return ans;
}
double ternary_search(int left,int right,int m,int k){
    double l=left,r=right;
    for(int i=0;i<MAX;i++){
        double ml=(l+r)/2,mr=(ml+r)/2;
        if(evalute(ml,ml*m+k)<evalute(mr,mr*m+k))
            r=mr;
        else l=ml;
    }
    return (l+r)/2;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,m,k,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        while(n--){
            cin>>x>>y;
            points.push_back({x,y});
        }
        cout<<ternary_search(-1e6,1e6,m,k)<<"\n";
        points.clear();
    }
}
/*
使用三分搜尋法
可參考https://yuihuang.com/ternary-search/
*/

