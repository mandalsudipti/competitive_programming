#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , tmp;
        cin>>n;
        tmp=n;
        int two=0 , odd_factor=0;
        while(n%2==0)
        {
            two++;
            n=n/2;
        }
        for(int i=3;i<=sqrt(n);i+=2)
        {
            while(n%i==0)
            {
                odd_factor++;
                n=n/i;
            }
        }
        if(n>2)
            odd_factor++;
        if(tmp==1)
            cout<<"FastestFinger"<<endl;
        else if(tmp==2)
            cout<<"Ashishgup"<<endl;
        else if(two>1 && odd_factor==0)
            cout<<"FastestFinger"<<endl;
        else
        {
            if((two>1 && odd_factor>0)||(two==0 && odd_factor>=1))
                cout<<"Ashishgup"<<endl;
            else if(two==1 && odd_factor>1)
                cout<<"Ashishgup"<<endl;
            else
                cout<<"FastestFinger"<<endl;
            
        }
    }
    return 0;
}

