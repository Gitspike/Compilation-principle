#include <iostream>
#include <string>
#include <cmath>
#include "check.hpp"

bool consist_of(std::string str, std::string range){ 
   // 判断str是否仅由range中的字符组成 
   for (int i = 0; i < str.length(); i++){
        if (std::string::npos == range.find(str[i])){
            return false;
        }
   }
   return true;
}

std::string type_of (std::string value){
    // 判断以字符串表示的value的类型，同时将参数改为处理过的数据
    if (consist_of(value, "+-1234567890.")){    
        // 数字组成
        if (std::string::npos == value.find('.'))
            return "integer";
        else
            return "real";
    }
    else if(3 == value.length() and '\'' == value[0] and '\'' == value[2] and isalpha(value[1])){
        return "char";
    }
    else{
        return "id";
    }
}
