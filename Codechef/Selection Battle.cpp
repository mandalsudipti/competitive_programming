#include<bits/stdc++.h>
using namespace std;

bool is_prime(int N)
{
   if(N==2)
        return true;
   if(N%2==0)
        return false;
    for(int i=3;i<=sqrt(N);i+=2)
    {
        if(N%i==0)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        if(is_prime(N))
            cout<<"Divesh\n";
        else
            cout<<"Tanya\n";
    }
    return 0;
}