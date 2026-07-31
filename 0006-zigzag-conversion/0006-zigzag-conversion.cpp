class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length())
            return s;
        int index=0, r=1;
        vector<vector<char>>rslt(numRows);
        for(auto &it:s){
            rslt[index].push_back(it);
            if(index==0)
                r=1;
            else if(index==numRows-1)
                r=-1;
            index+=r;
        }
        string result="";
        for(int i=0;i<rslt.size();i++){
            for(int j=0;j<rslt[i].size();j++){
                result+=rslt[i][j];
            }
        }
        return result;
    }
};