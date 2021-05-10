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
    ios::sync_with_stdio(false);
    string n,temp;
    int m;
    cin>>n>>m;
    while(m--){
        cin>>temp;
        int A=0,B=0;
        for(int i=0;i<n.size();i++){
            if(temp.find(n[i]) !=string::npos)
                B++;
        }
        for(int i=0;i<n.size();i++){
            if(n[i]==temp[i])
                A++;
        }
        cout<<A<<"A"<<B-A<<"B\n";
    }

}



