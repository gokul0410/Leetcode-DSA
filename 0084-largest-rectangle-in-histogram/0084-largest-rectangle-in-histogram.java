class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] right = new int[n];
        int[] left = new int [n];
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<n;i++){
            while(!st.isEmpty() && heights[st.peek()]>=heights[i])
                st.pop();
            if(st.isEmpty()) right[i] = -1;
            else right[i] = st.peek();
            st.push(i);
        }
        while(!st.isEmpty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty() && heights[st.peek()]>=heights[i])
                st.pop();
            if(st.isEmpty()) left[i] =n;
            else left[i] = st.peek();
            st.push(i); 
        }
        int maxArea = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int breadth = left[i]-right[i]-1;
            int area = breadth* heights[i];
            maxArea = Math.max(maxArea , area);
        }
        return maxArea;
    }
}