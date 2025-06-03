//
// Created by Sire1 on 25-6-3.
//
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int fast=0,slow=0;
        for (;fast<s.length();fast++){
            if (s[fast]!='#'){
                s[slow] = s[fast];
                slow++;
            }
            else {
                if (slow>0){
                    slow--;
                }
            }
        }
        int s_length = slow;
        fast=0,slow=0;
        for (;fast<t.length();fast++){
            if (t[fast]!='#'){
                t[slow] = t[fast];
                slow++;
            }
            else {
                if (slow >0){
                    slow--;
                }
            }
        }
        int s_ptr=0,t_ptr=0,t_length = slow;
        if (t_length!=s_length) return false;
        else{
            for (;s_ptr<s_length;s_ptr++){
                if (s_ptr==t_ptr && s[s_ptr] == t[t_ptr]){
                    t_ptr++;
                }
                else return false;
            }
        }
        return true;
    }
};