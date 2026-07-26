class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)<s.size()){
            int st = s.find(part);
            s.erase(st,part.size());
        }return s;
    }
};