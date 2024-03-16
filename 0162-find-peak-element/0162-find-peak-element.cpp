class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int low=1,high=nums.size()-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else if(nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1]){
                high=mid-1;
            }
            else if(nums[mid-1]>nums[mid] && nums[mid]<nums[mid+1]){
                low=mid+1;
            }
        }
        return nums[nums.size()-1]>=nums[0]?nums.size()-1:0;

    }
};