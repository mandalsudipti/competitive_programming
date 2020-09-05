#include<bits/stdc++.h>
using namespace std;

const long long int MOD = 998244353;
const int MAX_COL = 1002 ;
const int BB = 0 , WW = 1 , BW = 2 , WB = 3 ;
long long int no_of_ways[MAX_COL][2*MAX_COL][4] ;

int get_val(int second_last , int last)
{
    switch(second_last)
    {
        case BB:
        {
            switch(last)
            {
                case BB : return 0;
                case WW : return 1;
                case WB : return 1;
                case BW : return 1;
            }
        }
        case WW:
        {
            switch(last)
            {
                case WW : return 0;
                case BB : return 1;
                case BW : return 1;
                case WB : return 1;
            }
        }
        case WB:
        {
            switch(last)
            {
                case WW: return 0;
                case BB: return 0;
                case WB: return 0;
                case BW: return 2;
            }
        }
        case BW:
        {
            switch(last)
            {
                case WB: return 2;
                case WW: return 0;
                case BB: return 0;
                case BW: return 0;
            }
        }
    }
}

int main()
{
   int n , k ;
   cin>>n>>k;
   
   memset(no_of_ways,0,sizeof(no_of_ways));
   
   no_of_ways[1][1][BB] = no_of_ways[1][1][WW] = 1 ;
   no_of_ways[1][2][WB] = no_of_ways[1][2][BW] = 1 ;
   
   for(int col=2;col<=n;col++)
   {
       for(int component = 1 ; component<=2*col ; component++)
       {
           for(int last=0 ; last<4 ; last++)
           {
               for(int second_last = 0 ; second_last<4 ; second_last++)
               {
                   long long int new_component = component + get_val(second_last,last);
                   no_of_ways[col][new_component][last]+=no_of_ways[col - 1][component][second_last] ;
                   no_of_ways[col][new_component][last]%=MOD;
               }
           }
       }
   }
   
   long long int ans = no_of_ways[n][k][BB] + no_of_ways[n][k][WW] + no_of_ways[n][k][WB] + no_of_ways[n][k][BW] ;
   
   cout<<(ans%MOD);
   
   return 0;
}