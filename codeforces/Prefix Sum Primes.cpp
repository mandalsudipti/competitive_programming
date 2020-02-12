#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int cnt_one=0 , cnt_two =0 , val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        val==1 ? cnt_one++ : cnt_two++ ;
    }
    if(cnt_two>0)
    {
        cout<<"2 ";
        cnt_two--;
    }
    if(cnt_one>0)
    {
        cout<<"1 ";
        cnt_one--;
    }
    while(cnt_two--)
        cout<<"2 ";
    while(cnt_one--)
        cout<<"1 ";
    return 0;
}