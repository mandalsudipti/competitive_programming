#include<bits/stdc++.h>
using namespace std;
const int fix = 2 , not_fix = -1 ;
int main()
{
    int n ;
    cin>>n;
    vector<int>bits(10,not_fix);
    
    while(n--)
    {
        char op ;
        int x;
        cin>>op>>x ;
        if(op=='&')
        {
            for(int i=0;i<10;i++)
            {
                if((x&(1<<i))== 0)
                    bits[i]=0;
            }
        }
        else if(op=='|')
        {
            for(int i=0;i<10;i++)
            {
                if(x & (1<<i))
                    bits[i]=1;
            }
        }
        else if(op=='^')
        {
            for(int i=0;i<10;i++)
            {
                if( x & (1<<i))
                {
                    if(bits[i]==1 || bits[i] == 0 )
                        bits[i] = bits[i]^1;
                    else if(bits[i]==not_fix)
                        bits[i] = fix ;
                    else
                        bits[i] = not_fix;
                }
            }
        }
    }
    
    int AND = 0 , OR = 0 , XOR = 0 ;
    for(int i=0;i<10;i++)
    {
        //cout<<bits[i]<<endl;
        if(bits[i]!=0)
            AND +=(1<<i);
        if(bits[i]==1)
            OR+=(1<<i);
        if(bits[i]==fix)
            XOR+=(1<<i);
    }
    cout<<"3"<<endl;
    cout<<"&"<<" "<<AND<<endl;
    cout<<"|"<<" "<<OR<<endl;
    cout<<"^"<<" "<<XOR<<endl;
    
    return 0;
}