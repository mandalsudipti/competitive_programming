#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        long long int min_step = INT_MAX ;
        for(int i=1;i<=sqrt(n)+1;i++)
        {
            long long int cur_step = i-1;
            cur_step+=((n/i)+(n%i!=0)-1);
            min_step = min(min_step,cur_step);
        }
        
        cout<<min_step<<endl;
    }
    
    return 0 ;
}
