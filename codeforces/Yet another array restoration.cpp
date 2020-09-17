#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , x , y ;
        cin>>n>>x>>y;
        
        long long int maximum = y ;
        long long int diff ;
        bool flag = true ;
        while(flag)
        {
            diff = maximum - x ;
            /*if(maximum - diff*(n-1)>0 && (maximum - x)/diff <= (n-1))
            {
                flag = false;
                break;
            }*/
            
            for(int i=1;i<=sqrt(diff);i++)
            {
                if(diff%i==0 && maximum - i*(n-1)>0&& (maximum - x)%i==0 && (maximum - y)%i==0 && (maximum - x)/i <= (n-1) && (maximum - y)/i<=(n-1))
                {
                    diff = i ;
                    flag = false;
                    break;
                }
                else if(diff%(diff/i)==0 && maximum-(diff/i)*(n-1)>0 && (maximum-x)%(diff/i)==0 && (maximum-y)%(diff/i)==0 && (maximum-x)/(diff/i)<=(n-1) && (maximum-y)/(diff/i)<=(n-1))
                {
                    diff = diff/i ;
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
                
            maximum++;
        }
        
        cout<<maximum<<" ";
        for(int i=1;i<=(n-1);i++)
            cout<<maximum - (i*diff)<<" ";
        cout<<endl;
    }
    
    return 0;
}