class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int levl=0;
        for (char ch:s){
                if (ch=='('){  
                    if(levl>0){ 
                    result+=ch;
                    }
                levl++;
                }
                else if (ch==')'){
                    levl--;
                    if(levl>0){
                        result+=ch;
                    }
                }
        
        }
        return result;
    
    }
};