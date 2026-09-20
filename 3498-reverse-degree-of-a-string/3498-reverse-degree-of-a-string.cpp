class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for(int i=0;i<s.length();i++){
            int val =(s[i]-'a');
            result+=((26-val)*(i+1));
        }
        return result;
    }
};

