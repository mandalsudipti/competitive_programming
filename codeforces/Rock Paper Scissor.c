#include<stdio.h>
#include<string.h>
int main()
{
    int T,N,a,b,c,alice[3],bob[3],extra[3],i,win,mark;
    char arr[100];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        memset(alice,0,3*sizeof(int));
        memset(bob,0,3*sizeof(int));
        memset(extra,0,3*sizeof(int));
        win=0;
        if(N%2==0)
            mark=N/2;
        else
            mark=N/2 +1;
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        alice[0]=a;
        alice[1]=b;
        alice[2]=c;
        scanf("%s",arr);
        for(i=0;i<N;i++)
        {
            if(arr[i]=='R')  bob[0]=bob[0]+1;
            else if(arr[i]=='P') bob[1]=bob[1]+1;
            else if(arr[i]=='S') bob[2]=bob[2]+1;
        }  
        if(bob[0]<=alice[1]) 
        {
            win+=bob[0];
            extra[1]+=alice[1]-bob[0];
        }
        else
            win+=alice[1];
        if(bob[1]<=alice[2])
        {
            win+=bob[1];
            extra[2]+=alice[2]-bob[1];
        }
        else
            win+=alice[2];
        if(bob[2]<=alice[0])
        {
            win+=bob[2];
            extra[0]+=alice[0]-bob[2];
        }
        else
            win+=alice[0];
        if(win<mark)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(i=0;i<N;i++)
            {
                if(arr[i]=='R')
                {
                    if(alice[1]>0)
                    {
                        printf("P");
                        alice[1]--;
                    }
                    else if(extra[2]>0)
                    {
                        printf("S");
                        alice[2]--;
                        extra[2]--;
                    }
                    else if(extra[0]>0)
                    {
                        printf("R");
                        alice[0]--;
                        extra[0]--;
                    }
                }
                
                else if(arr[i]=='P')
                {
                    if(alice[2]>0)
                    {
                        printf("S");
                        alice[2]--;
                    }
                    else if(extra[0]>0)
                    {
                        printf("R");
                        alice[0]--;
                        extra[0]--;
                    }
                    else if(extra[1]>0)
                    {
                        printf("P");
                        alice[1]--;
                        extra[1]--;
                    }
                }
                
                else if(arr[i]=='S')
                {
                    if(alice[0]>0)
                    {
                        printf("R");
                        alice[0]--;
                    }
                    else if(extra[1]>0)
                    {
                        printf("P");
                        alice[1]--;
                        extra[1]--;
                    }
                    else if(extra[2]>0)
                    {
                        printf("S");
                        alice[2]--;
                        extra[2]--;
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
