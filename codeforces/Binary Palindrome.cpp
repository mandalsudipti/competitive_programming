#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<string>arr(n) ;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i] ;
            
        int not_palindrome = 0 , avaiable = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            int cnt_zero = 0 , cnt_one = 0 ;
            for(char ch : arr[i])
                ch == '0' ? cnt_zero++ : cnt_one++ ;
                
            if(arr[i].length()%2)
               avaiable++ ;
            else
            {
                if(cnt_one%2)
                    not_palindrome++;
            }
        }
        
        if(not_palindrome%2 == 0)
            cout<<n<<endl;
        else 
        {
            if(avaiable > 0)
                cout<<n<<endl;
            else
                cout<<(n-1)<<endl;
        }
    }
    
    return 0 ;
}