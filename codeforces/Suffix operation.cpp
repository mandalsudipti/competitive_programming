#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        vector<long long int>save(n,0);
        save[0] = abs(arr[0] - arr[1]) ;
        save[n-1] = abs(arr[n-1] - arr[n-2]) ;
        
        if(n > 2)
        {
            for(int i=1;i<n-1;i++)
            {
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                    save[i] = 2*(arr[i] - max(arr[i-1],arr[i+1]));
                    
                else if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
                    save[i] = 2*(min(arr[i-1],arr[i+1]) - arr[i]);
            }
        }
        
        int max_save = 0  ;
        for(int i=0;i<n;i++)
        {
            if(save[max_save] < save[i])
                max_save = i ;
        }
        
        if(max_save == 0)
            arr[0] = arr[1] ;
        else
            arr[max_save] = arr[max_save - 1];
            
        long long int total_cost = 0 ;
        for(int i=1;i<n;i++)
            total_cost+=abs(arr[i] - arr[i-1]);
            
        cout<<total_cost<<endl;
    }
    
    return 0;
}