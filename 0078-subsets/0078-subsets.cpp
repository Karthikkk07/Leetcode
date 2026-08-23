class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> current ;
        solve (0,nums,current , ans);
        return ans;
    }

    void solve(int index,vector<int>&nums,vector<int>&current,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(current);
            return ;
        }
        solve(index+1,nums,current,ans);
        current.push_back(nums[index]);
        solve(index+1,nums,current,ans);
        current.pop_back();
    }
};