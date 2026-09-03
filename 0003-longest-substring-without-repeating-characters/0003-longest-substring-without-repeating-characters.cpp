class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int count = 0;
        int ans = INT_MIN;
        for(int right = 0; right<=s.length(); right++){
            mp[s[right]]++;
            count = right - left;
            ans = max(ans,count);

            while(mp[s[right]] >1){
                mp[s[left]]--;
                left++;
                count = right - left;
                ans = max(ans, count);
            }
        }
        return ans;
    }
};