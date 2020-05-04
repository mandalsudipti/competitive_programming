#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k , m , t;
    cin>>n>>k>>m>>t;
    while(t--)
    {
        int x , i ;
        cin>>x>>i;
        if(x==0)
        {
            if(k<=i)
            {
                n=i;
            }
            else
            {
                n=n-i;
                k=k-i;
            }
        }
        else if(x==1)
        {
            if(i<=k)
                k++;
            n++;
        }
        cout<<n<<" "<<k<<endl;
    }
    return 0;
}