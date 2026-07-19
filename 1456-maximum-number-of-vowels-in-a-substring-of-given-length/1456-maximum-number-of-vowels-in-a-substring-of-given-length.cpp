class Solution {
public:
    bool isVowel(char ch) { return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'; }
    int maxVowels(string s, int k) {
        int vowels = 0;
        int n = s.size();
        for(int i = 0; i<k; i++){
            if(isVowel(s[i])){
                vowels++;
            }
        }
        int maxvowels = vowels;

        for(int right=k; right<n; right++){
            if(isVowel(s[right-k])){
                vowels--;
            }
            if(isVowel(s[right])){
                vowels++;
            }
            maxvowels = max(maxvowels , vowels);
        }
        return maxvowels;
    }
};