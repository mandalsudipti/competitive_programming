#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        
        if(k < n && n%k != 0)
            cout<<"2"<<endl;
        else if(k < n)
            cout<<"1"<<endl;
        else
            cout<<(k/n) + (k%n != 0) <<endl;
    }
    
    return 0;
}

