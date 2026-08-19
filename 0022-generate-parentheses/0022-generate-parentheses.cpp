class Solution {
public:
    void backtrack(string curr, int open, int close, int n,
                   vector<string>& ans) {
        
        // If we have used all parentheses
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can add '(' if we haven't used all n opening brackets
        if (open < n) {
            backtrack(curr + '(', open + 1, close, n, ans);
        }

        // We can add ')' only if there are unmatched '('
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