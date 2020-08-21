#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char ch)
{
    vector<char>vowel = {'a','e','i','o','u',' '};
    for(int i=0;i<vowel.size();i++)
    {
        if(vowel[i]==ch)
            return true;
    }
    return false;
}

int main()
{
    string S;
    cin>>S;
    int i = 0 ;
    while(i<S.length())
    {
        if(!is_vowel(S[i]) && i+2<S.length() && !is_vowel(S[i+1]) && !is_vowel(S[i+2]))
        {
            if(S[i+1]!=S[i] || S[i+2]!=S[i])
            {
                S.insert(i+2," ");
            }
        }
        i++;
    }
    
    cout<<S;
    
    return 0;
}
