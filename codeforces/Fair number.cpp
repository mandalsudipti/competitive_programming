#include<bits/stdc++.h>
using namespace std;

bool is_fair(long long int n)
{
    long long int tmp = n ;
    vector<long long int>digit;
    
    while(tmp != 0)
    {
        digit.push_back(tmp%10ll);
        tmp = tmp/10ll ;
        if(digit.back()!=0 && n% digit.back())
            return false;
            
    }
    
    return true ;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        while(!is_fair(n))
            n++;
        cout<<n<<endl;
    }
    
    return 0;
}