#include<bits/stdc++.h>
using namespace std;

const int range  = 1e7 + 5 ;
vector<int>freq(range , 0) ;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
       
       vector<int>arr(n+1);
       
       for(int i = 1 ; i <= n ; i++)
       {
           cin>>arr[i] ;
           arr[i] = factor[arr[i]];
       }
       
       
       vector <vector <int> > best_left(n + 1, vector <int> (k + 1));
        for(int change = 0; change <= k; change++)
        {
            int left = n + 1, right = n , duplicates = 0;

            while(right >= 1)
            {
                while(left > 1)
                {
                    if(duplicates == change && freq[arr[left - 1]] > 0)
                        break;

                    if(freq[arr[left - 1]] > 0)
                        duplicates++;

                    freq[arr[left - 1]]++;
                    left--;
                }

                best_left[right][change] = left; 

                if(freq[arr[right]] > 1)
                    duplicates--;
                freq[arr[right]]--;
                right--;
            }
        }

        vector <vector <int> > minimum_segments(n + 1, vector <int> (k + 1, range));
        for(int i = 1; i <= n ; i++)
        {
            for(int changes = 0; changes <= k; changes++)
            {
                if(changes > 0)
                    minimum_segments[i][changes] = minimum_segments[i][changes - 1];
            

                for(int last_changes = 0; last_changes <= changes; last_changes++)
                {
                    int left = best_left[i][last_changes];
        
                    if(left == 1)
                    {
                        minimum_segments[i][changes] = 1;
                        continue;
                    }

                    minimum_segments[i][changes] = min(minimum_segments[i][changes],minimum_segments[left - 1][changes - last_changes] + 1);

                }
            }
        }

        cout << minimum_segments[n][k] <<endl;
       
   }
   
   return 0;
}



