#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX 200005
bool comp(pair<int,bool> &a,pair<int,bool> &b){
    return a.first<b.first;
}
int main()
{
    int n,a,b,i=0,sz,now=0,ans=-1;
    scanf("%d",&n);
    pair<int,bool> arr[n<<1];
    while(n--){
        scanf("%d %d",&a,&b);
        arr[i++]={a,0};
        arr[i++]={b,1};
    }
    sz=i;
    sort(arr,arr+sz,comp);
    for(i=0;i<sz;i++){
        if(arr[i].second)
            now--;
        else {
            now++;
            ans=max(ans,now);
        }
    }
    printf("%d\n",ans);
}




