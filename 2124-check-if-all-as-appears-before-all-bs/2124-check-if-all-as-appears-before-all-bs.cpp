class Solution {
public:
    bool checkString(string s) {
        int a = 0;
        for(auto it : s){
            if(it =='a')a++;
        }
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == 'b'){
                if(i!=a) return false;
                return true;
            }
        }
        return true;
    }
};