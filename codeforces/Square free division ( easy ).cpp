#include<bits/stdc++.h>
using namespace std;

const int range  = 1e7 + 5 ;

void get_spf(vector<int>& spf)
{
    for(int i = 1 ; i < range ; i++)
        spf[i] = i ;
    for(int i = 4 ; i < range ; i+=2)
        spf[i] = 2 ;
        
    for(int i = 3 ; i*i < range ; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i*i ; j < range ; j+=i)
            {
                if(spf[j] == j)
                    spf[j] = i ;
            }
        }
    }
}

void factorization(vector<int>& factor , vector<int>& spf)
{
    factor[1] = 1 ;
    factor[2] = 2 ;
    factor[3] = 3 ;
   for(int i = 4 ; i < range ; i++)
   {
        int x = i/spf[i] ; 
        if(factor[x]%spf[i] != 0)
            factor[i] = factor[x] * spf[i] ;
        else
            factor[i] = factor[x] / spf[i] ;
        //cout<<i<<" "<<x<<" "<<factor[i]<<endl;
   }
}

int main()
{
   vector<int>spf(range) ; // smallest prime factor
   get_spf(spf);
   
   
   vector<int>factor(range); // factor which are not in square form
   factorization(factor , spf) ;
   
   int T ;
   cin>>T;
   
   while(T--)
   {
       int n , k  ;
       cin>>n>>k ;
       
       vector<int>arr(n);
       for(int i = 0 ; i < n ; i++)
       {
           cin>>arr[i] ;
           arr[i] = factor[arr[i]];
       }
       
       set<int>segment ;
       int count = 1 ;
       
       for(int i = 0 ; i < n ; i++)
       {
            if(segment.find(arr[i]) == segment.end())
                segment.insert(arr[i]);
            else
            {
                count++;
                segment.clear();
                segment.insert(arr[i]);
            }
       }
       
       cout<<count<<endl;
   }
   
   return 0;
}

