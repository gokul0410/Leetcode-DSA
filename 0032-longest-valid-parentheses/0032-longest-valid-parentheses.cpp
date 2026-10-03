class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int result = 0;
        //left -> right checking the longest 
        int open = 0 , close = 0;
        for(auto it : s){
            if(it =='(') open++;
            else close++;
            if(open == close) result = max(result , 2*open);
            //invalid condition
            if(close>open){
                open = 0 ; close = 0 ;
            }
        }
        open = 0 ; close=0;
        /*checking right -> left the longest 
        this is because when there is an surplus '('
        then the valid par can be missed for 
        example (()*/
        for(int i=n-1;i>=0;i--){
            int it = s[i];
            if(it =='(') open++;
            else close++;
            if(open == close) result = max(result , 2*open);
            if(close<open){
                open = 0 ; close = 0 ;
            }
        }
        return result;
    }
};