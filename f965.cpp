#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
#define MAX 1000005
class directory{
    public:
    directory* pre;
    map<string,int> files;
    vector<directory> dirs;
    directory(directory* previous){
        pre=previous;
        dirs.reserve(1000);//zj的伺服器不知道為什麼要加這行才會對，不加的話某些測資會記憶體錯誤
    }
    void touch(string s){
        if(!files.count(s))
            files[s]=-1;
    }
    void mkdir(string s){
        if(!files.count(s)){
            files[s]=dirs.size();
            dirs.push_back(directory(this));
        }
        else cout<<"mkdir: "<<s<<": File exists\n";
    }
    void ls(){
        for(map<string,int>::iterator it=files.begin();it !=files.end();it++)
            cout<<it->first<<"\n";
    }
};
int main() {
    int n;
    string s,name;
    directory temp(NULL);
    directory* now=&temp;
    cin>>n;
    while(n--){
        try{
        cin>>s;
        if(s !="ls")
            cin>>name;
        if(s=="touch")
            now->touch(name);
        else if(s=="mkdir")
            now->mkdir(name);
        else if(s=="cd"){
            if(name==".."&&now->pre !=NULL)
                now=now->pre;
            else if(name !=".."&&(!now->files.count(name)))
                cout<<"cd: "<<name<<": No such file or directory\n";
            else if(name !=".."&&(now->files)[name]==-1)
                cout<<"cd: "<<name<<": Not a directory\n";
            else if(name !=".."&&(now->files)[name] !=-1)
                now=&((now->dirs)[(now->files)[name]]);
        }
        else if(s=="ls")
            now->ls();
        }
        catch(exception ex){
            cout<<ex.what()<<"\n";
        }
    }
}
