class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        string res = "";
        vector<vector<bool> > dp(l, vector<bool>(l,0));
        for (int i=l-1; i>=0; i--) {
            for (int j=i; j<l; j++) {
                dp[i][j] = (s[i] == s[j]) && ((j-i <= 2) || dp[i+1][j-1]);
                
                if(dp[i][j] && (res.empty() || (j-i+1 > res.length()))) {
                    res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};