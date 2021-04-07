#include <iostream>
#include <string>
#include <set>
#include<vector>
#include <map>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 100000000
struct point
{
    int idx,first,second,rk;
};
vector<point> pvec;
vector<point>::iterator it;
int rk[10005];
bool comp(point &a,point &b)
{
    if(a.first==b.first)
        return a.second>b.second;
    else return a.first<b.first;
}
bool ycomp(point &a,point &b)
{
    return a.second<b.second;
}
void DCmerge(int l,int r)
{
    int m=(l+r)/2;
    sort(pvec.begin()+l,pvec.begin()+m+1,ycomp);
    for(int i=m+1; i<=r; i++)
    {
        int j,lr=m;
        while(pvec[lr].first==pvec[i].first)
            lr--;
        if(lr !=l-1){//解決x不單調的情況
            for(j=l; j<=m; j++)
            {
                if(pvec[j].second>=pvec[i].second)
                    break;
            }
            pvec[i].rk+=j-l;
        }
    }
}
void DCsolve(int l,int r)
{
    if(l>=r)
        return ;
    int m=(l+r)/2;
    DCsolve(l,m);
    DCsolve(m+1,r);
    DCmerge(l,r);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x,y;
    while(cin>>n)
    {
        int i=0;
        while(n--)
        {
            point temp;
            cin>>temp.first>>temp.second;
            temp.rk=0;
            temp.idx=i++;
            pvec.push_back(temp);
        }
        sort(pvec.begin(),pvec.end(),comp);
        DCsolve(0,pvec.size()-1);
        for(int i=0; i<pvec.size(); i++)
            rk[pvec[i].idx]=pvec[i].rk;
        for(i=0; i<pvec.size(); i++)
            cout<<rk[i]<<"\n";
        pvec.clear();
    }
}




