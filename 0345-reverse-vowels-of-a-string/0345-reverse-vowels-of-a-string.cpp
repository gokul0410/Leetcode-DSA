class Solution {
private:
    bool isVowel(char ch){
        char c = tolower(ch);
        if(c=='a'|| c=='e'|| c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int len = s.length();
        string result = "";
        string V ="";
        for(int i=0;i<len;i++){
            char ch = s[i];
            if(isVowel(ch)) V+=ch;
        }
        reverse(V.begin(),V.end());
        int ptr = 0;
        for(int i=0;i<len;i++){
            if(isVowel(s[i])){
                s[i]= V[ptr++];
            }
        }
        return s;
    }
};