#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int w , h , n ;
        cin>>w>>h>>n;
        
        long long int total = 1 , cur = 1 ;
        while(w%2 == 0 || h%2 == 0)
        {
            if(w%2 == 0)
            {
                total+=cur ;
                cur = cur * 2 ;
                w = w / 2 ;
            }
            if(h%2 == 0)
            {
                total+=cur;
                cur = cur*2 ;
                h = h/2 ;
            }
        }
        
        if(total >= n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}