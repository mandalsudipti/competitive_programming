#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n ;
    cin>>n;
    int entry_car[n] , exit_car[n] , exit_pos[n] , i ;
    for(i=0;i<n;i++)
    {
        cin>>entry_car[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>exit_car[i];
        exit_pos[exit_car[i]]=i;
    }
    
    int in=n-1 , out = n-1 , fine=0;
    while(in>=0 && out>=0)
    {
        if(exit_car[out]==-1)
            out--;
        else if(entry_car[in]==exit_car[out])
        {
            in--;
            out--;
        }
        else
        {
            fine++;
            int loc = exit_pos[entry_car[in]];
            exit_car[loc]=-1;
            in--;
        }
    }
    cout<<fine;
    return 0;
}