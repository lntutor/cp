#include <iostream>

using namespace std;


int main() {
	char c;
	bool begin = 1;
	while (scanf("%c" , &c) != EOF){
		if (c == '"') {
			if (begin) {
				printf("``");
			} else {
				printf("''");
			}
			begin = !begin;
		} else {
			printf("%c", c);
		}
	}
	return 0;
}
