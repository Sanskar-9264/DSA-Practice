class Solution {
public:

    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& ans, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(ans);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        // Include current element
        if (candidates[idx] <= target) {
            ans.push_back(candidates[idx]);
            
            solve(candidates, target - candidates[idx],
                  idx, ans, result);

            // Backtrack
            ans.pop_back();
        }

        // Exclude current element
        solve(candidates, target, idx + 1, ans, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> ans;

        solve(candidates, target, 0, ans, result);

        return result;
    }
};