class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int water=0;
        while(i<j){
            water = max(water,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return water;
    }
};
