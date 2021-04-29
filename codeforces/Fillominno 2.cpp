#include<bits/stdc++.h>
using namespace std ;

bool fill_matrix(vector<vector<int>>&matrix , int idx)
{
    int n = matrix.size() , cnt = matrix[idx][idx] , left = idx , ele = matrix[idx][idx]  , nxt_left ;
    
    while(cnt > 0 && idx < n)
    {
        nxt_left = -1 ;
        for(int i = idx ; i < n ; i++)
        {
            if(cnt == 0)
                break;
            
            int start = left ;
            for(int j = start ; j >= 0 ; j--)
            {
                if(cnt == 0 || (matrix[i][j] != 0 && matrix[i][j] != ele))
                    break;
                else
                {
                    cnt--;
                    matrix[i][j] = ele ;
                    left = j ;
                }
            }
            
            if(nxt_left == -1 && i+1 < n && matrix[i+1][left+1] == 0)
                nxt_left = left+1 ;
        }
        if(cnt > 0)
        {
            idx++ ;
            left = nxt_left ;
        }
    }
    
    if(cnt != 0)
        return false ;
    else
        return true ;
}

int main()
{
        int n ;
        cin>>n;
        vector<vector<int>>matrix(n , vector<int>(n,0));
        
        for(int i = 0 ; i < n ; i++)
            cin>>matrix[i][i] ;
         
        bool possible = true ;   
        for(int i = 0 ; i < n ; i++)
        {
            if(!possible)
                break;
            possible = fill_matrix(matrix , i);
        }  
        if(!possible)
            cout<<"-1"<<endl;
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j <= i ; j++)
                    cout<<matrix[i][j]<<" ";
                cout<<endl;
            }
        }
    
    return 0 ;
}