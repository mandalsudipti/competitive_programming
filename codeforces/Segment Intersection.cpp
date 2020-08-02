#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k ;
        cin>>n>>k;
        
        long long int l1 , r1 , l2 , r2 ;
        cin>>l1>>r1>>l2>>r2;
        if(l1>l2)
        {
            swap(l1,l2);
            swap(r1,r2);
        }
        long long int max_overlap = max(r1,r2) - min(l1,l2)  , initial_cost = 0 , initial_overlap = 0 ,  total_cost = 0;
        if(l2>=l1 && l2<=r1)
        {
            initial_overlap = min(r2-l2 , r1-l2) ;
        }
        else
            initial_cost = (l2-r1) ;
            
        k-=initial_overlap*n;
        if(k<=0)
        {
            cout<<"0"<<endl;
            continue;
        }
        max_overlap-= initial_overlap ;
        total_cost += initial_cost + min(k,max_overlap);
        k-=min(k,max_overlap);
        n--;
        while(k>0 && n>0)
        {
            long long int tmp = initial_cost + min(k,max_overlap) ;
            if(tmp<min(k,max_overlap)*2)
            {
                n--;
                total_cost+=tmp;
            }
            else
                break;
            k-=min(k,max_overlap);
        }
        if(k>=0)
            total_cost+=(k*2);
        cout<<total_cost<<endl;
    }
    
    return 0;
}