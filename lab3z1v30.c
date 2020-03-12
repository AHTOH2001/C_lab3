#include <stdio.h>
int problem1()
{
    int i,ans=0;
    for (i = 0;i<=9999999;i++)
        if (i%10+i/10%10+i/100%10==i/1000%10+i/10000%10+i/100000%10) ans++;
    
    printf ("%d",ans);
    return 0;
}