#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,i,min_len=200005,horizontal=0, vertical=0 ,left , right ;
        cin>>n;
        string S;
        cin>>S;
        map < pair<int,int> , int > pos ;
        pos[make_pair(0,0)]=-1;
        for(i=0;i<n;i++)
        {
            switch(S[i])
            {
                case 'L': horizontal--; break;
                case 'R':horizontal++; break;
                case 'U':vertical++; break;
                case 'D': vertical--; break;
            }
            if(pos.count(make_pair(horizontal,vertical))!=0)
            {
                int last_loc = pos[make_pair(horizontal,vertical)];
                if((i-last_loc)<min_len)
                    {
                        min_len=i-last_loc;
                        left=last_loc+1;
                        right=i;
                    }
            }
            pos[make_pair(horizontal,vertical)]=i;
        }
        if(min_len>n)
            cout<<"-1\n";
        else
        {
            cout<<left+1<<" "<<right+1<<endl;
        }
        
    }
    return 0;
}
