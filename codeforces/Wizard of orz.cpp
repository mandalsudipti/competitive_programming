#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        if(n == 1)
            cout<<"9"<<endl;
        else
        {
            vector<int>arr(n+1);
            arr[2] = 8 ;
            for(int i = 1 ; i <= n ; i++)
            {
                if(i != 2)
                    arr[i] = ( 8 + abs(i-2))%10 ;
            }
            for(int i = 1 ; i <= n ; i++)
                cout<<arr[i];
            cout<<endl;
        }
    }
    
    return 0;
}
