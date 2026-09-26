class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int totalSum = 0;

        for (int x : cardPoints) {
            totalSum += x;
        }

        int windowSize = n - k;

        if (windowSize == 0) {
            return totalSum;
        }
        int windowSum = 0;

        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i - windowSize];

            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalSum - minWindowSum;
    }
};