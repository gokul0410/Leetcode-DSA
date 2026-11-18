class Solution {
public:
    int minChanges(string s) {
        int len = s.length();
        int result = 0;
        for(int i=1;i<len;i+=2){
            if(s[i]!=s[i-1]) result++;
        }
        return result;
    }
};