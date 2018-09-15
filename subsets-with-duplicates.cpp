class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subsets_helper(res, temp, nums, 0);
        return res;
    }
private:
    void subsets_helper(vector<vector<int> >& res, vector<int>& temp, vector<int> nums, int start) {
        res.push_back(temp);
        for(int i=start; i<nums.size(); i++) {
            if (i>start && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            subsets_helper(res, temp, nums, i+1);
            temp.pop_back();
        }
    }
};
