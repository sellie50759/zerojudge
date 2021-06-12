#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
#define MAX 35
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> ivec;
    int n,ans=0;
    while(cin>>n)
        ivec.push_back(n);
    int i=0,maxx=-1,minn=ivec[0],maxxi=-1,minni=0,ansi=-1,ansj=-1;
    while(i+1<ivec.size()){
        if(ivec[i]<ivec[i+1]){
            while(i+1<ivec.size()&&ivec[i]<ivec[i+1])
                i++;
            if(i+1<ivec.size()){
                if(ivec[i]>maxx){
                    maxx=ivec[i];
                    maxxi=i;
                    if(ans<maxx-minn){
                        ans=maxx-minn;
                        ansi=maxxi;
                        ansj=minni;
                    }
                }
            }
            else {
                if(ivec[i]>maxx){
                    maxx=ivec[i];
                    maxxi=i;
                    if(ans<maxx-minn){
                        ans=maxx-minn;
                        ansi=maxxi;
                        ansj=minni;
                    }
                }
                break;
            }
        }
        else if(ivec[i]>ivec[i+1]){
            while(i+1<ivec.size()&&ivec[i]>ivec[i+1])
                i++;
            if(i+1<ivec.size()){
                if(minn>ivec[i]){
                    maxx=-1;
                    maxxi=-1;
                    minni=i;
                    minn=ivec[i];
                }
            }
            else break;
        }
        else {
            i++;
        }
    }
    cout<<ans<<" "<<(ansj==-1?-1:ivec[ansj])<<" "<<(ansi==-1?-1:ivec[ansi])<<"\n";
}

