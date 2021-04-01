#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , length ;
        cin>>n>>length ;
        
        multiset<int>arr ;
        for(int i = 0 ; i < n ; i++)
        {
            int val;
            cin>>val;
            arr.insert(val);
        }
        
        int tmp = length , height = 1;
        while(arr.size() > 0)
        {
            auto itr = arr.lower_bound(tmp);
            
            if( itr != arr.begin() && (itr == arr.end() || (*itr) > tmp))
                --itr ;
            
            if((*itr) <= tmp)
            {
                tmp-=(*itr);
                arr.erase(itr);
            }
            else
            {
                height++;
                tmp = length ;
            }
        }
        
        cout<<height<<endl;
    }
    
    return 0 ;
}

