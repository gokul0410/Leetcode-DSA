class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        unordered_map<int,int>mp;
        for(auto it:word){
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end());
        int cnt=1,result=0,val=0;
        for(int i=25;i>=0;i--){
            val++;
            result+=(freq[i]*cnt);
            if(val%8 ==0) cnt+=1;
            
        }
        return result;
    }
};