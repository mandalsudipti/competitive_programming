#include<bits/stdc++.h>
using namespace std;

int  main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int type , grid_size ;
        cin>>type>>grid_size;
        vector<vector<int>>tiles(type,vector<int>(4));
        
        bool possible = false;
        for(int i=0;i<type;i++)
        {
            cin>>tiles[i][0]>>tiles[i][1]>>tiles[i][2]>>tiles[i][3];
            if(tiles[i][1]==tiles[i][2])
                possible = true ;
        }
        
        if(!possible || grid_size%2!=0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    return 0;
}