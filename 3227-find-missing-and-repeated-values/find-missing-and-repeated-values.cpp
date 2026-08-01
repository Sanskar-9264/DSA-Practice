class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set <int > s ;
        vector <int> vec;
        int n = grid.size();
        int a ;
        int expected_sum = 0 , actual_sum = 0;
        for(int i = 0 ; i <n ; i++){
            for( int j = 0 ; j<n;j++){
                actual_sum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    //repeted
                    a = grid[i][j];
                    vec.push_back(a);
                }
                s.insert(grid[i][j]);
            }   
        }
        //missing 
        expected_sum = (n*n)*(n*n + 1)/2;
        // actual_sum = expected_sum + reapted - missing; 
        vec.push_back( a + expected_sum - actual_sum); 
        return vec;
    }
};