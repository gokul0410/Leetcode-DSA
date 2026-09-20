class Solution {
#define ll long long 
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        ll result = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>start,end;
        for(auto it: intervals){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        int i = 0;
        for(auto val: end){
            auto it = upper_bound(start.begin(),start.end(),val);
            int dist = distance(start.begin(),it);
            result+=(dist-i-1); i++;
        }
        return result;
    }
};