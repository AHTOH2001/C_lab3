#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
#define err -2000123000
#define max 2147483646

double stod(char s[1000])
{
    int i = 0, o = false, f = false;
    double sm = 0, d = 1;
    if (s[0] == '-')
    {
        o = true;
        i++;
    }
    if (s[0] == '\0' || s[0] == '\n')
        return 0;
    while (s[i] != '\0' && s[i] != '\n')
    {
        if (f)
            d *= 10;
        if (s[i] >= '0' && s[i] <= '9')
            sm = sm * 10 + (s[i] - '0');
        else if (s[i] == '.' && !f)
            f = true;
        else
            return err;

        if (sm >= max / 100)
            return err;
        i++;
    }
    if (o == true)
        return -1 * sm / d;
    else
        return sm / d;
}

void myprint(int n, double **mas)
{
    int i, j;
    for (i = 0; i < n * 2 + 2; i++)
        printf("*");
    printf("*\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%.3lf\t", mas[i][j]);
        printf("| %.3lf\n", mas[i][n]);
    }
}
int problem2()
{
    int n = 0, i, j, k;
    char s[1000];
    double caef,*ans,**a;
    printf("A*X=B\n");
    printf("Enter N:");
    scanf("%s", s);
    n = stod(s);
    if (n >= 100 || n == err || n <= 0)
    {
        printf("error\n");
        return 0;
    }
    ans = (double *)malloc(n * sizeof(double));
    a = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
        a[i] = (double *)malloc((n + 1) * sizeof(double));
    printf("Enter square matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%s", s);
            a[i][j] = stod(s);
            if (abs(a[i][j]) >= 10000 || a[i][j] == err)
            {
                printf("error\n");
                return 0;
            }
        }
    printf("Enter column B\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        a[i][n] = stod(s);
        if (abs(a[i][n]) >= 10000 || a[i][j] == err)
        {
            printf("error\n");
            return 0;
        }
    }
    myprint(n, a);
    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            caef = a[i][k] / a[k][k];
            for (j = k; j < n + 1; j++)
                a[i][j] = a[i][j] - a[k][j] * caef;
        }
        myprint(n, a);
    }
    for (i = n - 1; i >= 0; i--)
    {
        double sum = a[i][n];
        for (j = n - 1; j > i; j--)
            sum -= a[i][j] * ans[j];
        ans[i] = sum / a[i][i];
    }
    for (i = 0; i < n; i++)
        printf("x%d = %.3lf\n", i + 1, ans[i]);

    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(ans);
    return 0;
}