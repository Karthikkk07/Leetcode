class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        sort(strs.begin(),strs.end());
        string first=strs.front();
        string second=strs.back();
        string ans="";
        for (int i=0;i<min(first.size(),second.size());i++){
            if(first[i]!=second[i]){
                break;
            }
            ans+=first[i];
        }
        return ans;
    }
};