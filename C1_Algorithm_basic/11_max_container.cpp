class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int hright = height[right];
            int hleft = height[left];
            int h = min(hright,hleft);
            int tmp_area = (right-left)*h;
            max_area = max(max_area,tmp_area);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return max_area;
        }
};