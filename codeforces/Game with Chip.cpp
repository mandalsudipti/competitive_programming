#include<bits/stdc++.h>
using namespace std;

int main()
{
   int row , col  , chip ;
   cin>>row>>col>>chip;
   vector<pair<int,int>>source(chip);
   vector<pair<int,int>>dest(chip);
   int x,y,i;
   string ans="";
   for(i=0;i<chip;i++)
   {
       cin>>x>>y;
       source[i]=make_pair(x,y);
   }
   for(i=0;i<chip;i++)
   {
       cin>>x>>y;
       dest[i]=make_pair(x,y);
   }
   for(i=row;i>1;i--)
    ans+='U';
    for(i=col;i>1;i--)
        ans+='L';
    for(i=1;i<=row;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<col;j++)
                ans+='R';
        }
        else
        {
            for(int j=col-1;j>=1;j--)
                ans+='L';
        }
        if(i<row)
            ans+='D';
    }
    cout<<ans.length()<<endl;
    cout<<ans;
    return 0;
}


