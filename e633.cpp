#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
char determine(char c){
    if(c=='R')
        return '/';
    else if(c=='F')
        return '\\';
    else return '_';
}
int main(){
    int n,r=1;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        cout<<"Case #"<<r++<<":\n";
        int height=1,ground=1,cnt=1,width=s.size()+2;
        map<int,vector<pair<int,char> > > mi;
        for(int i=0;i<s.size();i++){
            if(s[i]=='F'){
                cnt--;
                ground=min(cnt,ground);
            }
            if(mi.count(cnt))
                mi[cnt].push_back(make_pair(i+1,s[i]));
            else {
                vector<pair<int,char> > temp;
                temp.push_back(make_pair(i+1,s[i]));
                mi[cnt]=temp;
            }
            if(s[i]=='R'){
                cnt++;
                height=max(cnt,height);
            }
        }
        /*
        for(auto &it:mi){
            cout<<it.first<<"\n";
            for(int j=0;j<it.second.size();j++)
                cout<<it.second[j].first<<" "<<it.second[j].second<<"\n";
        }
        */
        for(int i=height;i>=ground;i--){
            vector<pair<int,char> > temp=mi[i];
            if(temp.size()==0)
                continue;
            cout<<"| ";
            int k=1;
            for(int j=0;j<temp.size();j++,k++){
                while(temp[j].first>k){
                    cout<<" ";
                    k++;
                }
                cout<<determine(temp[j].second);
            }
            while(k !=width){
                cout<<" ";
                k++;
            }
            cout<<"\n";
        }
        cout<<'+'<<string(width,'-')<<"\n";
    }
}

/*
勞力題，照著題目的意思去做即可，注意格式
*/




