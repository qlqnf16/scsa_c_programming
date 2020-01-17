// 1
#if 0
void main(void){
    int x, y, i, sum = 0;
    scanf("%d %d", &x, &y);
    for (i = x; i <= y; i ++) {
        if (i%2 == 0) sum += i;
    }
    printf("%d", sum);
}
#endif

// 2
#if 0
void main(void){
    int i, j;
    for (i = 0; i < 100; i += 10) {
        for (j = 1; j  <= 10; j ++) {
            printf("%4d", i+j);
        }
        printf("\n");
    }
}
#endif

// 3
#if 0
void main(void){\
    int i, j;
    for (i = 0; i < 26; i ++) {
        for (j = 0; j < 26; j ++) {
            if (i + j >= 26) 
            printf("%c", 'A'+i+j-26);
            else
            printf("%c", 'A'+i+j);
        }
        printf("\n");
    }
}
#endif

// 4
#if 0
void main(void){
    int i, j,  k;
    for (i = 1; i <= 6; i ++) {
        for (j = 1; j < 6; j ++) {
            for (k = 1; k < 6; k ++) {
                printf("%d %d %d", i, j, k);
            }
            printf("\n");
        }
    }
}
#endif

// 5
#if 0
void main(void){
    int n, sum = 0, i = 1;
    scanf("%d", &n);
    while (i < n) {
        sum += n / i % 10;
        i *= 10;
    }
	printf("%d", sum);
}
#endif

// 6
#if 0
void main(void){
    int i, j, k;
    for (k = 0; k < 3; k ++) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j ++) {
                if (k == 0) {
                    if (j <= i)
                    printf("*");
                }
                else if (k == 1) {
                    if (j < 4-i) printf(" ");
                    else printf("*");
                }
                else {
                    if (j < i) printf(" ");
                    else printf("*");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}
#endif

// 7
#if 0
void main(void){
    int n, sum = 0;
    for (n = 3; sum < 1000; n += 3) {
        sum += n;
    }
    printf("%d\n", n);
}
#endif

// 8
#if 0
void main(void){
    int i = 1, j = 1, sum = 0, n;
    scanf("%d", &n);
    while (j <= n) {
        sum += i;
		 j += 1;
		 i *= j;
    }
    printf("%d", sum);
}
#endif

// 9
#if 0
#include <stdio.h>

int notPrime[1000001] = {0};

int isPrime(int num){
    if (notPrime[num]) return 0;
    else return 1;
}

void main(void){
    int i, j, test, n, t;
    notPrime[1] = 1;
    for (i = 2; i <= 1000000; i ++) {
        for (j = 2; j <= 1000000; j++) {
            if (i*j > 1000000) break;
            notPrime[i*j] = 1;
        } 
    }

    scanf("%d", &test);
    for (t = 0; t < test; t ++) {
        scanf("%d", &n);
        if(isPrime(n)) printf("YES\n");
        else printf("NO\n");
    }
}
#endif

// 10
#if 0
#include <stdio.h>

void printAliquot(int num) {
    int i;
    for (i = 1; i <= num; i ++) {
        if (num % i == 0) printf("%d ", i);
    }
    printf("\n");
}

void main(void){
    int t, n;
    scanf("%d", &n);
    for (t = 2; t<=n; t++) {
        printAliquot(t);
    }
}
#endif

// 11
#if 0
#include <stdio.h>

int countAliquot(int num) {
    int i, count=0;
    for (i = 1; i < num; i ++) {
        if (num % i == 0) count ++;
    }
    return count;
}

void main(void){
    int t, n, m, max = 0, count, maxNum;
    scanf("%d %d", &n, &m);
    for (t = m; t >= n; t --) {
        count = countAliquot(t);
        if (count >= max) {
            max = count;
            maxNum = t;
        }
    }
    printf("%d", maxNum);
}
#endif

// 12
#if 1
#include <stdio.h>
int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

void main(void){
    int year, month, day, i, totalDays = 0;
    scanf("%d %d %d", &year, &month, &day);
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100)))
        days[2] += 1;

    for (i = 1; i < month; i ++) {
        totalDays += days[i];
    }
    totalDays += day;
    printf("%d", totalDays);

}
#endif

