#include<stdio.h>
using namespace std;
typedef long long ll;
#define MAX 5005
int main() {
    static int sz=0,i=1,j,arr[MAX],sum=0;
    static char c;
    while((c=getchar()) !=EOF){
        if(c=='\n'){
            i=1;
            arr[sz++]=sum;
            sum=0;
        }
        else {
            if(c<='z'&&c>='a')
                sum+=i*(c-'a'+36);
            else if(c<='Z'&&c>='A')
                sum+=i*(c-'A'+10);
            else sum+=i*(c-'0');
            i++;
        }
    }
    for(i=0;i<sz;i++){
        for(j=i+1;j<sz;j++){
            if(arr[i]==arr[j]){
                printf("%d %d\n",i+1,j+1);
                return 0;
            }
        }
    }
}

