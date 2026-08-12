class Solution {
public:

    void getper(vector<int>&nums , int idx , vector<vector<int>> &ans){

        if(idx == nums.size()){
            ans.push_back({nums});
            return;
        }

        for(int i = idx ; i<nums.size() ; i++){
            swap(nums[idx],nums[i]);
            getper(nums,idx+1,ans);

            //backtracking
            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int idx = 0;
        getper(nums,idx,ans);
        return ans;



    }
};