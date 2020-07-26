class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
                int start=0;
        int maxlen=1;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=0;i<n-1;i++) 
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxlen=2;
            }
        }

        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    if(k>maxlen)
                    {
                        start=i;
                        maxlen=k;
                    }
                    dp[i][j]=true;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
