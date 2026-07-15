class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        vector<pair<char, int>> v(mp.begin(), mp.end());


        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        string ans;
        for (const auto &it : v) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};