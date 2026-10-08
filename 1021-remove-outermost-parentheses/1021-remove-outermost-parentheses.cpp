class Solution {
public:
    string removeOuterParentheses(string s) {
        //stack to store {paren , index }
        stack<pair<char,int>> st; int n = s.length();
        set<int>idx; //store the index to be popped
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first =='(' && s[i]==')'){
                int id = st.top().second;
                st.pop();
                //outer paren 
                if(st.empty()){
                    idx.insert(id);
                    idx.insert(i);
                }
            }else st.push({s[i],i});
        }
        string result = "";
        //remove the marked paren 
        for(int i=0;i<n;i++){
            if(!idx.count(i)) result+=s[i];
        }
        return result;
    }
};