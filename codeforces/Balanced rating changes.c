#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N, i,*arr,cnt,*ans;
    long long int even_sum=0 ,odd_sum=0;
    scanf("%d",&N);
    arr=(int*)malloc(N*sizeof(int));
    ans=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
        ans[i]=arr[i]/2;
        if(arr[i]%2==0)
            even_sum+=ans[i];
        else
         odd_sum+=ans[i];
    }
    cnt=even_sum + odd_sum; 
    if(cnt>0)  
    {
        for(i=0;i<N;i++)
        {
            if(cnt==0)  break;
            if(arr[i]%2!=0 && arr[i]<0)
            {
                ans[i]=ans[i]-1;
                cnt--;
            }
        }
    }
    
    if(cnt<0)
    {
        for(i=0;i<N;i++)
        {
            if(cnt==0)  break;
            if(arr[i]%2!=0 && arr[i]>0)
            {
                ans[i]=ans[i]+1;
                cnt++;
            }
        }
    }
    for(i=0;i<N;i++)
        printf("%d ",ans[i]);
}






