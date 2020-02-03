#include<bits/stdc++.h>
using namespace std;

int main()
{
   int T;
   cin>>T;
   while(T--)
   {
       int n ,i, cnt_odd=0;
       cin>>n;
       string S;
       cin>>S;
       string T="";
       for(i=0;i<n;i++)
       {
           if((S[i]-48)!=0 && (S[i]-48)%2==1)
           {
               T+=S[i];
               cnt_odd++;
               if(cnt_odd%2==0)
                break;
           }
           else
            T+=S[i];
       }
       if(cnt_odd%2==0 && cnt_odd!=0)
        cout<<T<<endl;
       else
        cout<<"-1"<<endl;
   }
   return 0;
}