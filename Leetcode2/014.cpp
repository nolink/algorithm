class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string shortest;
        bool set = false, allMatch = false;
        for(auto s : strs){
            if(!set || s.length() < shortest.length()) shortest = s;
        }
        for(int i=shortest.length();i>0;i--){
            string sub = shortest.substr(0, i);
            allMatch = true;
            for(auto s : strs){
                if(s.compare(0, i, sub) != 0){
                    allMatch = false;
                    break;
                }
            }
            if(allMatch) return sub;
        }
        return "";
    }
};
