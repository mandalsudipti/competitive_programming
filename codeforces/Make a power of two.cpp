#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<long long int>power_of_two ;
    power_of_two.push_back(1) ;
    
    while(power_of_two.back() < 1e18)
        power_of_two.push_back(power_of_two.back() * 2ll) ;
        
    unordered_map<string , int>prefix ;
    for(long long int num : power_of_two)
    {
        string S = to_string(num) ;
        for(int i = 0 ; i < S.length() ; i++)
        {
            string cur = S.substr(0 , i+1) ;
            if(prefix.find(cur) == prefix.end() || prefix[cur] > (S.length() - i - 1))
                prefix[cur] = S.length() - i - 1 ;
        }
    }
    
    int T ;
    cin>>T;
    
    while(T--)
    {
        long long int num ;
        cin>>num ;
        string S = to_string(num) ;
        
        int min_op = S.length() + 1 , n = S.length();
        for(int i = 1 ; i < (1<<n) ; i++)
        {
            string subsequence = "" ;
            for(int bit = 0 ; bit <= 10 ; bit++)
            {
                if(i & (1<<bit))
                    subsequence+=S[bit] ;
            }
            //cout<<subsequence<<endl;
            if(prefix.find(subsequence) != prefix.end())
                min_op = min(min_op , prefix[subsequence] + n - (int)subsequence.length()) ;
        }
        
        cout<<min_op<<endl;
    }
    
    return 0 ;
}
