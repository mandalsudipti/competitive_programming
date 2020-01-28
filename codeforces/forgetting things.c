#include<stdio.h>

int main()
{
    int da,db;
    scanf("%d",&da);
    scanf("%d",&db);
    if(db-da==1)
    {
        printf("%d %d",da,da+1);
    }
    else if(db==da)
    {
        printf("%d %d",da*10,(da*10)+1);
    }
    else if(db<da && db==1 && da==9)
    {
        printf("9 10");
    }
    else
        printf("-1");
    return 0;
}
