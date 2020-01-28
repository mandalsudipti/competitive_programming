#include<bits/stdc++.h>
using namespace std;

long long int get_identical(int n)
{
    return (n*(n-1)*(n-2))/6 ;
}

char get_third(char a , char b)
{
    if((a=='S' && b=='E')||(a=='E' && b=='S'))
        return 'T';
    else if((a=='E' && b=='T') || (a=='T' && b=='E'))
        return 'S';
    else
        return 'E';
}

string get_string(string s1 , string s2)
{
    string mystring;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]==s2[i])
            mystring+=s1[i];
        else
        {
            mystring+= get_third(s1[i] , s2[i]);
        }
    }
    return mystring ;
}

int main()
{
    int n ,k ,i ;
    cin>>n>>k;
    map<string , int > card ;
    vector<string> feature(n) ;
    
    for(i=0;i<n;i++)
    {
        cin>>feature[i];
        card[feature[i]]++;
    }
    long long int identical_set=0 , non_identical_set=0 , total_set=0 ;
    for(auto itr=card.begin();itr!=card.end();++itr)
    {
        identical_set+= get_identical(itr->second);
    }
    for(i=0;i<feature.size();i++)
    {
        for(int j=i+1 ;j<feature.size();j++)
        {
            if(feature[i]==feature[j])
            {
                continue;
            }
            else
            {
                string mystring = get_string(feature[i] , feature[j]) ;
                non_identical_set+=card[mystring];
            }
        }
    }
    non_identical_set /=3 ;
    total_set = identical_set + non_identical_set ;
    cout<<total_set ;
    return 0;
}