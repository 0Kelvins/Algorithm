#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct player
{
    char name[50];
    int m;
    int s;
};
int cmp(player a, player b)
{
    if (a.m != b.m)
        return a.m < b.m;
    else if (a.s != b.s)
        return a.s < b.s;
    return strcmp(a.name, b.name) < 0;
}
int main()
{
    int n, i, t, k = 1;
    player p[11];

    // freopen("HDU-2115/in.txt", "r", stdin);
    // freopen("HDU-2115/out.txt", "w", stdout);

    while (scanf("%d", &n) != EOF && n != 0)
    {
        if (k > 1)
            printf("\n");
        for (i = 0; i < n; i++)
            scanf("%s %d:%d", p[i].name, &p[i].m, &p[i].s);
        sort(p, p + n, cmp);
        t = 1;
        printf("Case #%d\n%s %d\n", k++, p[0].name, t);
        for (i = 1; i < n; i++)
        {
            printf("%s ", p[i].name);
            if (p[i].m == p[i - 1].m && p[i].s == p[i - 1].s) {
                printf("%d", t);
            }
            else
            {
                t = i + 1;
                printf("%d", t);
            }
            if (i < n)
                printf("\n");
        }
    }
    
    return 0;
}