#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
        
    return false;
}

int main()
{
    string S , T ;
    cin>>S>>T;
    if(S.length()!=T.length())
        cout<<"NO";
    else
    {
        for(int i=0;i<S.length();i++)
        {
            if(is_vowel(S[i])!=is_vowel(T[i]))
            {
                cout<<"NO";
                return 0;
            }
        }
        cout<<"YES";
    }
        
    return 0;
}
