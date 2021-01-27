#include<bits/stdc++.h>
using namespace std;
const int range = 40009 ;
vector<int>prime ;

void find_prime()
{
   vector<bool>is_prime(range,true);
   
   for(int i = 2 ; i < range ; i++)
   {
       if(is_prime[i])
       {
            for(int j = i*i ; j < range ; j+=i)
                is_prime[j] = false ;    
       }
   }
   
   for(int i = 2 ; i < range ; i++)
   {
       if(is_prime[i])
        prime.push_back(i);
   }
}

int main()
{
    find_prime();
    int T ;
    cin>>T;
    while(T--)
    {
        int d ;
        cin>>d ;
        
        long long int A , B ;
        int idx = lower_bound(prime.begin() , prime.end() , 1+d) - prime.begin() ;
        A = prime[idx] ;
        idx = lower_bound(prime.begin() , prime.end() , A + d) - prime.begin() ;
        B = prime[idx] ;
        
        cout<<(A*B)<<endl;
    }
    
    return 0 ;
}

