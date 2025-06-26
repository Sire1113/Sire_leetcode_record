#include "str_utils.h"

namespace mystr{
    void reverse(std::string& s){
        int left{}, right = s.size();
        while (left < right){
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
}