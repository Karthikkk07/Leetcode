class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;
        for (int i=0;i<n;i++){
            unordered_map<char,int>freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for (auto it:freq){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                sum+=(maxi-mini);

            }
        }
        return sum;
    }
};