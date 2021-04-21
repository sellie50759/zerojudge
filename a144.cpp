#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define MAX 20005
vector<int> ivec;
void Merge(int i){
    for(int j=i;j<ivec.size()-1;j++){
        int k=1;
        while(ivec[j]<ivec[i-1]){
            while(ivec[j+k]==0){
                k++;
                if(j+k==ivec.size())
                    break;
            }
            if(j+k==ivec.size())
                break;
            ivec[j]++;
            ivec[j+k]--;
        }
        if(j+k==ivec.size())
            break;
    }
    while(ivec.back()==0)
        ivec.pop_back();
    //system("pause");
}
bool next(){
    for(int i=ivec.size()-1;i>=0;i--){
        if(ivec[i] !=1){
            if(i==ivec.size()-1||ivec[i]==2){
                int temp=ivec[i];
                vector<int> tmp={temp-1,1};
                ivec.erase(ivec.begin()+i);
                ivec.insert(ivec.begin()+i,tmp.begin(),tmp.end());
            }
            else {
                ivec[i]--;
                ivec[i+1]++;
                Merge(i+1);
            }
            return true;
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        cout<<n<<"\n";
        ivec.push_back(n);
        while(next()){
            for(int i=0;i<ivec.size();i++)
                cout<<ivec[i]<<" ";
            cout<<"\n";
        }
        ivec.clear();
    }

}




