class Solution {
public:
    bool isvalid(string s){
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return s == s2;
    }
    void getallpart(vector<vector<string>>&ans,vector<string>&partitions ,string s){
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i = 0;i<s.size() ; i++){
            string parts = s.substr(0,i+1);
            if(isvalid(parts)){
                partitions.push_back({parts});
                getallpart(ans,partitions,s.substr(i+1));
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partitions;
        getallpart(ans,partitions,s);
        return ans;
    }
};