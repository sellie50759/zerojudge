#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
#define MAX 5000005
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
int arr[MAX];
bool isDie[MAX];
int find_root(int x){
    if(isDie[x]==false)
        return x;
    return arr[x]=find_root(arr[x]);
}
int main() {
    int n,q,pos;
    char cmd;
    while(1){
        n=readint();
        if(error)
            break;
        q=readint();
        for(int i=1;i<=n;i++)
            arr[i]=i;
        while(q--){
            cmd=readchar();
            readchar(); //讀掉空格
            pos=readint();
            readchar(); //讀掉題目多加的空格
            if(cmd=='-'){
                isDie[pos]=true;
                arr[pos]=pos+1;
                arr[pos]=find_root(pos);
            }
            else {
                int val=find_root(pos);
                if(val>n)
                    printer->PrintString("-1");
                else printer->PrintNumber(val);
            }
        }
    }
    delete printer;
}
/*
根據題目想出類似並查集路徑壓縮的作法，再加上io優化就可以解決了。
*/







