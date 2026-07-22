class Solution {
public:

    bool isvalid(vector<int> &nums , int k , int max ){
            int student = 1;
            int pages = 0;

            for(int i =0;i<nums.size();i++){
                if(nums[i]>max){ // edge case 
                    return false;
                }
                if(pages+nums[i] <= max){
                    pages += nums[i];
                }else{
                    student++;
                    pages = nums[i];
                }
            }
            return student>k? false :true;
            
     }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0;
        if(k>n){ //edge case student more than number of books
            return -1;
        }
        for(int i =0 ; i<n;i++){
            sum = sum + nums[i];
        }
        int ans = -1;
        int st=0 , end = sum;
        while(st<=end){
            int mid = st + (end-st)/2;

            if(isvalid(nums , k , mid)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid + 1;
            }
        }return ans;
    }
};