class Solution {
public:
    bool isvalid(vector<int>& v ,int m , int middle,int n ){
        int ball = 1 , last_filled_basket = v[0];
        for(int i=1 ;i<n;i++){
            if(v[i]-last_filled_basket >= middle){
                ball++;
                last_filled_basket = v[i];
            }
            if(ball == m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int n = pos.size() ,st = 1 , end = pos[n-1] - pos[0] , ans = -1 ;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(isvalid(pos,m,mid,n)){
                ans = mid;
                st = mid +1;
            }else{
                end = mid -1;
            }
        }
        return ans;
    }
};