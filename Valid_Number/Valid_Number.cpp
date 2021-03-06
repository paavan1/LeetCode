#include<stdlib.h>

bool isNumber(const char *s) {

        if(s == NULL) return false;

        //some flags
        bool int_emp = true, dec_start = false, dec_emp = true, exp_start = false, exp_emp = true;

        //ignore the beginning blanks
        while(*s == ' ') s++;

        //ignore the trailing blanks
        const char* end = s;

        if(*end == '\0') return false;

        while(*(end+1) != '\0') end++;

        while(*end == ' ') end--;

        //sign of integral part
        if(*s == '+' || *s == '-') s++;

        //integral part
        while(dec_start == false && exp_start == false && s <= end){
            if(*s >= '0' && *s <= '9'){
                int_emp = false; s++;
            }else if(*s == '.'){
                dec_start = true; s++; break;
            }else if(*s == 'e'){
                exp_start = true; s++; break;
            }else{
                return false;
            }
        }

        if(int_emp == true && dec_start == false) return false;

        //decimal part
        while(dec_start == true && s <= end){
            if(*s >= '0' && *s <= '9'){
                dec_emp = false; s++;
            }else if(*s == 'e'){
                exp_start = true; s++; break;
            }else{
                return false;
            }
        }

        if(int_emp == true && dec_emp == true) return false;

        //sign of exponential part
        if(*s == '+' || *s == '-') s++;

        //exponential part
        while(exp_start == true && s <= end){
            if(*s >= '0' && *s <= '9'){
                exp_emp = false; s++;
            }else{
                return false;
            }
        }

        if(exp_start == true && exp_emp == true) return false;
        return true;
    }
