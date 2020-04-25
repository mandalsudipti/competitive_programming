#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size ;
    cin>>size;
    vector<int>change_if_black(4,0);
    for(int i=0;i<4;i++)
    {
        int cnt=0;
        for(int j=0;j<size;j++)
        {
            string S;
            cin>>S;
            for(int k=0;k<size;k++)
            {
                int num = S[k]-48;
                if(num == (j+k)%2)
                    cnt++;
            }
        }
        change_if_black[i]=cnt;
    }
    int min_change = 5*size*size  , x ;
    
    x = 4*size*size - change_if_black[0] - change_if_black[1] - change_if_black[2] - change_if_black[3] ;
    for(int i=0;i<=2;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            int change=x-(size*size-change_if_black[i])-(size*size-change_if_black[j])+change_if_black[i]+change_if_black[j] ;
            min_change = min(min_change , change);
            //cout<<change<<endl;
        }
    }
    cout<<min_change;
    return 0;
}