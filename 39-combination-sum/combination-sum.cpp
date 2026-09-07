class Solution {
public:
    set<vector<int>> s;
    void combsum(vector<int> &arr, int target, vector<int> &combin,vector<vector<int>> &ans,int i){

        if(target==0 ){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }         
            return;
        }
        if(i==arr.size() || target<0){
            return;
        }

        combin.push_back(arr[i]);
        combsum(arr,target-arr[i],combin,ans,i+1);
        combsum(arr,target-arr[i],combin,ans,i);
        combin.pop_back();
        combsum(arr,target,combin,ans,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combin;
        vector<vector<int>>ans;
        combsum(candidates,target,combin,ans,0);
        return ans;
    }
};