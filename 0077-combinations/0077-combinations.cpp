class Solution {
    vector<vector<int>> result;
private:
    void backtrack(int st , int n , int k , vector<int>&arr){
        if(k==0){
            result.push_back(arr);
            return;
        }
        for(int i=st;i<=n;i++){
            arr.push_back(i);
            backtrack(i+1,n,k-1,arr);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(1,n,k,temp);
        return result;
    }
};