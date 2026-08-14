class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        int left =0 , maxi = INT_MIN;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(left<=right && mp[s[right]]>2){
                mp[s[left]]--;
                left++;
            }
            maxi = max(maxi,right-left+1);
        }
        return maxi;
    }
};