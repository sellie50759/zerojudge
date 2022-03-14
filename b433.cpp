#include <iostream>
#include<map>
using namespace std;

typedef unsigned short int UINT16;
class SimpleIdea {
public:
        UINT16 key;
        SimpleIdea(UINT16 k = 0):
               key(k) {}
        UINT16 encrypt(UINT16 m) {
               return (rotate_left(m, key&15) + key)^key;
        }
        UINT16 decrypt(UINT16 m) {
               return rotate_left((m^key)+(~key)+1, 16 - (key&15));
        }
private:
        UINT16 rotate_left(UINT16 x, UINT16 n) {
        return  (x << n) | (x >> (16-n));
        }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int c,m;
    while(cin>>c>>m){
    UINT16 mp[1<<16]={0};
    for (int i = 0; i < (1<<16); i++){
        SimpleIdea test(i);
        mp[test.encrypt(m)]++;
    }
    int ans=0;
    for (int i = 0; i < (1<<16); i++){
        SimpleIdea test(i);
        ans+=mp[test.decrypt(c)];
    }
    cout<<ans<<"\n";
    }
    return 0;
}
/*
使用作者給的程式再加上meet in the middle attack的方法即可
*/
