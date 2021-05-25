class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)
            return 0;
        
        vector<int> left(height.size());
        vector<int> right(height.size());
        
        left[0] = height[0];
        right[height.size()-1] = height.back();
        
        for(int i=1, j=height.size()-2; i<height.size(); i++, j--){
            left[i] = max(left[i-1], height[i]);
            right[j] = max(right[j+1], height[j]);
        }
        int sum = 0;
        for(int i=1; i<height.size(); i++)
            sum += min(left[i],right[i]) - height[i];
        
        
    return sum;
    }
};