class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            vector<string> str;
            string temp = "";
            for(int i=0;i<s.length();i++){
                temp+= s[i];
                if((i+1)%k == 0){
                    str.push_back(temp);
                    temp = "";
                }
            }
            if(temp != "") str.push_back(temp);
            temp = ""; s="";
            for(int i=0;i<str.size();i++){
                string val = str[i];
                int sum = 0;
                for(int i=0;i<val.length();i++){
                    sum+= (val[i]-'0');
                }
                s+=to_string(sum);
            }
        }
        return s;
    }
};