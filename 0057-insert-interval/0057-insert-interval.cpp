class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& ni) {
        if(nums.size() == 0) {
            return {ni};
        }
        
        int low = 0;
        vector<vector<int>> v;
        
        // Insert intervals before ni
        while (low < nums.size() && nums[low][1] < ni[0]) {
            v.push_back(nums[low++]);
        }

        // Merge intervals overlapping with ni
        while (low < nums.size() && nums[low][0] <= ni[1]) {
            ni[0] = min(ni[0], nums[low][0]);
            ni[1] = max(ni[1], nums[low][1]);
            low++;
        }
        v.push_back(ni);

        // Insert remaining intervals
        while (low < nums.size()) {
            v.push_back(nums[low++]);
        }

        return v;
    }
};
