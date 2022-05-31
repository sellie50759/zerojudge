#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
#define MAX 1005
typedef long long ll;
const int MaxN=1e5+5;
int A[MaxN];
class Node{
    public:
    int sign;
    Node(){
        sign=0;
    }
    Node(int v){
        if(v>0)
            sign=1;
        else if(v<0)
            sign=-1;
        else sign=0;
    }
};
Node seg_tree[MaxN*4];
int build(int now,int l,int r){
    if(l==r){
        seg_tree[now]=Node(A[l]);
        return seg_tree[now].sign;
    }
    int mid=(l+r)/2;
    int left_result=build(now*2+1,l,mid),right_result=build(now*2+2,mid+1,r);
    int result=left_result*right_result;
    seg_tree[now]=Node(result);
    return result;
}
void modify(int now,int l,int r,int pos,int x){
    if(l==r){
        seg_tree[now]=Node(x);
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        modify(now*2+1,l,mid,pos,x);
    else {
        modify(now*2+2,mid+1,r,pos,x);
    }
    seg_tree[now].sign=seg_tree[now*2+1].sign*seg_tree[now*2+2].sign;
}
// max,min
int query(int now,int l,int r,int L,int R){
    if(L==l&&R==r)
        return seg_tree[now].sign;
    int mid=(l+r)/2;
    if(R<=mid){
        return query(now*2+1,l,mid,L,R);
    }
    else if(L>mid){
        return query(now*2+2,mid+1,r,L,R);
    }
    else {
        int left_result=query(now*2+1,l,mid,L,mid),right_result=query(now*2+2,mid+1,r,mid+1,R);
        int result=left_result*right_result;
        return result;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,x,y;
    char cmd;
    while(cin>>n>>k){
        for(int i=0;i<n;i++)
            cin>>A[i];

        build(0,0,n-1);

        while(k--){
            cin>>cmd>>x>>y;
            if(cmd=='C'){
                modify(0,0,n-1,x-1,y);
            }
            else {
                int result=query(0,0,n-1,x-1,y-1);
                if(result>0)
                    cout<<"+";
                else if(result<0)
                    cout<<"-";
                else cout<<"0";
            }
        }
        cout<<"\n";
    }

    return 0;
}

