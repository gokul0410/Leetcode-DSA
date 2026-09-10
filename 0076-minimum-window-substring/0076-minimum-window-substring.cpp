class Solution {
public:
    string minWindow(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        if(l1<l2) return "";
        int best_start = 0 , best_len= INT_MAX;
        int left = 0;
        unordered_map<int,int>need , formed;
        for(auto it : t){
            need[it]++;
        }
        int form= 0 ;
        for(int right = 0 ; right<l1;right++){
            formed[s[right]]++;
            if(need[s[right]]>0 && need[s[right]]>=formed[s[right]])
                form++;
            while(form == l2){
                if(right - left+1< best_len){
                    best_len = right -left +1;
                    best_start = left;
                }
                formed[s[left]]--;
                if(need[s[left]]>0 && formed[s[left]]<need[s[left]] ) {
                form--;
                }
                left++;
            }
        }
        return best_len!=INT_MAX?s.substr(best_start ,best_len):"";
    }
};