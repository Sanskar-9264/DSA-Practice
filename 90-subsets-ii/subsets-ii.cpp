class Solution {
public:
    void getallsubset(vector<int>& nums,vector<int>& ans , int i , vector<vector<int>> &allsubset){
        if(i == nums.size()){
            allsubset.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getallsubset(nums,ans,i+1,allsubset);

        ans.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[i] == nums[idx]){
            idx++;
        }
        getallsubset(nums,ans,idx,allsubset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allsubset;
        vector<int>ans;
        sort(nums.begin(),nums.end());

        getallsubset(nums,ans,0,allsubset);
        return allsubset;
    }
};