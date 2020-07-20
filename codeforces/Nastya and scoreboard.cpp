#include<bits/stdc++.h>
using namespace std;
const int invalid = 1e9 ;
vector<string>num_arr;

void set_num()
{
    num_arr.push_back("1110111"); //0
    num_arr.push_back("0010010"); //1
    num_arr.push_back("1011101"); //2
    num_arr.push_back("1011011"); //3 
    num_arr.push_back("0111010"); //4
    num_arr.push_back("1101011"); //5
    num_arr.push_back("1101111"); //6 
    num_arr.push_back("1010010"); //7
    num_arr.push_back("1111111"); //8
    num_arr.push_back("1111011"); //9
}

int convert(string S , int num)
{
    string T = num_arr[num] ;
    int cnt = 0 ;
    for(int i=0;i<T.length();i++)
    {
        if(S[i]=='1' && T[i]=='0')
            return invalid;
        if(S[i]=='0' && T[i]=='1')
            cnt++;
    }
    return cnt ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set_num();
    
    int n , k ;
    cin>>n>>k;
    
    vector<string>digit(n);
    for(int i=0;i<n;i++)
        cin>>digit[i];
    
    vector<vector<bool>>is_possible(n+2,vector<bool>(k+5,false));
    is_possible[n][0] = true;
    
    /*for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=k;j++)
        {
            for(int d=0;d<10;d++)
            {
                int x  = convert(digit[i],d) ;
                int remain = j - x ;
                if(remain>=0 && is_possible[i+1][remain])
                    is_possible[i][j] = true ;
            }
        }
    }*/
    
    for(int i=n-1;i>=0;i--)
    {
        vector<int>convert_req ;
        for(int d=0;d<10;d++)
            convert_req.push_back(convert(digit[i],d));
            
        for(int j=0;j<=k;j++)
        {
            for(int d=0;d<10;d++)
            {
                int x = convert_req[d] ;
                int remain = j - x ;
                if(remain>=0 && is_possible[i+1][remain])
                    is_possible[i][j] = true ;
            }
        }
    }
    
    if(!is_possible[0][k])
    {
        cout<<"-1";
        return 0;
    }
    string ans ;
    for(int i=0;i<n;i++)
    {
        for(int d=9;d>=0;d--)
        {
            int x = convert(digit[i],d) ;
            int remain = k - x ;
            if(remain>=0 && is_possible[i+1][remain])
            {
                ans +=(d+'0');
                k-=x;
                break;
            }
        }
    }
    
    cout<<ans;
    
    return 0;
}

