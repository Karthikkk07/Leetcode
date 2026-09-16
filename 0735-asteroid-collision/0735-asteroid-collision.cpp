class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                st.push_back(asteroid);
            } 
            else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroid)) {
                    st.pop_back();
                }

                if (!st.empty() && st.back() == abs(asteroid)) {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroid);
                }
            }
        }

        return st;
    }
};