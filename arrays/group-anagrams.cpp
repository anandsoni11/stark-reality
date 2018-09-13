/*
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > hmap;
        int l = strs.size();
        for (int i=0; i<l; i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            hmap[key].push_back(strs[i]);
        }
        
        for (auto it=hmap.begin(); it!=hmap.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};
