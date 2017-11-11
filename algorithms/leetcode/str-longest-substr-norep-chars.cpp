class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128,-1);
        int start = -1;
        int maxLen = 0;
        for (int i=0; i<s.length(); i++) {
            if (v[s[i]] > start) {
                start = v[s[i]];
            }
            v[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};