#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        string red , blue ;
        cin>>red>>blue;
        
        int win = 0 , loss = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(red[i] > blue[i])
                win++;
            else if(red[i] < blue[i])
                loss++;
        }
        
        if(win > loss)
            cout<<"RED\n";
        else if(win < loss)
            cout<<"BLUE\n";
        else
            cout<<"EQUAL\n";
    }
    
    return 0;
}

