#include<bits/stdc++.h>
using namespace std;

const int HILL = 1 , VALLEY = 2 ;

bool check(int left , int mid , int right , vector<int>&arr)
{
    int n = arr.size() ;
    if(left < 0 || left >= n || right < 0 || right >= n || mid < 0 || mid >= n )
        return false;
        
    if((arr[mid] > arr[left] && arr[mid] > arr[right])|| (arr[mid] < arr[left] && arr[mid] < arr[right]))
        return true;
    else
        return false;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        int cnt = 0 ;
        vector<int>slope_change(n,0);
        for(int i = 1 ; i < n-1 ; i++)
        {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) 
            {
                cnt++;
                slope_change[i] = HILL ;
            }
            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
            {
                cnt++;
                slope_change[i] = VALLEY ;
            }
        }
        
        int minimum = cnt ;
        for(int i = 0 ; i < n ; i++)
        {
            if(slope_change[i] == HILL || slope_change[i] == VALLEY)
            {
                if(slope_change[i-1] == 0 && slope_change[i+1] == 0)
                    minimum = min(minimum , cnt - 1);
                else if(slope_change[i-1] == slope_change[i+1])
                {
                    minimum = min( minimum , cnt - 2);
                    if(slope_change[i-1] == HILL && ((arr[i-1] <= arr[i+1]) || (arr[i+1] <= arr[i-1])) )
                        minimum = min( minimum , cnt - 3);
                    else if(slope_change[i-1] == VALLEY && ((arr[i-1] >= arr[i+1]) || (arr[i+1] >= arr[i-1])) )
                        minimum = min( minimum , cnt - 3);
                }
                else if(slope_change[i-1]!=0 || slope_change[i+1]!=0)
                {
                    if(slope_change[i-1]!=0 && !check(i-1,i+1,i+2,arr) && !check(i-1,i+1,i+2,arr))
                        minimum = min( minimum , cnt - 2);
                    if(slope_change[i+1]!=0 && !check(i-2,i-1,i+1,arr) && !check(i-2,i-1,i+1,arr))
                        minimum = min( minimum , cnt - 2) ;
                    minimum = min( minimum , cnt - 1);
                }
            }
        }
        
        cout<<minimum<<endl;
    }
    
    return 0;
}


