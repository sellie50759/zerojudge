#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define MAX 100005
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll arr[MAX];//採用hash的方式將複雜度減為nlogn 詳情參考這篇https://home.gamer.com.tw/creationDetail.php?sn=4459304
    int n,k;
    while(cin>>n){
        if(n==0)
            break;
        bool sign=false;
        arr[0]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            arr[i]+=arr[i-1];
        }
        cin>>k;
        map<int,vector<int> > si;
        for(int i=0;i<=n;i++){
            arr[i]%=k;
            if(arr[i]<0)
                arr[i]+=k;
            if(si.count(arr[i]))
                si[arr[i]].push_back(i);
            else {
                vector<int> ivec;
                ivec.push_back(i);
                si[arr[i]]=ivec;
            }
        }
        for(int i=0;i<=n;i++){
            if(si[arr[i]].size() !=1){
                cout<<i+1<<" "<<si[arr[i]][1]<<"\n";
                sign=true;
                break;
            }
        }
        if(sign==false)
            cout<<"no solutions.\n";
    }

}

