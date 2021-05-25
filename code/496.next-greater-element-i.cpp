class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> value(nums1.size(), -1);
        stack<int> st;
        map<int, int> hash;
        
        for (int i=0; i<nums1.size(); i++)
            hash[nums1[i]] = i+1;
        
        int i=0, j=0;
        while(i <= nums1.size() - 1 && j <= nums2.size() - 1 ){
            if(!st.empty() && st.top() < nums2[j])
                while(i <= nums1.size() - 1 && !st.empty()){
                    if(st.top() < nums2[j]){
                        value[hash[st.top()] - 1] = nums2[j];
                        st.pop();
                        i += 1 ;
                    }
                    else
                        break;
                } 
            if(hash[nums2[j]])
                st.push(nums2[j]);
            j++;
            
        }
        return value;
    }
};