class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char,int>mp; //{alpha , index}
        int left=0,right=0;
        int maxilen=0;
        while(right<len){
            char ch = s[right];
            if(mp.find(ch)!=mp.end()){
                if(mp[ch]>=left){
                    left = mp[ch]+1;
                }
            }
            int length=right-left+1;
            maxilen = max(maxilen,length);
            mp[ch]=right;
            right++;
        }
        return maxilen;
    }
};