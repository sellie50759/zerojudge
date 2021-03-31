#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
char color[4]={'S','H','D','C'};
typedef pair<int,char> cd;
bool cdcmp(cd &a,cd &b){
    return a.first==b.first?a.second>b.second:a.first>b.first;
}
bool cmp(pair<int,vector<cd> > &a,pair<int,vector<cd> > &b){
    int sz=a.second.size();
    for(int i=0;i<sz;i++){
        if(a.second[i].first !=b.second[i].first)
            return a.second[i].first>b.second[i].first;
    }
    return a.second[0].second>b.second[0].second;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,temp,r=1;
    vector<pair<int,vector<cd>> > card;
    cin>>t;
    while(t--){
        card.resize(10);
        for(int i=0;i<10;i++)
            card[i].first=i+1;
        for(int i=0;i<5;i++){
            for(int j=0;j<10;j++){
                cin>>temp;
                if(temp%13==0)
                    card[j].second.push_back(make_pair(14,color[temp/13]));
                else card[j].second.push_back(make_pair(temp%13+1,color[temp/13]));
            }
        }
        cin>>temp>>temp;
        for(int i=0;i<card.size();i++)
            sort(card[i].second.begin(),card[i].second.end(),cdcmp);
        sort(card.begin(),card.end(),cmp);
        cout<<"Case "<<r++<<":\n";
        for(int i=0;i<card.size();i++){
            cout<<card[i].first<<" ";
            for(int j=0;j<card[i].second.size();j++){
                cout<<card[i].second[j].second;
                if(card[i].second[j].first==14)
                    cout<<'A';
                else if(card[i].second[j].first==13)
                    cout<<'K';
                else if(card[i].second[j].first==12)
                    cout<<'Q';
                else if(card[i].second[j].first==11)
                    cout<<'J';
                else if(card[i].second[j].first==10)
                    cout<<'T';
                else cout<<card[i].second[j].first;
                cout<<" ";
            }
            cout<<"\n";
        }
        card.clear();
    }
}











