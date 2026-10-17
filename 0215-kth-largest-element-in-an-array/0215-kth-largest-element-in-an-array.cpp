class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> snums=nums;
        sort(snums.begin(),snums.end());
        int n=snums.size();
        int index=n-k;
        return snums[index];
    }
};