class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int>m;
        vector<int> v=score;
        sort(v.begin(),v.end());
        int n=v.size();
        for(int i=0;i<v.size();i++){
            m[v[i]]=n-i;
        }
        vector<string> ans;
        for(auto x:score){
            if(m[x]==1){
                ans.push_back("Gold Medal");
            }
            else if(m[x]==2){
                ans.push_back("Silver Medal");
            }
            else if(m[x]==3){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(m[x]));
            }
        }
        return ans;
    }
};