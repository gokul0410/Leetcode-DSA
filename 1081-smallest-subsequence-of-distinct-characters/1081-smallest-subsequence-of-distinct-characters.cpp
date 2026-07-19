class Solution {
public:
    string smallestSubsequence(string s) {
        int len=s.length();
        vector<int>last(26);
        vector<bool>visited(26,false);
        for(int i=0;i<len;i++){
            last[s[i]-'a']=i;
        }
        stack<char>st;
        for(int i=0;i<len;i++){
            if(visited[s[i]-'a']) continue;
            while(!st.empty() && st.top()>s[i] && last[st.top()-'a']>i){
                visited[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a']=true;
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};