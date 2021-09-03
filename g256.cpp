#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 1000005
int arr[MAX]={0,0};
int f(ll n){
    if(n==1)
        return 0;
    if(n<MAX&&arr[n])
        return arr[n];
    if(n&1){
        if(n<MAX)
            return arr[n]=f(3*n+1)+1;
        else return f(3*n+1)+1;
    }
    else {
        if(n<MAX)
            return arr[n]=f(n>>1)+1;
        else return f(n>>1)+1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    for(int i=2;i<MAX;i++)
        f(i);
    while(cin>>n)
        cout<<arr[n]<<"\n";
}
    /*
        原本以為建表會比遞迴快，結果是要在資料大於一定的量級之後才會比較快，可能也是因為這題的序列都不會太長，所以導致建表的效益偏低。
        這題無論是建表或遞迴都可以做，以下附上遞迴的程式碼。
        
        
        
        #include <iostream>
        #include <string>
        #include <set>
        #include<vector>
        #include <map>
        #include<stack>
        #include<cstring>
        #include<cmath>
        #include<algorithm>
        using namespace std;
        typedef long long ll;
        #define MAX 1000005
        int f(ll n){
            if(n==1)
                return 0;
            if(n&1)
                return f(3*n+1)+1;
            else return f(n>>1)+1;
        }
        int main()
        {
            cin.tie(0);
            ios::sync_with_stdio(false);
            int n;
            while(cin>>n)
                cout<<f(n)<<"\n";

        }
    */



