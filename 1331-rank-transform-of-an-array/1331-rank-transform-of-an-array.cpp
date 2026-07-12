class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        vector<int>result; vector<int>copy(arr.begin(),arr.end());
        sort(copy.begin(),copy.end()); int cnt=1;
        for(int i=0;i<n;i++){
            if(mp.find(copy[i])!=mp.end()) continue;
            mp[copy[i]]=cnt;
            cnt++;
        }
        for(int i=0;i<n;i++){
            int rank = mp[arr[i]];
            result.push_back(rank);
        }
        return result;
    }
};