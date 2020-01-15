// 1
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int calcMax(int a, int b) {
    if (a > b) return a;
    else return b;
}

void main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", calcMax(a, b));
}

#endif

// 2
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void numComp(int a, int b){
    if (a < b) printf("%d < %d", a, b);
    else if (a > b) printf("%d > %d", a, b);
    else printf("%d == %d", a, b);
};

void main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
	numComp(a,b);
}

#endif

// 3

#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int numCount(int a){
    if (a <= 0) return 0;
    else if (a < 10) return 1;
    else if (a < 100) return 2;
    else return 3;
};

void main(void) {
    int a;
    scanf("%d", &a);
    printf("%d", numCount(a));
}

#endif

// 7
#if 0
void main(void){
	int a;
	scanf("%d", &a);
	printf("%s\n", a%2 ? "È¦¼ö" : "Â¦¼ö");
}

#endif

// 8
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int calcAbsolute(int num){
    if (num >= 0) return num;
    else return num * -1; 
};

void main(void) {
    int a;
    scanf("%d", &a);
    printf("%d", calcAbsolute(a));
}

#endif

// 9
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

char calcMultiple(int num){
    if (num % 3 == 0 && num % 5 == 0) return 'O';
    else return 'X';
};

void main(void) {
    int a;
    scanf("%d", &a);
    printf("%c", calcMultiple(a));
}

#endif

// 10
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int calcNum(int x, int y, char op) {
    int answer;
    switch (op) {
        case '+': answer = x + y; break;
        case '-': answer = x - y; break;
        case '*': answer = x * y; break;
        case '/': answer = x / y; break;
    }
    return answer;
}

void main(void) {
    int a, b;
    char op;
    scanf("%d %d %c", &a, &b, &op);
    printf("%d", calcNum(a, b, op));
}

#endif

// 11
#if 1
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

char checkWeight(int weight){
    if (weight < 0 || weight > 200) return 'X';
    if (weight < 50) return 'F';
    else if (weight < 60) return 'L';
    else if (weight < 70) return 'M';
    else return 'H';
}

void main(void) {
    int a; char result;
    scanf("%d", &a);
    result = checkWeight(a);
    if (result == 'X') printf("error\n");
    else printf("%c\n", result);
}

#endif