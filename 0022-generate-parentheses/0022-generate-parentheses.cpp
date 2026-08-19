class Solution {
public:
    void backtrack(string curr, int open, int close, int n,
                   vector<string>& ans) {
        
       
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            backtrack(curr + '(', open + 1, close, n, ans);
        }

        if (close < open) {
            backtrack(curr + ')', open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        backtrack("", 0, 0, n, ans);

        return ans;
    }
};