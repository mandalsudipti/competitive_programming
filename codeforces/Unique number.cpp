#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x ;
        cin>>x;
        vector<int>num;
        int maximum = 9 ;
        
        if(x > 45)
        {
            cout<<"-1"<<endl;
            continue;
        }
        
        while(x > 0)
        {
            if(maximum <= x)
            {
                num.push_back(maximum);
                x-=maximum;
                maximum--;
            }
            else
            {
                num.push_back(x);
                break;
            }
        }
        
        reverse(num.begin(),num.end());
        for(int i = 0 ; i < num.size() ; i++)
            cout<<num[i];
        cout<<endl;
    }
    
    return 0;
}