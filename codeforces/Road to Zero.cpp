#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int num1 , num2 , a , b , cost=0;
        cin>>num1>>num2>>a>>b;
        if(num2==0 && num1==0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            long long int minimum = min(num2,num1);
            cost+= (abs(num2-num1))*a + min(b*minimum,2*a*minimum);
            cout<<cost<<endl;
        }
    }
    return 0;
}

