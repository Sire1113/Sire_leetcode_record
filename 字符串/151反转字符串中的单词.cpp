class Solution {
public:
    string reverseWords(string s) {
        int left{};
        for (int right=0; right<s.length(); right++){
            if (s[right] != ' '){
                s[left] = s[right];
                left++;
            }
            else {
                if (left > 0){
                    s[left]=' ';
                    left++;
                    while (right+1<s.length() && s[right+1]==' ')
                        right++;
                }
            }
        }
        left = (s[left-1] == ' ')? left -1: left;
        s.resize(left);
        reverse(s.begin(), s.end());
        left = 0;
        for (int cur=0; cur < s.length(); cur++){
            if (s[cur] == ' '){
                reverse(s.begin()+left, s.begin()+cur);
                left = cur + 1;
            }
            else if (cur == s.length()-1)
                reverse(s.begin()+left, s.end());
        }
        return s;
    }
};