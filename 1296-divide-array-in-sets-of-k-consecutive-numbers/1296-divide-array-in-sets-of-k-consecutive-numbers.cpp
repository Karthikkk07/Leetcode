class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        if (nums.size() % k != 0) {
             return false;
        }
        map<int, int> mp;
        for (int card : nums) {
            mp[card]++;
        }
        while (!mp.empty()) {
            int first = mp.begin()->first;

            for (int card = first; card < first + k; card++) {
                if (mp[card] == 0) {
                    return false;
                }
                mp[card]--;
                if (mp[card] == 0) {
                    mp.erase(card);
                }
            }
        }
        return true;
    }
};
