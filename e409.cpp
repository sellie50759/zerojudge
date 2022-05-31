#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
#define MAX 1005
typedef long long ll;
const int MaxN = 1000000+5;
const int MaxQ = 100000+5;
int A[MaxN];
bool C[MaxQ];
int X[MaxQ] , Y[MaxQ];
int k,m,N,Q;
void gen_dat()
{
    int i,j;
    for( i=k+1; i<=max(Q,N); ++i )
         A[i] = ( A[i-2]*97 + A[i-1]*3 )%m+1;
    for(i=1,j=max(Q,N); i<=Q; ++i,--j)
    {
        C[i] = A[i]&1;
        X[i] = (A[i]+A[j])%N+1;
        if(C[i]) Y[i] = X[i]+ ( (A[i]<<3)+(A[j]<<5)+m )%( N-X[i]+1 );
        else Y[i] = ((A[i]<<3)+(A[j]<<5))%m+1;
    }
}
class Node{
    public:
    int Max,Min;
    Node(){
        Max=-1;
        Min=1e6;
    }
    Node(int v){
        Max=Min=v;
    }
    Node(int maxx,int minn){
        Max=maxx;
        Min=minn;
    }
};
Node seg_tree[MaxN*4];
pair<int,int> build(int now,int l,int r){
    if(l==r){
        seg_tree[now]=Node(A[l+1]);
        return make_pair(A[l+1],A[l+1]);
    }
    int mid=(l+r)/2;
    pair<int,int> left_result=build(now*2+1,l,mid),right_result=build(now*2+2,mid+1,r);
    pair<int,int> result=make_pair(max(left_result.first,right_result.first),min(left_result.second,right_result.second));
    seg_tree[now]=Node(result.first,result.second);
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
    seg_tree[now].Max=max(seg_tree[now*2+1].Max, seg_tree[now*2+2].Max);
    seg_tree[now].Min=min(seg_tree[now*2+1].Min, seg_tree[now*2+2].Min);
}
// max,min
pair<int,int> query(int now,int l,int r,int L,int R){
    if(L<=l&&R>=r){
        return make_pair(seg_tree[now].Max,seg_tree[now].Min);
    }
    int mid=(l+r)/2;
    if(R<=mid){
        return query(now*2+1,l,mid,L,R);
    }
    else if(L>mid){
        return query(now*2+2,mid+1,r,L,R);
    }
    else {
        pair<int,int> left_result=query(now*2+1,l,mid,L,mid),right_result=query(now*2+2,mid+1,r,mid+1,R);
        pair<int,int> result=make_pair(max(left_result.first,right_result.first),min(left_result.second,right_result.second));
        return result;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin>>k>>m){
        for(int i=1;i<=k;i++){
            cin>>A[i];
        }
        cin>>N>>Q;
        gen_dat();
        build(0,0,N-1);
        for(int i=1;i<=Q;i++){
            //cout<<"command: "<<C[i]<<" "<<X[i]<<" "<<Y[i]<<"\n";
            if(C[i]){
                if(X[i]>Y[i])
                    swap(X[i],Y[i]);
                pair<int,int> result=query(0,0,N-1,X[i]-1,Y[i]-1);
                cout<<result.first-result.second<<"\n";
            }
            else {
                modify(0,0,N-1,X[i]-1,Y[i]);
            }
        }
    }
    return 0;
}
