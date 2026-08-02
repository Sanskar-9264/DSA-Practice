class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> s;
        int ans ;
        int n = nums.size();
        for(int i =0 ; i<n;i++){

            if(s.find(nums[i]) != s.end()){
                ans = nums[i];
                break;
            }else{
                s.insert(nums[i]);
            }
        }return ans;
    }
};