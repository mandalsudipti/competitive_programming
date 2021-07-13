#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>A(n) , B(n) ;
        int diff = 0 ;
        vector<int>up , down ;
        
        for(int i = 0 ; i < n ; i++)
            cin>>A[i] ;
        for(int i = 0 ; i < n ; i++)
            cin>>B[i] ;
            
        for(int i = 0 ; i < n ; i++)
        {
            diff+=(A[i] - B[i]);
            if(A[i] > B[i])
                up.push_back(i);
            else if(A[i] < B[i])
                down.push_back(i) ;
        }
        
        if(diff != 0)
            cout<<"-1\n";
        else
        {
            int op = 0 ;
            for(int i = 0 ; i < up.size() ; i++)
                op+=abs(A[up[i]] - B[up[i]]) ;
                
            cout<<op<<endl;
            int idx1 = 0 , idx2 = 0 ;
            while(idx1 < up.size() && idx2 < down.size())
            {
                cout<<up[idx1]+1<<" "<<down[idx2]+1<<endl;
                A[up[idx1]]-- ;
                if(A[up[idx1]] == B[up[idx1]])
                    idx1++ ;
                    
                A[down[idx2]]++;
                if(A[down[idx2]] == B[down[idx2]])
                    idx2++ ;
                
            }
        }
    }
    return 0 ;
}