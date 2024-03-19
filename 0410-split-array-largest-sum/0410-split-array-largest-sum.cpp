class Solution {
public:
    bool func(vector<int>& nums, int k,int mid){
        int sum=0;
        int count=1;
        for(auto x:nums){
            if(sum+x<=mid){
                sum+=x;
            }
            else{
                sum=x;
                count++;
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        for(auto x:nums){
            low=max(low,x);
            high+=x;
        }
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(nums,k,mid)){
                cout<<"mid="<<mid<<endl;
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};