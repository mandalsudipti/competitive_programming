#include<bits/stdc++.h>
using namespace std;

int find_left(int arr[],int n , int num , int freq)
{
    for(int i=0;i<n;i++)
    {
        if(freq==0)
            return (i-1);
        if(arr[i]==num)
            freq--;
    }
    return n-1;
}

int find_right(int arr[],int n,int num,int freq)
{
    for(int i=n-1;i>=0;i--)
    {
        if(freq==0)
            return (i+1);
        if(arr[i]==num)
            freq--;
    }
    return 0;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int arr[n];
        vector<vector<int>>freq_so_far(n,vector<int>(27,0));
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            for(int j=1;j<=26;j++)
            {
                if(i>0)
                    freq_so_far[i][j]=freq_so_far[i-1][j];
            }
            freq_so_far[i][arr[i]]++;
        }
        int maximum_len=1;
        for(int j=1;j<=26;j++)
        {
            if(freq_so_far[n-1][j]>=2)
            {
                int len=freq_so_far[n-1][j]/2 , left , right , cnt=0 ;
                left = find_left(arr,n,j,len);
                right = find_right(arr,n,j,len);
                while(len>=1)
                {
                    int maximum = 0 ;
                    for(int x=1;x<=26;x++)
                    {
                        maximum = max(maximum , freq_so_far[right-1][x]- freq_so_far[left][x]);
                    }
                    
                    maximum_len = max(maximum_len , len*2+maximum);
                    if(len>1)
                    {
                        for(int x=left-1;x>=0;x--)
                        {
                            if(arr[x]==j)
                            {
                                left=x;
                                break;
                            }
                        }
                        for(int x=right+1;x<n;x++)
                        {
                            if(arr[x]==j)
                            {
                                right=x;
                                break;
                            }
                        }
                    }
                    len--;
                    
                }
            }
        }
        cout<<maximum_len<<endl;
    }
    return 0;
}