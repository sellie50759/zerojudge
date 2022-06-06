#include<iostream>
#include<map>
#include<set>
#define MAX 500005
using namespace std;
typedef long long ll;
class Node{
public:
    ll val,tag;
    Node(){
        val=0;
        tag=0;
    }
    Node(int v){
        val=v;
        tag=0;
    }
};
Node seg_tree[MAX*4];
int arr[MAX];
void build(int l,int r,int now){
    if(l==r){
        seg_tree[now]=Node(arr[l]);
        return ;
    }

    int mid=(l+r)/2;
    build(l,mid,now*2+1);
    build(mid+1,r,now*2+2);

    seg_tree[now]=Node(seg_tree[now*2+1].val+seg_tree[now*2+2].val);
}
ll query(int l,int r,int now,int L,int R){
    if(l==L&&r==R){
        //cout<<l<<" "<<r<<" "<<seg_tree[now].val<<" "<<seg_tree[now].tag*(r-l+1)<<"&\n";
        return seg_tree[now].val+seg_tree[now].tag*(r-l+1);
    }

    seg_tree[now*2+1].tag+=seg_tree[now].tag;
    seg_tree[now*2+2].tag+=seg_tree[now].tag;
    seg_tree[now].val+=seg_tree[now].tag*(r-l+1);
    seg_tree[now].tag=0;

    int mid=(l+r)/2;
    if(R<=mid){
        return query(l,mid,now*2+1,L,R);
    }
    else if(L>mid){
        return query(mid+1,r,now*2+2,L,R);
    }
    else {
        return query(l,mid,now*2+1,L,mid)+query(mid+1,r,now*2+2,mid+1,R);
    }
}
void modify(int l,int r,int now,int L,int R,int k){
    if(l==L&&r==R){
        seg_tree[now].tag+=k;
        return ;
    }

    int mid=(l+r)/2;
    if(R<=mid){
        modify(l,mid,now*2+1,L,R,k);
    }
    else if(L>mid){
        modify(mid+1,r,now*2+2,L,R,k);
    }
    else {
        modify(l,mid,now*2+1,L,mid,k);
        modify(mid+1,r,now*2+2,mid+1,R,k);
    }

    ll left=seg_tree[now*2+1].val+seg_tree[now*2+1].tag*(mid-l+1);
    ll right=seg_tree[now*2+2].val+seg_tree[now*2+2].tag*(r-mid);
    seg_tree[now].val=left+right;

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q,cmd,l,r,k;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        build(0,n-1,0);
        cin>>q;
        while(q--){
            cin>>cmd;
            if(cmd==1){
                cin>>l>>r>>k;
                l--,r--;
                modify(0,n-1,0,l,r,k);
            }
            else {
                cin>>l>>r;
                l--,r--;
                cout<<query(0,n-1,0,l,r)<<"\n";
            }
        }
    }
    return 0;
}
