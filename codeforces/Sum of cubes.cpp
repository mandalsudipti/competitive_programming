#include<bits/stdc++.h>
using namespace std;
const long long int range = 1e12 + 5 ;
void get_cube(set<long long int>& cube_number)
{
    for(long long int i = 1 ; i < 10005 ; i++)
    {
        long long int cube = i * i * i ;
        if(cube > range)
            break;
        cube_number.insert(cube);
    }
}

int main()
{
    set<long long int> cube_number ;
    get_cube(cube_number);
    
    int T ;
    cin>>T;
    while(T--)
    {
        long long int x ;
        cin>>x;
        bool possible = false;
        
        for(long long int num : cube_number)
        {
            if( num > x)
                break;
            if(cube_number.find(x - num) != cube_number.end())
            {
                possible = true ;
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