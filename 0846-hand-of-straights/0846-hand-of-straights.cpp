
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        map<int, int> mp;
        for (int card : hand) {
            mp[card]++;
        }
        while (!mp.empty()) {
            int first = mp.begin()->first;

            for (int card = first; card < first + groupSize; card++) {
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
