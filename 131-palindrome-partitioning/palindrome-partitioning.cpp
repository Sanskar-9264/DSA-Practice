class Solution {
public:

    bool isPalindrome(string& s, int start, int end) {

        while (start < end) {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void solve(string& s, int idx,
               vector<string>& ans,
               vector<vector<string>>& result) {

        // String completely partitioned
        if (idx == s.size()) {
            result.push_back(ans);
            return;
        }

        // Try every possible substring
        for (int i = idx; i < s.size(); i++) {

            // Only choose palindrome substring
            if (isPalindrome(s, idx, i)) {

                // Choose
                ans.push_back(s.substr(idx, i - idx + 1));

                // Recursion for remaining string
                solve(s, i + 1, ans, result);

                // Backtrack
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> ans;

        solve(s, 0, ans, result);

        return result;
    }
};