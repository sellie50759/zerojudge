/*因為我正在讀OS，所以我就出了這題。

現在請各位寫一支程式模擬以下這些指令：

1. touch [name]：如果當前資料夾下沒有叫做 [name] 的檔案或資料夾，則在當前資料夾下新增一個叫做 [name] 的檔案。

2. mkdir [name]：如果當前資料夾下沒有叫做 [name] 的檔案或資料夾，則在當前資料夾下新增一個叫做 [name] 的資料夾。否則，印出一行 mkdir: [name]: File exists。

3. cd [name]：

i. 如果 [name] 是 .. 且當前資料夾不是 /，則前往上層資料夾。

ii. 如果 [name] 不是 .. 且當前資料夾下沒有叫做 [name] 的檔案或資料夾，則印出一行 cd: [name]: No such file or directory。

iii. 如果 [name] 不是 .. 且當前資料夾下有叫做 [name] 的檔案，則印出一行 cd: [name]: Not a directory。

iv. 如果 [name] 不是 .. 且當前資料夾下有叫做 [name] 的資料夾，則前往該資料夾。

4. ls：依照字典序由小到大印出所有當前資料夾下的檔案和資料夾，一行一個。

程式開始前當前資料夾為 / 且 / 下沒有任何檔案或資料夾。

範例輸入 #1
11
touch b
mkdir b
touch b
mkdir a
cd a
cd a
touch a
cd a
cd ..
cd ..
ls
範例輸出 #1
mkdir: b: File exists
cd: a: No such file or directory
cd: a: Not a directory
a
b
*/
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
