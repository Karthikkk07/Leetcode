class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size(), 0);

        int len = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
            }
            else if (len != 0) {
                len = lps[len - 1];
                i--;
            }
        }

        return s.substr(0, lps[s.size() - 1]);
    }
};