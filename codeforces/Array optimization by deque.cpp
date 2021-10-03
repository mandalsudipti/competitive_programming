#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace __gnu_pbds;
using namespace std ;

template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        multi_ordered_set<int> seg_tree ;
        int n ,val ;
        cin>>n ;
        map<int,int>freq ;
        
        long long int count_inverse = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val ;
            freq[val]++ ;
            
            if(i == 0)
            {
                seg_tree.insert(val) ;
                continue ;
            }
            seg_tree.insert(val) ;
            
            int lower_ele = seg_tree.order_of_key(val) ;
            int higher_ele = i+1 - lower_ele - freq[val] ;
            
            count_inverse+=min(lower_ele , higher_ele) ;
        }
        
        cout<<count_inverse<<endl;
    }
    
   return 0 ;
}
