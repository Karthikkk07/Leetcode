class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>mp; 
        int rank=1;
        for(int i=0;i<sorted.size();i++){
            if(mp.count(sorted[i])==0){
                mp[sorted[i]]=rank;
                rank++;
            }
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};