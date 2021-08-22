#include<bits/stdc++.h>
using namespace std ;


bool all_found(vector<int>& count , map<char,int>& mp)
{
    for(pair<char,int>P : mp)
    {
        if(count[P.first - 'a'] != P.second)
            return false ;
    }
    return true ;
}

bool is_valid(vector<string>& arr)
{
    for(int i = 0 ; i < arr.size()-1 ; i++)
    {
        string S1 = arr[i] , S2 = arr[i+1] ; // S2 > S1
        char tmp = '#' ;
        int idx = 0 ;
        
        for(int j = 0 ; j < S2.length() ; j++)
        {
            if(idx >= S1.length() || S1[idx] != S2[j])
            {
                if(tmp == '#')
                    tmp = S2[j] ;
                else if(tmp != S2[j])
                    return false ;
            }
            else
                idx++ ;
        }
    }
    
    return true ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        string S ;
        cin>>S;
        
        vector<string>substring ;
        vector<int>freq(26 , 0) ;
        vector<bool>found(26 , false) ;
        
        string op = "" , ans = "" ;
        int step = 0, required_char = 0 ;
        bool possible = true ;
        
        for(int i = 0 ; i < S.length() ; i++)
        {
            freq[S[i] - 'a']++ ;
            if(freq[S[i] - 'a'] == 1)
                step++ ;
        }
        
        while(step > 0 && possible && S.length() > 0)
        {
            map<char,int>required_freq ;
            step-- ;
            required_char++ ;
            
            vector<int>count(26 , 0) ;
            int start = 0 ;
            
            for(int i = S.length()-1 ; i >= 0 ; i--)
            {
                count[S[i]-'a']++;
                if(count[S[i] - 'a'] == 1)
                {
                    required_freq[S[i]] = freq[S[i] - 'a'] / (step + 1) ;
                    if(freq[S[i] - 'a'] % (step + 1) != 0)
                    {
                        possible = false ;
                        break;
                    }
                }
                
                freq[S[i] - 'a']-- ;
                if(!found[S[i] - 'a'])
                {
                    found[S[i] - 'a'] = true ;
                    op+=S[i] ;
                }
                
                if(required_freq.size() == required_char && all_found(count , required_freq))
                {
                    start = i ;
                    break;
                }
                
            }
            
            if(required_freq.size() != required_char)
            {
                possible = false ;
                break;
            }
            
            substring.push_back(S.substr(start , S.length() - start + 1)) ;
            S = S.substr(0 , start) ;
        }
        
        if(!possible || step != 0)
        {
            cout<<"-1"<<endl;
            continue ;
        }
        reverse(op.begin() , op.end());
        ans = substring.back() ;
        
        if(is_valid(substring))
            cout<<ans<<" "<<op<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0 ;
}