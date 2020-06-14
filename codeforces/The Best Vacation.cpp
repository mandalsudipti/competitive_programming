#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , x ;
    cin>>n>>x;
    vector<long long int>days(2*n+5,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>days[i];
        days[n+i] = days[i];
    }
    
    long long int maximum_so_far = 0 ,cur=0 , my_days = 0 , start_month = 0 , start_day = 1;
    for(int i=0;i<2*n;i++)
    {
       my_days +=days[i] ;
       long long int tmp = cur + (days[i]*(days[i]+1))/2 ;
       
       while(my_days>x)
       {
           long long int y = days[start_month] - start_day + 1;
           //cout<<tmp<<" "<<my_days<<" "<<y<<endl;
           if(my_days-y>=x)
           {
               my_days-=y;
               tmp -= ( (days[start_month]*(days[start_month]+1))/2 - (start_day*(start_day-1))/2 ) ;
               start_month++;
               start_day = 1;
           }
           else
           {
              y = my_days - x ;
              my_days = x ;
              tmp -= ( (start_day+y-1)*(start_day+y) )/2 - (start_day*(start_day - 1))/2 ;
              start_day = start_day + y ;
              break;
           }
       }
       cur = tmp ;
       maximum_so_far = max(maximum_so_far , cur) ;
    }
    cout<<maximum_so_far<<endl;
    
    return 0;
}
