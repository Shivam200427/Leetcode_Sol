class Solution {
public:

    vector<vector<int>> ans;
    vector<int> current;

    void solve(vector<int>& nums, int index) {

        if(index == nums.size()) {
            ans.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        solve(nums, index + 1);

        current.pop_back();
        solve(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(nums, 0);

        return ans;
    }
};