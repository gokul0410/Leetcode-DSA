class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>>mp;
        for(auto it : reservedSeats){
            int r = it[0], c=it[1];
            mp[r].push_back(c);
        }
        int result =0;
        for(auto it:mp){
            unordered_set<int>st(it.second.begin(),it.second.end());
            bool first = !st.count(2)&& !st.count(3) && !st.count(4) && !st.count(5);
            bool second = !st.count(4)&& !st.count(5) && !st.count(6) && !st.count(7);
            bool third = !st.count(6)&& !st.count(7) && !st.count(8) && !st.count(9);
            if(first && third) result+=2;
            else if(first || second || third) result++;
        }
        int sz = mp.size();
        result+= ((n-sz) *2 );
        return result;
    }
};