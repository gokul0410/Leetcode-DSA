class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> z(n,0);
        z[0] = 0 ; //substring not the whole string 
        for(int i =1 ;i<n;i++){
            int ptr = 0;
            while(i+ptr<n && s[ptr] == s[i+ptr])
                ptr++;
            z[i] = ptr;
        }
        //for(int i=0;i<n;i++) cout<<z[i]<<" ";
        for(int i=1;i<n;i++){
            if(z[i]==0 ) continue;
            string temp = s.substr(0,z[i]);
            //cout<<temp << " ";
            int val=(n/(temp.size()));
            string str= "";
            for(int i=0;i<val;i++)
                str+=temp;
            if(str == s) return true;
        }
        return false;
    }
};