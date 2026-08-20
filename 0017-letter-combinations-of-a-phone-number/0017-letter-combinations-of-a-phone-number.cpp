class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty())
            return ans;
        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        string current;
        backtrack(0, digits, mp, current, ans);
        return ans;
    }
    void backtrack(int index, string& digits,
                   vector<string>& mp,
                   string& current,
                   vector<string>& ans) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);       
            backtrack(index + 1, digits,mp, current, ans); 
            current.pop_back();         
        }
    }
};