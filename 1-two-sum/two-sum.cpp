class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int , int> m;
        vector <int> ans ;
        int n = nums.size();
        int first , sec;
        for(int i =0 ; i<n ;i++){
            first = nums[i];
            sec = target - first;
            if(m.find(sec) != m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
            }
            m[first] = i;
        }return ans;
    }
};