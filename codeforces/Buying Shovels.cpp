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
        long long int min_package = n ;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(n/i<=k)
                {
                    min_package=i;
                    break;
                }
                else if(i<=k)
                    min_package = min(min_package,n/i);
            }
        }
        cout<<min_package<<endl;
    }
    return 0;
}