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
        
        vector<int>arr(n+1);
        for(int i = 1 ; i <= n ; i++)
            cin>>arr[i] ;
        
        bool flag = true ;
        for(int i = 1 ; i <= n ; i++)
        {
            if(i != arr[i])
            {
                flag = false ;
                break;
            }
        }
        
        if(flag)
            cout<<"0"<<endl;
        else if(arr[1] == 1 || arr[n] == n)
            cout<<"1"<<endl;
        else
        {
            if(arr[1] == n && arr[n] == 1)
                cout<<"3"<<endl;
            else
                cout<<"2"<<endl;
        }
    }
    
    return 0 ;
}
