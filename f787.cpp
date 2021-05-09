#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
class Person{
public:
    string name;
    int life,damage,next;
    bool isshock;
    vector<string> item;
    Person(string Name,int Life,int Damage,vector<string> Item,int Next):name(Name),life(Life),damage(Damage),item(Item),next(Next){
        isshock=false;
    }
    void print(){
        if(life<=damage)
            cout<<name<<" dead.\n";
        else {
            cout<<name<<" "<<life-damage<<" ";
            for(int i=0;i<item.size()-damage;i++)
                cout<<item[i]<<" ";
            cout<<"\n";
        }
    }
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,s,Life,Damage,Next;
    string Name,temp;
    vector<string> Item;
    while(cin>>n>>s){
        vector<Person> pvec;
        s--;
        while(n--){
            cin>>Name>>Life>>Damage;
            Item.resize(Life);
            for(int i=0;i<Life;i++)
                cin>>Item[i];
            cin>>Next;
            Next--;
            pvec.push_back(Person(Name,Life,Damage,Item,Next));
        }
        while(pvec[s].isshock==false){
            pvec[s].isshock=true;
            pvec[s].print();
            s=pvec[s].next;
        }
    }
}



