class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        for(char c : s1){
            need[c]++;
        }
        int left = 0;
        for(int right = 0; right< s2.length(); right++){
            window[s2[right]]++;
            if(right - left+ 1 > s1.length()){
                window[s2[left]]--;
                if(window[s2[left]] == 0){
                    window.erase(s2[left]);
                }
                left++;
            }
            if(right-left+1 == s1.length()){
                if(need == window){
                    return true;
                }
            }
        }
        return false;
    }
};