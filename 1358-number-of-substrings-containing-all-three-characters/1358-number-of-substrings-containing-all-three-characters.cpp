class Solution {
public:

    long long numberOfSubstrings(string s) {
        int n = s.size();
        if (n < 3) {
            return 0;
        }
 
        vector<int> frequency(3, 0);
 
        int left = 0;
        long long count = 0;
 
        for (int right = 0; right < n; right++) {
            frequency[s[right] - 'a']++;
 
            while (
                frequency[0] > 0 &&
                frequency[1] > 0 &&
                frequency[2] > 0
            ) {
                count += n - right;
 
                frequency[s[left] - 'a']--;
                left++;
            }
        }
 
        return count;
    }
};