#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 4000000
/*
struct Node{
    int val,tag;
    Node(){
        val=0;
        tag=1;
    }
};
Node tree[MAX];
int cmd,s;
int query(int a,int b,int l,int r,int now){

}
void modify(int a,int b,int l,int r,int now){
    if(cmd==1){
        int mid=(l+r)/2;
        if(a<l&&b>r)
            tree[now].val+=s;
        else if(a<l)
            modify(a,b,l,mid,now*2);
        else if(b>r)
            modify(a,b,mid+1,r,now*2+1);
        else {
            modify(a,b,l,mid,now*2);
            modify(a,b,mid+1,r,now*2+1);
        }
    }
    else {
        int mid=(l+r)/2;
        if(a<l&&b>r)
            tree[now].tag*=s;
        else if(a<l)
            modify(a,b,l,mid,now*2);
        else if(b>r)
            modify(a,b,mid+1,r,now*2+1);
        else {
            modify(a,b,l,mid,now*2);
            modify(a,b,mid+1,r,now*2+1);
        }
    }
}
*/
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);//複雜度O(m*n)
    int n,m,temp;
    while(cin>>n>>m){
        vector<int> ivec;
        vector<int>::iterator it;
        ll ans=0;
        while(n--){
            cin>>temp;
            ivec.push_back(temp);
        }
        sort(ivec.begin(),ivec.end());
        while(m--){
            cin>>temp;
            if(!ivec.empty()){
                it=upper_bound(ivec.begin(),ivec.end(),temp);
                if(it !=ivec.begin()){
                    it--;
                    ans+=*it;
                    ivec.erase(it);
                }
            }
        }
        cout<<ans<<"\n";
        ivec.clear();
    }
}
/* map版解法
#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);//複雜度O(m*log(n))
    int n,m,temp;
    while(cin>>n>>m){
        map<int,int> mi;
        map<int,int>::iterator it;
        ll ans=0;
        while(n--){
            cin>>temp;
            mi[temp]++;
        }
        while(m--){
            cin>>temp;
            it=mi.upper_bound(temp);
            if(it !=mi.begin()){
                bool error=false;
                for(it--;it !=mi.begin();it--){
                    if(it->second !=0){
                        if(--it->second==0){
                            error=true;
                            mi.erase(it);
                        }
                        ans+=it->first;
                        break;
                    }
                }
                if(error==false&&it==mi.begin()){
                    if(it->second !=0){
                        it->second--;
                        ans+=it->first;
                    }
                }
            }
        }
        cout<<ans<<"\n";
        mi.clear();
    }
}
*/
