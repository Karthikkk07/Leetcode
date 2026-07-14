class Solution {
public:
    string frequencySort(string s) {

    
        int freq[128] = {0};

        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<int, char>> v;

        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                v.push_back({freq[i], char(i)});
            }
        }

        
        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });

     
        string ans;

        for (const auto &it : v) {
            ans.append(it.first, it.second);
        }

        return ans;
    }
};