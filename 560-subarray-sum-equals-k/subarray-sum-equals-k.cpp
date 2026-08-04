class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps (n,0) ;//ps -> prefix sum
        int count =0;
        int sum = 0;
        for(int i = 0 ;i<n;i++){
            sum += nums[i];
            ps[i] = sum;
        }
        unordered_map <int,int> m;//ps with frequency
        for(int j =0;j<n;j++){
            if(ps[j] == k) count++;
            int val = ps[j]-k;
            if(m.find(val) != m.end()){
                count = count+m[val]; // m[val] stores frequency
            }
            if(m.find(ps[j]) == m.end()){
                m[ps[j]]=0;
            }
            m[ps[j]]++;
        }
        return count;
        
    }
};