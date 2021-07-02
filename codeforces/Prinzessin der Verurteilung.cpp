#include<bits/stdc++.h>
using namespace std ;

void precompute(vector<string>& arr)
{
    for(int i = 0 ; i < 26 ; i++)
    {
        string S = "" ;
        S+=(i + 'a') ;
        arr.push_back(S) ;
        for(int j = 0 ; j < 26 ; j++)
        {
            S+=(j + 'a') ;
            arr.push_back(S) ;
            for(int k = 0 ; k < 26 ; k++)
            {
                S+=(k + 'a');
                arr.push_back(S) ;
                S.pop_back() ;
            }
            S.pop_back() ;
        }
    }
}

set<string>get_substring(string& S)
{
    set<string>sub_string ;
    
    for(int i = 0 ; i < S.length() ; i++)
    {
        for(int j = i ; j < S.length() ; j++)
            sub_string.insert(S.substr(i , j - i + 1)) ;
    }
    return sub_string ;
}

bool sortbylen(const string& S1 , const string& S2)
{
    if(S1.length() != S2.length())
        return S1.length() < S2.length() ;
    else
        return S1 < S2 ;
}

int main()
{
    vector<string>arr ;
    precompute(arr) ;
    sort(arr.begin() , arr.end() , sortbylen) ;
        
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n ;
        string S ;
        cin>>S ;
        
        set<string>sub_string = get_substring(S) ;
        string MEX ;
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(sub_string.find(arr[i]) == sub_string.end())
            {
                MEX = arr[i] ;
                break;
            }
        }
        cout<<MEX<<endl;
    }
    
    return 0 ;
}