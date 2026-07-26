class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int closed=0;
        for (int ch:s){
            if (ch=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else{
                    closed++;
                }

            }
        }
        
        return (open+closed);


    }
};