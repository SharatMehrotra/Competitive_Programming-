// 14
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int min=INT_MAX;
        int i;
        string word;
        if(strs.size()==0) return "";
        for(i=0;i<strs.size();i++)
        {
            if(strs[i].size()<min)
            {
                min=strs[i].size();
                word=strs[i];
            } 
        }
        int flag=0;
        for(i=0;i<min;i++)
        {
            char ch=word[i];
            flag=0;
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j][i]!=ch)
                    flag=1;
            }
            if(!flag)
                s.push_back(ch);
            else break;
        }
        return s;
    }
};
