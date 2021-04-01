#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        
        vector<int>arr(n);
        multiset<int,greater<int>>freq ;
        int start = 0;
        
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
        
        sort(arr.begin(),arr.end());    
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i] != arr[start])
            {
                freq.insert(i - start);
                start = i ;
            }
        }
        freq.insert(n - start);
        
        while(freq.size() > 1)
        {
            int first , second ;
            
            first = (*freq.begin());
            freq.erase(freq.begin());
            
            second = (*freq.begin());
            freq.erase(freq.begin());
            
            first--;
            second--;
            
            if(first != 0)
                freq.insert(first);
            if(second != 0)
                freq.insert(second);
        }
        
        cout<<(*freq.begin())<<endl;
        
    }
    
    return 0;
}



