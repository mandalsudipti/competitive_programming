#include<bits/stdc++.h>
using namespace std ;
const long long int mod = 1e9 + 7 ;
int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int plane ,  k ;
        cin>>plane>>k ;
        
        vector<vector<long long int>>left(k+1 , vector<long long int>(plane+1,0));
        vector<vector<long long int>>right(k+1 , vector<long long int>(plane+1,0));
        
        vector<vector<long long int>>left_prefix(k+1 , vector<long long int>(plane+1,0));
        vector<vector<long long int>>right_prefix(k+1 , vector<long long int>(plane+1,0));
        
        
        for(int i = 1 ; i <= k ; i++)
        {
            for(int j = 1 ; j <= plane ; j++)
            {
                if(i == 1)
                {
                    left[i][j] = 1 ;
                    right[i][j] = 1 ;
                }
                else
                {
                    if(j - 1 == 0)
                        left[i][j] = (1 + 1 + right_prefix[i-1][plane-1])%mod ;
                    else
                        left[i][j]=(1+(right_prefix[i-1][plane-1]-(j-2 >= 1 ? right_prefix[i-1][j-2] : 0)+mod)%mod)%mod ;
                        
                        
                    if(j + 1 == plane + 1)
                        right[i][j] = (1 + 1 + (left_prefix[i-1][j] - left_prefix[i-1][1] + mod)%mod)%mod ;
                    else
                        right[i][j] = (1 + (left_prefix[i-1][j+1] - left_prefix[i-1][1] + mod)%mod)%mod ;
                }
            }
            
            for(int j = 1 ; j <= plane ; j++)
            {
                left_prefix[i][j] = left[i][j] ;
                right_prefix[i][j] = right[i][j] ;
                
                if(j > 1)
                {
                    left_prefix[i][j]+=left_prefix[i][j-1] ;
                    right_prefix[i][j]+=right_prefix[i][j-1] ;
                }
                left_prefix[i][j]%=mod ;
                right_prefix[i][j]%=mod ;
            }
        }
        
        
        cout<<left[k][1]%mod<<endl;
    }
    
    return 0 ;
}