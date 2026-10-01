class Solution {
public:

    vector<int> current;
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int i) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (target < 0 || i == candidates.size()) {
            return;
        }

        current.push_back(candidates[i]);

        solve(candidates, target - candidates[i], i);

        current.pop_back();

        solve(candidates, target, i + 1);
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {

        solve(candidates, target, 0);

        return ans;
    }
};