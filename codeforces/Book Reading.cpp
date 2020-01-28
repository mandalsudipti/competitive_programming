#include<bits/stdc++.h>
using namespace std;

int main ()
{
  int query;
  cin >> query;
  while (query--)
  {
      long long int page, divisor, i, j, sum = 0, ten = 10, valid_page;
      cin >> page >> divisor;
      valid_page = page / divisor;
      vector<long long int>last_digit;
      for(i=1;i<=10;i++)
      {
        bool found=false;
        for(j=0;j<last_digit.size();j++)
        {
            if(last_digit[j]==(divisor*i)%ten)
            {
                found=true;
                break;
            }
        }
        if(!found)
        {
            last_digit.push_back((divisor*i)%ten);
        }
      }
      while(valid_page>0)
      {
          //cout<<valid_page<<endl;
          if(valid_page>=last_digit.size())
          {
              for(i=0;i<last_digit.size();i++)
                sum+=last_digit[i];
              sum=(sum)*(valid_page/last_digit.size());
              valid_page=valid_page-((valid_page/last_digit.size())*last_digit.size());
          }
          else if(valid_page<last_digit.size())
          {
              for(i=0;i<valid_page;i++)
                sum+=last_digit[i];
              valid_page=0;
          }
      }
      cout<<sum<<endl;
   }
  return 0;
}
