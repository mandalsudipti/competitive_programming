#include<bits/stdc++.h>
using namespace std ;

const int unvisited = 0 , visited = 1 , blocked = -1 ;

string get_string(int k)
{
    vector<vector<int>>distinct_pair(k , vector<int>(k , unvisited));
    string S ;
    
    distinct_pair[0][0] = visited ;
    bool found  = true ;
    while(found)
    {
        if(S.length() == 0)
            S+="aa";
        else
        {
            found = false ;
            int last_letter = (S.back() - 'a');
            
            for(int i = 0 ; i < k ; i++)
            {
                if(distinct_pair[last_letter][i] == unvisited)
                {
                    if(distinct_pair[i][k-1] == visited)
                        distinct_pair[last_letter][i] = blocked ;
                    else
                    {
                        S+=(i + 'a');
                        distinct_pair[last_letter][i] = visited ;
                        found = true ;
                        break;
                    }
                }
            }
        }
    }
    
    if(k > 1)
        S+='a' ;
    
    return S ;
}

int main()
{
    int n , k ;
    cin>>n>>k;
    
    string base_string = get_string(k);
    
    string ans ;
    if(base_string.length() >= n)
        ans+=base_string.substr(0,n);
    else
    {
        ans+=base_string ;
        while(n - ans.length() >= base_string.length()-1)
            ans+=base_string.substr(1) ;
        
        if(n - ans.length() >= 1)
            ans+=base_string.substr(1 , n - ans.length());
    }
    
    cout<<ans<<endl;
    
    return 0 ;
}

