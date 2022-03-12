#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
#define MAX 1000005
inline char readchar() {  //功能是從stdin讀一個char
	const int S = 1e3; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
	//快速io
}
bool error=false;
long long int readint(){  //功能是從stdin讀一個int
    long long int a=0;
    char c='0';
    while(c>='0'&&c<='9'){
        a=(a<<3)+(a<<1)+c-'0';
        c=readchar();
    }
    if(c==EOF)
        error=true;
    return a;
    //讀整數
}

class Printer { // 功能是快速輸出
public:
	static const int length = 1 << 20;
	char buffer[length], *pointer, *end;

	Printer() {
		pointer = buffer, end = pointer + length - 1;
	}

	~Printer() {
		*pointer = '\0', printf("%s", buffer);
	}

	//template <class type>
	void PrintNumber(int number) {
		static char digits[20];
		int index = 0;
		*(digits + index) = '\n', ++index;
		if (!number)
			*(digits + index) = '0', ++index;
		while (number)
			*(digits + index) = (number % 10) + '0', ++index, number /= 10;
		while (index) {
			if (pointer == end)
				*pointer = '\0', printf("%s", buffer), pointer = buffer;
			--index, *pointer = *(digits + index), ++pointer;
		}
	}

	void PrintChar(char character) {
		if (pointer == end)
			*pointer = '\0', printf("%s", buffer), pointer = buffer;
		*pointer = character, ++pointer;
	}
	void PrintString(const string &s){
	    if(pointer+s.size()>end)
            *pointer = '\0', printf("%s", buffer), pointer = buffer;
        for(int i=0;i<s.size();i++)
            *pointer = s[i], ++pointer;
	}

} *printer = new Printer();

int arr[MAX],n,origin[MAX];
void modify(int pos,int x){
    int init_pos=pos;
    for(;pos<=n;pos+=pos&-pos){
        arr[pos]^=origin[init_pos];
        arr[pos]^=x;
    }
}
int query(int pos){
    int ans=0;
    for(;pos>0;pos-=pos&-pos)
        ans^=arr[pos];
    return ans;
}
int main() {
    int q;
    while(1){
        n=readint();
        if(error)
            break;
        q=readint();
        int temp;
        for(int i=1;i<=n;i++){
            temp=readint();
            modify(i,temp);
            origin[i]=temp;
        }
        bool cmd;
        int a,b;
        while(q--){
            cmd=readint(),a=readint(),b=readint();
            if(cmd){
                modify(a,b);
                origin[a]=b;
            }
            else printer->PrintNumber(query(a-1)^query(b));
        }
    }
    delete printer;
}
/*
BIT可以在O(logn)的時間內求出前綴和，這題只是把前綴和改成前綴xor而已，
所以稍稍修改BIT程式碼即可。最麻煩的是這題要做比較多的輸出入優化，不可以只用cin.tie(0),ios::sync_with_stdio(false)。
BIT的介紹可參考 https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-binary-indexed-tree
*/







