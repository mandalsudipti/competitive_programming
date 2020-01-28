#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool allwhite=true , allblack=true;
    int n,i;
    cin>>n;
    string str;
    cin>>str;
    vector<int>move;
    for(i=0;i<n;i++) //allwhite
    {
        if(str[i]=='B')
        {
            allwhite=false;
            break;
        }
    }
    if(allwhite)
    {
        cout<<"0";
        return 0;
    }
    for(i=0;i<n;i++)//all black
    {
        if(str[i]=='W')
        {
            allblack=false;
            break;
        }
    }
    if(allblack)
    {
        cout<<"0";
        return 0;;
    }
    for(i=0;i<n-1;i++) // make white
    {
        if(str[i]=='B')
        {
            move.push_back(i+1);
            str[i]='W';
            if(str[i+1]=='B')
                str[i+1]='W';
            else
                str[i+1]='B';
        }
    }
    if(str[n-1]=='B')
    {
        for(i=0;i<n-1;i++) // make black
        {
            if(str[i]=='W')
            {
                move.push_back(i+1);
                str[i]='B';
                if(str[i+1]=='W')
                    str[i+1]='B';
                else
                    str[i+1]='W';
            }
        }
        if(str[n-1]=='W')
        cout<<"-1";
        else
        {
            cout<<move.size()<<endl;
            for(i=0;i<move.size();i++)
                cout<<move[i]<<" ";
        }
    }
    else
    {
        cout<<move.size()<<endl;
        for(i=0;i<move.size();i++)
            cout<<move[i]<<" ";
    }
    return 0;
}

