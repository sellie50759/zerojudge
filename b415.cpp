#include<iostream>
using namespace std;
typedef long long ll;
bool error=false;
inline char readchar() {
	const int S = 1e3; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
	//快速io
}
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
		*(digits + index) = ' ', ++index;
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

} *printer = new Printer();
int main(){
    ll n,x,m;
    while(1){
        x=readint();
        if(error)
            break;
        n=readint(),m=readint();
        while(m--){
            printer->PrintNumber(x);
            x=(x*x)%n;
        }
        printer->PrintChar('\n');
    }
    delete printer;
}



