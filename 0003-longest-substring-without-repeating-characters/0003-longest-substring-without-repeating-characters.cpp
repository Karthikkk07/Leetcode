class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }

            hash[s[right]] = right;

            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};