class Solution {
public:
    bool dfs(vector<int>& nums,int mid,int h){
        size_t sum=0;
        for(auto x:nums){
            if(x%mid!=0){
                sum+=1;
            }
            sum+=x/mid;
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int ma=nums[max_element(nums.begin(),nums.end())-nums.begin()];
        int low=1,high=ma;
        int ans=ma;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(dfs(nums,mid,h)){
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