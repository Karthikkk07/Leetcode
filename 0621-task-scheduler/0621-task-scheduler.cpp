class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];

        int slots = (maxFreq - 1) * (n + 1);

        int countMax = 0;

        for (int f : freq) {
            if (f == maxFreq) {
                countMax++;
            }
        }
        return max((int)tasks.size(), slots + countMax);
    }
};