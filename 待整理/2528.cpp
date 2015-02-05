#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define N 20002

struct line
{
    int times;
    int left, right;

}lines[N * 6];

struct item
{
    int first;
    int last;
}temp[2 * N];

void create(int s, int t, int step)
{
    lines[step].left = s;
    lines[step].right = t;
    if(s == t)
        return ;
    int mid = ( lines[step].left + lines[step].right ) / 2;
    create(s, mid, step * 2);
    create(mid + 1, t, step * 2 + 1);
}

void update(int s, int t, int step, int i)
{
    if(t == lines[step].right && lines[step].left == s)
    {
        lines[step].times = i;
        return;
    }
    
    if(lines[step].times != 0 && lines[step].times != i)
    {
        lines[step * 2].times = lines[step].times;
        lines[step * 2 + 1].times = lines[step].times;
        lines[step].times = 0;
    }

    int mid = ( lines[step].left + lines[step].right) / 2;
    if(t <= mid)
    {
        update(s, t, step * 2, i);
    }
    else if(s > mid)
        update(s, t, step * 2 + 1, i);
    else 
    {
        update(s, mid, step * 2, i);
        update(mid + 1, t, step * 2 + 1, i);
    }
}
int k, result;
int re[N*6];
void cal(int num)
{
    if(lines[num].times)
    {

        if(re[lines[num].times] != 1)
        {
            re[lines[num].times] = 1;
            result++;
        }
        return ;
    }
    cal(2 * num );
    cal(2 * num + 1);
}

int cmp(const void *p, const void *q)
{
    line *a = (line *)p;
    line *b = (line *)q;
    return a->times < b->times ? 1 : -1;
}

int cmp2(const void *p, const void *q)
{
    return (((struct item *)p)->first - ((struct item *)q)->first);
}

int main()
{
    int i, j;
    int t, n;
    int l[N], r[N];
    struct item *x, *y, xx, yy;

//    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(temp, 0, sizeof(temp));
        for(i=1, k=0; i<=n; i++)
        {
            scanf("%d%d", &l[i], &r[i]);
            temp[++k].first = l[i];
            temp[++k].first = r[i];
        }

        /*离散化*/
        qsort(temp+1, n * 2, sizeof(temp[0]), cmp2);
        i=1;
        k=0;
        while(1)
        {
            if(i > n * 2)
                break;
            k++;
            temp[k].first = temp[i].first;
            temp[k].last = k;
            while(temp[i+1].first == temp[i].first)
                i++;
            i++;
        }
    
        memset(lines, 0, sizeof(lines));
        create(1, k, 1); //建树


        for(i=1; i<=n; i++)
        {
            xx.first = l[i];
            yy.first = r[i];
            x = (struct item *)bsearch(&xx, temp+1, k, sizeof(temp[1]), cmp2);
            y = (struct item *)bsearch(&yy, temp+1, k, sizeof(temp[1]), cmp2);
            update(x->last, y->last, 1, i); //更新

        }
        result = 0;
        memset(re, 0, sizeof(re));
        cal(1); //计数

        
        printf("%d\n", result);
    }
    getch();
    return 0;
}

