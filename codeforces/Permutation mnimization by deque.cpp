#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , val;
        cin>>n ;
        
        deque<int>arr ;
        for(int i = 0 ; i < n; i++)
        {
            cin>>val;
            if(arr.size() == 0 || arr.front() < val)
                arr.push_back(val) ;
            else
                arr.push_front(val) ;
        }
        
        for(int ele : arr)
            cout<<ele<<" ";
        cout<<endl;
    }
    
    return 0 ;
}