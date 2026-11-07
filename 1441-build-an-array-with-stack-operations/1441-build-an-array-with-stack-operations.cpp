class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        //unordered_set<int> nums(target.begin(), target.end());
        vector<string> result;
        //int maxi = *max_element(target.begin(), target.end());
        int ptr = 0;
        for(int i=1;i<=target.back();i++){
            result.push_back("Push");
            if(i == target[ptr]) ptr++;
            else result.push_back("Pop");
        }
        return result;
    }
};