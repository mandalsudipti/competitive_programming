#include<bits/stdc++.h>
using namespace std ;

void get_divisor(int num , map<int,int>& freq)
{
    for(int i = 1 ; i <= sqrt(num) ; i++)
    {
        if(num % i == 0)
        {
            freq[i]++ ;
            if(i != num/i)
                freq[num / i]++ ;
        }
    }
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n ;
        
        vector<long long int>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
        sort(arr.begin() , arr.end()) ;
        
        
        int k = 1 , required_freq = (n/2) - 1;
        for(int i = 0 ; i < n ; i++)
        {
            if(i > n/2)
                break;
            map<int,int>freq ;
            int equal = 1 ;
            for(int j = i+1 ; j < n ; j++)
            {
                if(arr[j] == arr[i])
                    equal++ ;
                else
                    get_divisor(arr[j] - arr[i] , freq) ;
            }
            if(equal >= n/2)
            {
                k = -1 ;
                break ;
            }
            for(pair<int,int>P : freq)
            {
                if(equal + P.second >= n/2)
                    k = max(k , P.first) ;
            }
        }
        
        cout<<k<<endl;
    }
    return 0 ;
}
