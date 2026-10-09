class Solution {
public:
    int minInsertions(string s) {
        int n= s.length();
        stack<char> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(i<n-1 && s[i+1]==')') i++;
                else ans++;
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else ans++;
            }
        }
        return ans + 2*st.size();
    }
};