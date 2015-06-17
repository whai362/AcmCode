/*
   by whai
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
int arr[200009];
int left_m[200009], right_m[200009];
int ans[200009];
int stack[200009], stop;
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    arr[0] = arr[N + 1] = -1;
    //left
    stop = 0;
    stack[++stop] = 0;
    for (int i = 1; i <= N; i++)
    {
        while (arr[i] <= arr[stack[stop]])
            stop --;
        left_m[i] = stack[stop];
        stack[++stop] = i;
    }
    //right
    stop = 0;
    stack[++stop] = N + 1;
    for (int i = N; i >= 1; i--)
    {
        while (arr[i] <= arr[stack[stop]])
            stop --;
        right_m[i] = stack[stop];
        stack[++stop] = i;
    }
    //ans
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= N; i++)
    {
        int len = right_m[i] - left_m[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }
    for (int i = N - 1; i >= 1; i--)
        if (ans[i] == 0 ||  ans[i] < ans[i + 1])
            ans[i] = ans[i + 1];
    for (int i = 1; i <= N; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
