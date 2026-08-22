class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>right(n),left(n);
        stack<int>st;
        //left->right who is smaller than me one to my left 
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()) right[i] = -1;
            else right[i] = st.top();
            st.push(i);
        }
        //clearing the stack 
        while(!st.empty()) st.pop();
        //right->left who is smaller than me to my right 
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()) left[i] = n;
            else left[i] = st.top();
            st.push(i);
        }
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int breadth = left[i]-right[i] -1;
            int area = breadth*heights[i];
            maxi = max(maxi , area);
        }
        return maxi;
    }
};