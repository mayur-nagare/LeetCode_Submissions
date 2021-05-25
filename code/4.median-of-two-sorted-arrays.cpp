class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i<nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());

        float mid =0;
        double median = 0;
        if(nums1.size() % 2 ==0){
            mid = (nums1.size()/2) - 1;
            median = (nums1[mid] + nums1[mid+1])/2.0;
            cout<<"even "<<nums1[mid]<<" "<<nums1[mid+1]<<endl;
        }else{
            mid = floor(nums1.size()/2) ;
            median = nums1[mid];
            cout<<"odd"<<mid<<" "<<median<<endl;
        }
        return median;
    }
};