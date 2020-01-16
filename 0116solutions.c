// 1
#if 0
void main(void){
    int n;
    scanf("%d", &n);
	printf("%d", (n%2) ? n/2+1: n/2);
}
#endif


// 2
#if 0
void main(void){
    long long n, i, sum = 0;
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        if (i % 2) sum += i;
    }
	printf("%lld", sum);
}
#endif


// 3
#if 0
void main(void){
    long long n, i, sum = 0;
    scanf("%lld", &n);
    for (i = n; i >= 1; i--) {
        if (i % 2) printf("%lld ", i);
    }
}
#endif

// 4
#if 0
void main(void){
    long long n, i, count = 0;
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("%lld ", i);
            count ++;
        }
    }
	printf("\n%d\n", count);
}
#endif

// 5
#if 0
void main(void){
    int i, j=0;
    for (i = 1; i < 99; i++) {
        if (i%2) {
            printf("%2d ", i);
            j ++;
        }
        if (j == 15) {
            printf("\n");
            j = 0;
        }
        
    }
}
#endif

// 6
#if 0
void main(void){
    int i, j;
    for (i = 1; i < 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}
#endif


// 7
#if 0
void main(void){
    int i, j;
    for (i = 1; i < 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%9d", j);
        }
        printf("\n");
    }
}
#endif

// 8
#if 0
void main(void){
    int i, j;
    for (i = 0; i < 26; i++) {
        for (j = 0; j <= i; j++) {
            printf("%c", j+'A');
        }
        printf("\n");
    }
}
#endif

// 9
#if 0
void main(void){
    int i, j;
    for (i = 1; i < 10; i++) {
        for (j = 2; j < 10; j++) {
            printf("%2d*%2d=%2d", j, i, j*i);
        }
        printf("\n");
    }
}
#endif

// 10
#if 0
void main(void){
    int i, j;
    for (i = 1; i < 7; i++) {
        for (j = 1; j < 7; j++) {
            printf("%d %d\n", i, j);
        }
    }
}
#endif

// 11
#if 0
void main(void){
    int n, sum = 0, i = 1;
    scanf("%d", &n);
    while (sum < n) {
        sum += i;
        i ++;
    }
    printf("%d", i-1);
}
#endif

// 12
#if 1
void main(void){
    int n, i = 1;
    scanf("%d", &n);
    while (i <= n) {
        printf("%d", n / i % 10);
        i *= 10;
    }
}
#endif

