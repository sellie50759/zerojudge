#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<list>
#pragma GCC optimize("O3")
using namespace std;
typedef unsigned long long ull;
inline char readchar() {
	const int S = 1e3; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
	//快速io
}
bool error=false;
long long int readint(){
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

class Printer {
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
int main(){
    int n,m;
    n=readint(),m=readint();
    vector<int> ivec;//紀錄第i-1個人之後的人
    bool died[n];
    memset(died,false,sizeof(died));
    ivec.reserve(n+1);
    for(int i=1;i<=n-1;i++)
        ivec.push_back(i+1);
    ivec.push_back(-1);//-1代表後面沒有人了
    while(m--){
        int temp;
        temp=readint();
        temp--;
        if(died[temp]||ivec[temp]==-1)
            printer->PrintString("0u0 ...... ?\n");
        else {
            printer->PrintNumber(ivec[temp]);
            died[ivec[temp]-1]=true;
            ivec[temp]=ivec[ivec[temp]-1];//每殺掉一個人就把被殺掉的那個人的後面那個人指定給現在這個人
        }
    }
    delete printer;

}
