#include <iostream>
#include <string>
#include <set>
#include<vector>
#include <map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
bool node[25];
vector<int> ivec;
int len,n;
bool flag;
bool dfs(int i,int sum,int now)
{
    if(sum>len)
        return false;
    if(len==sum){
        now++;
        i=0,sum=0;
        if(now==3)
            return true;
    }
    for(int j=i+1;j<n;j++){
        if(!node[j]){
            node[j]=true;
            if(dfs(j,sum+ivec[j],now))
                return true;
            node[j]=false;
        }
    }
    return false;
}
int main()
{
    int t,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>temp;
            sum+=temp;
            ivec.push_back(temp);
        }
        if(sum%4 !=0)
            cout<<"no\n";
        else
        {
            len=sum/4;
            memset(node,0,sizeof(node));
            node[0]=true;
            if(dfs(0,ivec[0],0))
                cout<<"yes\n";
            else cout<<"no\n";
        }
        ivec.clear();
    }
}
