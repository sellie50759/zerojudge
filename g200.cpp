#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAX 50001
vector<vector<string> > output;//最終的輸出
struct Node{
    string val;
    vector<Node*> next;
};
void bfs(Node* now){
    queue<Node*> qn;
    qn.push(now);
    output.push_back(vector<string>());
    int depth=0;
    while(!qn.empty()){
        int sz=qn.size();
        while(sz--){
            Node* temp=qn.front();
            output[depth].push_back(temp->val);
            for(int i=0;i<temp->next.size();i++)
                qn.push(temp->next[i]);
            qn.pop();
        }
        depth++;
        output.push_back(vector<string>());
    }
}
void dfs(Node* now){
    cout<<now->val<<"\n";
    for(int i=0;i<now->next.size();i++)
        dfs(now->next[i]);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Node *root=new Node;
    map<string,Node*> nametonode;//由名字對應到node*的表
    string rt,s,t;
    int n,m,d;
    while(cin>>rt>>n>>m){
        root->val=rt;
        nametonode[rt]=root;
        while(n--){
            cin>>s>>t;
            Node* temp=new Node;
            temp->val=t;
            nametonode[s]->next.push_back(temp);
            nametonode[t]=temp;
        }
        bfs(root);
        while(m--){
            cin>>d;
            d--;
            for(int i=0;i<output[d].size();i++)
                cout<<output[d][i]<<" ";
            cout<<"\n";
        }
        output.clear();
        nametonode.clear();
    }

}
/*
c++的直接模擬就行 照題目需求建一棵多叉樹 然後跑一次bfs得出每層的輸出順序即可
*/



