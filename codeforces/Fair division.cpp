#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int sum = 0 , two = 0 , one = 0 , val ;
        for(int i = 0 ; i < n ;i++)
        {
            cin>>val;
            sum+=val;
            val == 2 ? two+=val : one+=val ;
        }
        
        if(sum%2)
            cout<<"NO"<<endl;
        else
        {
            sum= sum/2 ;
            bool flag = true ;
            if(sum%2)
            {
                if(!one)
                    flag = false;
                else
                {
                    one--;
                    sum--;
                }
            }
            
            int tmp = min(sum , two) ;
            sum-=tmp;
            
            if(sum > one)
                flag = false;
                
            if(!flag)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    
    return 0;
}