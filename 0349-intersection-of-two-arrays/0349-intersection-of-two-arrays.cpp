class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>result;
        for(auto it:nums1){
            mp[it]++;
        }
        for(auto it :nums2){
            if(mp.find(it)!=mp.end()){
                result.push_back(it);
            }
        }
        unordered_set<int>st(result.begin(),result.end());
        vector<int>fin;
        for(auto it :st){
            fin.push_back(it);
        }
        return fin;
    }
};