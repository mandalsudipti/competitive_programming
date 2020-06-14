#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        set<int>claim_row;
        set<int>claim_col;
        int row , col  , val ;
        cin>>row>>col;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>val;
                if(val==1)
                {
                    claim_row.insert(i);
                    claim_col.insert(j);
                }
            }
        }
        int free_row = row - claim_row.size() ;
        int free_col = col - claim_col.size() ;
        
        if(min(free_col,free_row)%2==0)
            cout<<"Vivek"<<endl;
        else
            cout<<"Ashish"<<endl;
    }
    return 0;
}