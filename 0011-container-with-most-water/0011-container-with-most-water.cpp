class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0, right =n-1;
        int maxArea = INT_MIN;
        while(left<right){
            int dist = right - left;
            int waterlvl = min(height[right],height[left]);
            maxArea = max(maxArea , dist*waterlvl);
            if(height[left] >height[right]) right--;
            else if(height[left]<height[right]) left++;
            else {
                right -- ; left++;
            }
        }
        return maxArea;
    }
};