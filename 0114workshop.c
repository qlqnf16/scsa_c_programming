/*=======================
[1-3 변수와 입력, 1-4 기본연산자]
========================*/
// 1
#if 1
#include <stdio.h>

void main(void) {
    int radius;
    printf("반지름 : ");
    scanf("%d", &radius);
    printf("원의 넓이 : %d * %d * 3.14 = %.3f\n", radius, radius, radius*radius*3.14);
}
#endif

// 2
#if 0
#include <stdio.h>

void main(void) {
    int year, birthyear;
    scanf("%d %d", &year, &birthyear);
    printf("%d\n", year-birthyear+1);
}
#endif

// 3
#if 0
#include <stdio.h>

void main(void) {
    char lower;
    int i;
    for (i = 0; i < 2; i ++) {
        scanf("%c", &lower);
        fflush(stdin);
        printf("%c\n", lower-32);
    }
}
#endif

// 4
#if 0
#include <stdio.h>

void main(void) {
    int a, b, c, sum;
    scanf("%d %d %d", &a, &b, &c);
    sum = a+b+c;
    printf("sum= %d\navg= %f\n", sum, sum/3.0);
}
#endif

// 5
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void main(void) {
    char name[50], processor[50], odd;
    int hdd; double display;

    printf("제품명 : ");
    gets(name);
    printf("프로세서 : ");
    gets(processor);
    printf("HDD : ");
    scanf("%d", &hdd);
	fflush(stdin);
    printf("ODD 유무(y/n) : ");
    scanf("%c", &odd);
    fflush(stdin);
    printf("디스플레이 : ");
    scanf("%lf", &display);

    printf("%-20s%-20s%10s%10s%20s\n", "제품명", "프로세서", "HDD", "ODD", "디스플레이");
    printf("%-20s%-20s%10d%10c%20.1f\n", name, processor, hdd, odd, display);
}
#endif

// 6
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void main(void) {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%f, %f, %f, %f", a+b, a-b, a*b, a/b);
}

#endif

// 7
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void main(void) {
    int money;
    int apple = 1500;
    scanf("%d", &money);
    printf("%d %d\n", money/apple, money%apple);
}

#endif

// 8
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void main(void) {
    int fruits = 300;
    int apples;
    scanf("%d", &apples);
    printf("%d", apples*100/fruits);
}

#endif

// 9
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void main(void) {
    int num;
    scanf("%d", &num);
    printf("%d", num%2);
}

#endif

// 10
// (1) 3
// (2) 5
// (3) 0
// (4) 2
// (5) 2
//  (6) -40

// 11
// 출력결과: 6, 3, 3

/*=======================
[2-1. 함수의 기본]
========================*/
// 1
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

float getCircumference(int radius) {
    float pi = 3.14f;
    return radius*pi*2.0;
}

void main(void) {
    int radius;
	float circumference;
    scanf("%d", &radius);
    circumference = getCircumference(radius);
    printf("%.3f", circumference);
}

#endif

// 2
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int getAge(int birthYear, int currentYear) {
    return currentYear - birthYear + 1;
}

void main(void) {
    int birthYear, currentYear;
    scanf("%d %d", &birthYear, &currentYear);
    printf("%d\n", getAge(birthYear, currentYear));
}

#endif

// 3
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

float getAverage(int a, int b, int c) {
    int sum = a+b+c;
    return sum / 3.0;
}

void main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.2f\n", getAverage(a, b, c));
}

#endif

// 4
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int sumOfEveryDigit(int num) {
    int first = num / 100;
    int second = num % 100 / 10;
    int third = num % 10;
    return first + second + third;
}

void main(void) {
    int a;
    scanf("%d", &a);
    printf("%d\n", sumOfEveryDigit(a));
}

#endif

// 5
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int numOfOdds(int a, int b, int c){
    return a%2 + b%2 + c%2;
}

void main(void) {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", numOfOdds(a, b, c));
}

#endif

// 6
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

double getHeightSqr(double height){
    return height*height;
}

double calcFat(double height, double weight){
    double heightSqr = getHeightSqr(height);
    return weight / heightSqr;
}

void main(void) {
    double height, weight;
    double fatness;
    scanf("%lf %lf", &height, &weight);
    fatness = calcFat(height, weight);
    printf("%.2f", fatness);
}

#endif

// 7
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int calcPrice(int price, int dc){
	int temp = (price * ((100-dc)*0.01) / 10);
    return temp * 10 ;
}

void main(void) {
   int price, dc;
   scanf("%d %d", &price, &dc);
   printf("%d", calcPrice(price, dc));
}

#endif

// 8
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int getRandomNum(void){
    return (rand() % 10) + 1;
}

void main(void) {
    printf("%d\n", getRandomNum());
    printf("%d\n", getRandomNum());
    printf("%d\n", getRandomNum());
}

#endif

// 9
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

void main(void) {
    printf("1KB => %.fByte\n", pow(2.0, 10.0));
    printf("1MB => %.fByte\n", pow(2.0, 20.0));
    printf("1GB => %.fByte\n", pow(2.0, 30.0));
    printf("1TB => %.fByte\n", pow(2.0, 40.0));
}

#endif

// 10
#if 0
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "my.h"

void main(void) {
    char a;
    scanf("%c", &a);
    printf("%c\n", changeCase(a));
}

#endif