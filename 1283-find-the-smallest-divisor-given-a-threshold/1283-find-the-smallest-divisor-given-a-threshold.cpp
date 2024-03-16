class Solution {
public:
    bool func(vector<int>& nums,int t,int mid){
        int sum=0;
        for(auto x:nums){
            if(x%mid!=0){
                sum+=1;
            }
            sum+=x/mid;
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        size_t low=1;
        size_t high=nums[max_element(nums.begin(),nums.end())-nums.begin()];
        size_t ans=high;
        while(low<=high){
            size_t mid=low+(high-low)/2;
            if(func(nums,t,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};