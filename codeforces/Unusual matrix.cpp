#include<bits/stdc++.h>
using namespace std;

void change_col(vector<string>&matrix1 , int col)
{
    for(int i = 0 ; i < matrix1.size() ; i++)
    {
        matrix1[i][col] == '0' ? matrix1[i][col] = '1' : matrix1[i][col] = '0' ;
    }
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        
        vector<string>matrix1(n);
        vector<string>matrix2(n);
        
        for(int i = 0 ; i < n ; i++)
            cin>>matrix1[i];
        for(int i = 0 ; i < n ;i++)
            cin>>matrix2[i];
        
        for(int j = 0 ; j < n ; j++)
        {
            if(matrix1[0][j] != matrix2[0][j])
                change_col(matrix1 , j);
        }
        
        
        bool possible = true ;
        for(int i = 1 ; i < n ; i++)
        {
            int cnt = 0 ;
            for(int j = 0 ; j < n ; j++)
            {
                if(matrix1[i][j]!=matrix2[i][j])
                    cnt++;
            }
            if(cnt > 0 && cnt < n)
            {
                possible = false;
                break;
            }
        }
        
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}