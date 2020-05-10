#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    string left , right ;
    cin>>left>>right;
    vector<vector<int>>left_letter(26);
    vector<vector<int>>right_letter(26);
    vector<int>left_question_mark;
    vector<int>right_question_mark;
    
    for(int i=0;i<n;i++)
    {
        if(left[i]=='?')
            left_question_mark.push_back(i);
        else if(left[i]!='?')
            left_letter[left[i]-97].push_back(i);
            
        if(right[i]=='?')
            right_question_mark.push_back(i);
        else if(right[i]!='?')
            right_letter[right[i]-97].push_back(i);
    }
    
    int left_idx=0 , right_idx=0;
    vector<pair<int,int>>ans;
    
    for(int i=0;i<26;i++)
    {
        int len = min(left_letter[i].size(),right_letter[i].size());
        for(int j=0;j<len;j++)
        {
            ans.push_back(make_pair(left_letter[i][j],right_letter[i][j]));
        }
        if(left_letter[i].size()>len)
        {
            for(int j=len;j<left_letter[i].size();j++)
            {
                if(right_idx==right_question_mark.size())
                    break;
                else
                    ans.push_back(make_pair(left_letter[i][j],right_question_mark[right_idx++]));
            }
        }
        else if(right_letter[i].size()>len)
        {
            for(int j=len;j<right_letter[i].size();j++)
            {
                if(left_idx==left_question_mark.size())
                    break;
                else
                    ans.push_back(make_pair(left_question_mark[left_idx++],right_letter[i][j]));
            }
        }
    }
    while(left_idx<left_question_mark.size() && right_idx<right_question_mark.size())
    {
        ans.push_back(make_pair(left_question_mark[left_idx++],right_question_mark[right_idx++]));
    }
    
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
        
    return 0;
}
