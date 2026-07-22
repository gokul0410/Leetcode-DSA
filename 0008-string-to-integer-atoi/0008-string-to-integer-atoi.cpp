class Solution {
public:
    int myAtoi(string s) {
        int sign=1 ;
        int j=0, len= s.length();
        while(j<len && s[j]==' ') j++;
        if(s[j]=='-') {
            sign=-1 ; j++;
        }else if(s[j]=='+'){ j++; }
        long long result=0;
        while(j<len && isdigit(s[j])){
            int digit = s[j]-'0';
            result = result*10 + digit;
            if(result>INT_MAX){
                if(sign==-1) return INT_MIN;
                return INT_MAX;
            } 
            j++;
        }
        return 1LL*result*sign;
    }
};