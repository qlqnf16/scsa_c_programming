//1 [Data Structure] Queue #1
#if 0
#include <stdio.h>

#define MAX 5

int CIRQ[5];
int RP = 0, WP = 0;

int QUEUE(int d)
{
    // 코드설계
    if ((WP + 1) % MAX == RP) return -1;
    CIRQ[WP++] = d;
    WP %= MAX;
    return WP;
}

int DEQUEUE(int* p)
{
    // 코드설계
    if (WP == RP) return -1;
    *p = CIRQ[RP++];
    RP %= MAX;
    return RP;
}

/********************************************************************************/
/* 이부분은설계한코드의오류를확인하기위한테스트코드임가급적수정금지   */
/********************************************************************************/

int main(void)
{
    int i;
    int r;
    int d;

    int oper[] = { 1, 1, 1, 1, 1,  0, 0, 0, 0, 0,  1, 1, 1, 0, 0, 1, 1,  0 };
    int que[] = { 1, 3, 5, 7, 9,  1, 3, 5, 7, 0,  2, 4, 6, 2, 4, 8, 10, 6 };
    int res[] = { 1, 2, 3, 4, -1, 1, 2, 3, 4, -1, 0, 1, 2, 0, 1, 3, 4,  2 };

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        printf("TEST VECTOR [%d]\n", i);

        if (oper[i] == 1)
        {
            r = QUEUE(que[i]);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, YOur return => %d\n", res[i], r);
                return 0;
            }

            else
            {
                if ((r != -1) && (que[i] != CIRQ[(WP == 0) ? (4) : (WP - 1)]))
                {
                    printf(">>>>Fail: Expected QUEUE data => %d, Your QUEUE data => %d\n", que[i], CIRQ[(WP == 0) ? (4) : (WP - 1)]);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d, queue => %d\n", r, CIRQ[(WP == 0) ? (4) : (WP - 1)]);
                    else printf("return => %d\n", r);
                }
            }
        }

        else
        {
            r = DEQUEUE(&d);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, YOur return => %d\n", res[i], r);        return 0;
            }

            else
            {
                if ((r != -1) && (que[i] != d))
                {
                    printf(">>>>Fail: Expected DEQUEUE data => %d, Your DEQUEUE data => %d\n", que[i], d);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d, queue => %d\n", r, CIRQ[(WP == 0) ? (4) : (WP - 1)]);
                    else printf("return => %d\n", r);
                }
            }
        }
    }

    return 1;
}
#endif


//2 [Data Structure] Stack #2
#if 0
#include <stdio.h>
#define MAX_ST      3
#define STACK_FULL  -1
#define STACK_EMPTY MAX_ST

int STACK[4];
int SP = 3;

int PUSH(int d)
{
    // 코드설계
    if (SP == STACK_FULL) return 0xFF;
    STACK[SP--] = d;
    return SP;
}

int POP(int* p)
{
    // 코드설계
    if (SP == STACK_EMPTY) return 0xFF;
    *p = STACK[++SP];
    return SP;
}

// 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지 

int main(void)
{
    int i;
    int r;
    int d;

    int oper[] = { 1, 1, 1, 1, 1,    0, 0, 0, 0, 0,    1, 1, 1, 0, 0, 1, 1,  0 };
    int stk[] = { 1, 3, 5, 7, 9,     7, 5, 3, 1, 0,    2, 4, 6, 6, 4, 8, 10, 10 };
    int res[] = { 2, 1, 0, -1, 0xff, 0, 1, 2, 3, 0xFF, 2, 1, 0, 1, 2, 1, 0,  1 };

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        if (oper[i] == 1)
        {
            r = PUSH(stk[i]);

            if (r != res[i])
            {
                printf(">>>>Fail: Expected return => %d, Your return => %d\n", res[i], r);
                return 0;
            }

            if (r == 0xFF)
            {
                printf("return => 0x%.2X\n", r);
                continue;
            }

            if (STACK[SP + 1] != stk[i])
            {
                printf(">>>>Fail : Expected stack data => %d, Your stack data => %d\n", stk[i], STACK[SP + 1]);
                return 0;
            }

            printf("return => 0x%.2X\n", r);
            printf("PUSH => %d\n", STACK[SP + 1]);
        }

        else
        {
            r = POP(&d);

            if (r != res[i])
            {
                printf(">>>>Fail: Expected return => %d, Your return => %d\n", res[i], r);
                return 0;
            }

            if (r == 0xFF)
            {
                printf("return => 0x%.2X\n", r);
                continue;
            }

            if (d != stk[i])
            {
                printf(">>>>Fail: Expected POP data => %d, Your POP data => %d\n", stk[i], d);
                return 0;
            }

            printf("return => 0x%.2X\n", r);
            printf("POP => %d\n", d);
        }
    }

    return 1;
}

#endif


//3 [Data Structure] Linked List #1
#if 0

#include <stdio.h>
#include <malloc.h>

struct st
{
    int id;
    struct st* next;
}HEAD = { -1,NULL };

struct st* Insert(int d)
{
    struct st * head = &HEAD;
    struct st* p;
    // 코드설계
    for (;;) {
        if (!head->next || head->next->id > d) {
            p = calloc(1, sizeof(struct st));
            if (!p) return NULL;
            p->id = d;
            p->next = head->next;
            head->next = p;
            return p;
        }
        if (head->next->id == d) return NULL;
        head = head->next;
    }

}

struct st* Delete(int d)
{
    struct st* head = &HEAD;
    struct st* p;
    // 코드설계
    for (;;) {
        if (!head->next) return NULL;
        if (head->next->id == d) {
            p = head->next;
            head->next = head->next->next;
            return p;
        }
        head = head->next;
    }
}

// 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지  

int main(void)
{
#define R (void *)1
#define N (void *)NULL

    int i;
    int oper[] = { 0,  1, 1,  1, 1,  1,  1,  1, 1, 0,  0, 0,  0, 1, 0, };
    int data[] = { 7,  2, 1,  5, 4,  7,  9,  9, 8, 1,  9, 7,  7, 3, 2, };
    void* res[] = { N,  R, R,  R, R,  R,  R,  N, R, R,  R, R,  N, R, R, };
    int next[] = { -1, -1, 2, -1, 5, -1, -1, -1, 9, 2, -1, 8, -1, 4, 3, };
    struct st* r, * t;

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        printf("TEST VECTOR [%d]\n", i);

        if (oper[i] == 1)
        {
            r = Insert(data[i]);

            if (res[i] == NULL)
            {
                if (r != NULL)
                {
                    printf(">>>>Fail: Expected return => 0x%.8X, Your return=> 0x%.8X\n", res[i], r);
                    return 0;
                }

                else
                {
                    printf("return => 0x%.8X\n", r);
                }
            }

            else
            {
                t = &HEAD;
                printf("LINK : ");

                for (;;)
                {
                    if (t->next == NULL)
                    {
                        if (t->id == -1) printf("HEAD\n", t->id);
                        else printf("%d(LAST)\n", t->id);
                        break;
                    }

                    else
                    {
                        if (t->id == -1) printf("HEAD -> ", t->id);
                        else printf("%d -> ", t->id);
                        t = t->next;
                    }
                }

                if ((r->next == NULL) && (next[i] != -1))
                {
                    printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => NULL\n", next[i]);
                }

                else
                {
                    if ((r->next == NULL) && (next[i] == -1))
                    {
                        printf("id => %d, next => NULL\n", r->id);
                    }

                    else if (next[i] != r->next->id)
                    {
                        printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => %d\n ", next[i], r->next->id);
                        return 0;
                    }

                    else
                    {
                        printf("next link ID => %d\n", r->next->id);

                        if (r->id != data[i])
                        {
                            printf(">>>>Fail: Expected inserted ID => %d, Your inserted ID => %d\n", data[i], r->id);
                            return 0;
                        }

                        else
                        {
                            printf("inserted ID => %d\n", r->id);
                        }
                    }
                }
            }
        }

        else
        {
            r = Delete(data[i]);

            if (res[i] == NULL)
            {
                if (r != NULL)
                {
                    printf(">>>>Fail: Expected return => 0x%.8X, Your return=> 0x%.8X\n", res[i], r);
                    return 0;
                }

                else
                {
                    printf("return => 0x%.8X\n", r);
                }
            }

            else
            {
                t = &HEAD;
                printf("LINK : ");

                for (;;)
                {
                    if (t->next == NULL)
                    {
                        if (t->id == -1) printf("HEAD\n", t->id);
                        else printf("%d(LAST)\n", t->id);
                        break;
                    }

                    else
                    {
                        if (t->id == -1) printf("HEAD -> ", t->id);
                        else printf("%d -> ", t->id);
                        t = t->next;
                    }
                }

                if ((r->next == NULL) && (next[i] != -1))
                {
                    printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => NULL\n", next[i]);
                }

                else
                {
                    if ((r->next == NULL) && (next[i] == -1))
                    {
                        printf("id => %d, next => NULL\n", r->id);
                    }

                    else if (next[i] != r->next->id)
                    {
                        printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => %d\n", next[i], r->next->id);
                        return 0;
                    }

                    else
                    {
                        printf("next link ID => %d\n", r->next->id);

                        if (r->id != data[i])
                        {
                            printf(">>>>Fail: Expected deleted ID => %d, Your deleted ID => %d\n", data[i], r->id);
                            return 0;
                        }

                        else
                        {
                            printf("deleted ID => %d\n", r->id);
                            free(r);
                        }
                    }
                }
            }
        }
    }

    return 1;
}


#endif

//4 [Data Structure] Queue #2
#if 0
#include <stdio.h>

#include <malloc.h>

struct st
{
    int id;
    struct st* rp;
    struct st* wp;
};

struct st HEAD = { 0,NULL, NULL };
struct st TAIL = { 0,NULL, NULL };

struct st* QUEUE(int d)
{
    // 코드설계
    struct st* p;
    struct st* tail = &TAIL;
    
    p = calloc(1, sizeof(struct st));
    if (!p) return NULL;
    p->id = d;
    tail->wp->rp = p;
    p->rp = tail;
    p->wp = tail->wp;
    tail->wp = p;
    return p;
}


int DEQUEUE(int* p)
{
    // 코드설계
    struct st* temp;
    struct st* head = &HEAD;

    if (head->rp == &TAIL) return -1;
    *p = head->rp->id;
    temp = head->rp;
    head->rp->rp->wp = head;
    head->rp = head->rp->rp;
    return 0;
    //head->rp = head->rp->rp;


}


/********************************************************************************/

/* 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지   */

/********************************************************************************/

int main(void)
{
    int i;
    int d;

    struct st* r, * t;
    int p[1];
    int oper[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1, 0, 0, 1, 1,  0, 0, 0,  0 };
    int que[] = { 1, 3, 5, 7, 9,  1, 3, 5, 7, 9, 0,  2, 4, 6, 2, 4, 8, 10, 6, 8, 10, 0 };
    int ans[] = { 1, 3, 5, 7, 9,  0, 0, 0, 0, 0, -1, 2, 4, 6, 0, 0, 8, 10, 0, 0, 0,  -1 };

    HEAD.rp = &TAIL;
    TAIL.wp = &HEAD;

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        printf("\nTEST VECTOR [%d]\n", i);

        if (oper[i] == 1)
        {
            r = QUEUE(que[i]);

            t = HEAD.rp;

            while (t->rp != NULL)
            {
                printf("=> [%d]", t->id);
                t = t->rp;
            }

            printf("\n");

            t = TAIL.wp;

            while (t->wp != NULL)
            {
                printf("=> [%d]", t->id);
                t = t->wp;
            }

            printf("\n");

            if (r == NULL)
            {
                printf(">>>>틀림: 리턴된구조체의주소가NULL 포인터임\n");
                return 0;
            }

            if (r->id != ans[i])
            {
                printf(">>>>틀림: 리턴된구조체주소의id 예상값=> %d, 실제리턴된구조체의id 값=> %d\n", ans[i], r->id);
                return 0;
            }

            if (TAIL.wp != r)
            {
                printf(">>>>틀림: TAIL측wp 링크오류(TAIL의wp가리턴된자료주소가아님)\n");
                return 0;
            }

            if (r->rp != &TAIL)
            {
                printf(">>>>틀림: 리턴된자료의rp가TAIL의주소가아님)\n");
                return 0;
            }

            t = &HEAD;

            for (;;)
            {
                if (t->rp == &TAIL) break;
                else t = t->rp;
            }

            if ((t != r) || (t->id != r->id))
            {
                printf(">>>>틀림: HEAD측으로부터찾은TAIL 바로앞에있어야하는구조체주소와리턴된구조체주소가다름\n");
                return 0;
            }

            printf("OK\n");
        }


        else
        {
            d = DEQUEUE(p);

            t = HEAD.rp;

            while (t->rp != NULL)
            {
                printf("=> [%d]", t->id);
                t = t->rp;
            }

            printf("\n");

            t = TAIL.wp;

            while (t->wp != NULL)
            {
                printf("=> [%d]", t->id);
                t = t->wp;
            }

            printf("\n");

            if (d != ans[i])
            {
                printf(">>>>틀림: 예상리턴값= %d, 실제리턴값= %d\n", ans[i], d);
                return 0;
            }

            if (d != -1)
            {
                if (*p != que[i])
                {
                    printf(">>>>틀림: 큐에서꺼내서p 주소에들어있는데이터의예상값=> %d, 실제p 주소에들어있는값=> %d\n", que[i], *p);
                    return 0;
                }

                t = &HEAD;

                for (;;)
                {
                    if (t->rp == &TAIL) break;
                    else t = t->rp;
                }

                t = &TAIL;

                for (;;)
                {
                    if (t->wp == &HEAD) break;
                    else t = t->wp;
                }
            }

            printf("OK\n");
        }
    }

    return 1;
}

#endif

//5 [Data Structure] Hash Table #1
#if 0

#include <stdio.h>

#define STEP   2
#define HASH   5  

int Hash[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int Insert(int d)
{
    // 코드설계
    int start, key = d % 5;
    start = key;

    if (Hash[key] == -1) {
        Hash[key] = d;
        return key;
    }

    while (Hash[key] != -1) {
        key += STEP;
        if (key >= 9) key -= 9;
        if (Hash[key] == d) return -1;
        if (key == start) return -1;
    }

    Hash[key] = d;
    return key;
}

int Delete(int d)
{
    // 코드설계
    int start, key = d % 5;
    start = key;

    if (Hash[key] == d) {
        Hash[key] = -1;
        return key;
    }
    while (Hash[key] != d) {
        key += STEP;
        if (key >= 9) key -= 9;
        if (key == start) return -1;
    }
    Hash[key] = -1;
    return key;
}

/********************************************************************************/
/* 이 부분은 설계한 코드의 오류를 확인하기 위한 테스트 코드임 수정금지   */
/********************************************************************************/

int main(void)
{
    int i;
    int r;

    int oper[] = { 1, 1, 1, 1, 1, 1, 1,  1,  1,  1,   1, 0, 0,  1,  1 };
    int hash[] = { 2, 0, 5, 4, 7, 9, 9,  8,  15, 17, 21, 2, 31, 18, 50 };
    int res[] = { 2, 0, 4, 6, 8, 1, -1, 3,   5, 7,  -1, 2, -1, 2,  -1 };

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        printf("TEST VECTOR [%d]\n", i);

        if (oper[i] == 1)
        {
            r = Insert(hash[i]);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, Your return=> %d\n", res[i], r);
                return 0;
            }

            else
            {
                if ((r != -1) && (hash[i] != Hash[r]))
                {
                    printf(">>>>Fail: Expected HASH data => %d, Your HASH data => %d\n", hash[i], Hash[r]);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d, value => %d\n", r, Hash[r]);
                    else printf("return => %d\n", r);
                }
            }
        }

        else
        {
            r = Delete(hash[i]);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, Your return=> %d\n", res[i], r);
                return 0;
            }

            else
            {
                if ((r != -1) && (Hash[r] != -1))
                {
                    printf(">>>>Fail: Expected HASH data => %d, Your HASH data => %d\n", hash[i], Hash[r]);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d\n", r);
                    else printf("return => %d\n", r);
                }
            }
        }
    }

    return 1;
}
#endif

//6 [Data Structure] Linked List #2
#if 0
#include <stdio.h>

struct st
{
    int id;
    int next;
}data[5] = { {0, -1}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };

int Insert(int d)
{
    // 코드작성
    int saved = -1;
    struct st *head = &data[0];

    for (int i = 1; i < 5; i++) {
        if (data[i].id == d) return -1;
        if (data[i].id == 0) {
            data[i].id = d;
            saved = i;
            break;
        }
    }
    if (saved == -1) return -1;

    for (int i = 0; i < 4; i++) {
        if (head->next == -1 || data[head->next].id > d) {
            data[saved].next = head->next;
            head->next = saved;
            return saved;
        }
        head = &data[head->next];
    }
}

int Delete(int d)
{
    // 코드작성
    int target = -1;
    struct st* head = &data[0];

    for (int i = 1; i < 5; i++) {
        if (data[i].id == d) {
            target = i;
            break;
        }
    }
    if (target == -1) return -1;
    for (int i = 0; i < 4; i++) {
        if (head->next == -1) return -1;
        if (data[head->next].id == d) {
            data[head->next].id = 0;
            head->next = data[head->next].next;
            return target;
        }
        head = &data[head->next];
    }
    return target;
}

/********************************************************************************/
/* 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지*/
/********************************************************************************/

int main(void)
{
    int i;
    int r;

    int j;

    int oper[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,   1, 0 };
    int val[] = { 10, 5, 20, 5, 7, 8, 10, 20, 15, 80, 100, 20, 7 };
    int next[] = { -1, 1, -1, 0, 1, 0, 0, 0, 0, -1, -1,   0, 0 };
    int res[] = { 1, 2, 3, -1, 4, -1, 1, 3, -1, 1, 3,   -1, 4 };

    printf("ROOM-NO\tID\tNEXT\n");
    printf("---------------------\n");

    for (j = 0; j < 5; j++)
    {
        printf("%d\t%d\t%d\n", j, data[j].id, data[j].next);
    }

    printf("---------------------\n");

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        printf("TEST VECTOR [%d]\n", i);

        if (oper[i] == 1) r = Insert(val[i]);
        else r = Delete(val[i]);

        printf("ROOM-NO\tID\tNEXT\n");
        printf("---------------------\n");

        for (j = 0; j < 5; j++)
        {
            printf("%d\t%d\t%d\n", j, data[j].id, data[j].next);
        }

        printf("---------------------\n");

        if (res[i] != r)
        {
            printf(">>>>Fail: Expected Return=> %d, Your Return=> %d\n", res[i], r);
            return 0;
        }

        else
        {
            if (r == -1)
            {
                printf("return => %d\n", r);
            }

            else
            {
                printf("return => %d\n", r);

                if ((val[i] != data[r].id) && (oper[i] == 1))
                {
                    printf(">>>>Fail: Expected Saved ID => %d, Your ID => %d\n", val[i], data[r].id);
                    return 0;
                }

                else
                {
                    if (oper[i] == 1)
                    {
                        printf("id => %d\n", data[r].id);
                    }

                    else
                    {
                        printf("id => %d\n", data[r].id);
                    }


                    if (oper[i] == 1)
                    {
                        if (next[i] != data[r].next)
                        {
                            printf(">>>>Fail: Expected next => %d, Your next => %d\n", next[i], data[r].next);
                            return 0;
                        }

                        else
                        {
                            printf("next => %d\n", data[r].next);
                        }
                    }
                }
            }
        }
    }

    return 1;
}
#endif
