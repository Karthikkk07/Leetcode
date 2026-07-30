class Solution {
public:
    vector<int> computeLPS(string pattern){
        vector<int>lps(pattern.length(),0);
        int len=0;
        int i=1;
        while (i<pattern.length()){
            if (pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
              }

            else{ 
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }

        }

    return lps;
    }
      int strStr(string haystack, string needle) {

        vector<int> lps = computeLPS(needle);

        int i = 0;
        int j = 0;

        while (i < haystack.length()) {

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.length()) {
                return i - j;
            }

            else if (i < haystack.length() &&
                     haystack[i] != needle[j]) {

                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return -1;
    }
};