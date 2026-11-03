class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n = words.size();
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> result;
        for(int i=0;i<n;i++){
            int r1 = 0 , r2 = 0 , r3 = 0;
            for(int j=0;j<words[i].length();j++){
                char ch = tolower(words[i][j]);
                if(row1.find(ch) != string::npos) r1++;
                else if(row2.find(ch)!= string::npos) r2++;
                else r3++;
            }
            if((!r1&&!r2&&r3) || (r1&&!r2&&!r3)|| (!r1&&r2&&!r3))
                result.push_back(words[i]);
        }
        return result;
    }
};