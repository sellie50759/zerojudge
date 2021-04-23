#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
#define MAX 205
int main()
{
   int n,m;
   vector<vector<int> > ivec;
   while(cin>>n>>m){
        for(int i=0;i<n;i++){
            vector<int> temp;
            int val;
            for(int j=0;j<m;j++){
                cin>>val;
                temp.push_back(val);
            }
            ivec.push_back(temp);
        }
        int sum=0;
        vector<int> maxval;
        for(int i=0;i<n;i++){
            int maxx=-1;
            for(int j=0;j<m;j++)
                maxx=max(maxx,ivec[i][j]);
            sum+=maxx;
            maxval.push_back(maxx);
        }
        cout<<sum<<"\n";
        bool sign=false;
        for(int i=0;i<maxval.size();i++){
            if(sum%maxval[i]==0){
                cout<<maxval[i]<<" ";
                sign=true;
            }
        }
        if(sign==false)
            cout<<"-1";
        cout<<"\n";
        ivec.clear();
   }

}




