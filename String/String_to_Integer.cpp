#include<climits>

int atoi(const char *str) {

        bool sign = true, out_range = false;

        //ignore spaces
        while(*str ==' ') str++;

        //sign
        if(*str == '-') sign = false;
        if(*str == '+' || *str == '-') str++;

        int num = 0;

        while(*str >= '0' && *str <= '9')
        {
            if(num > INT_MAX / 10 )
            {
                out_range = true; break;
            }

            num *= 10;

            if( (sign && num >= INT_MAX - *str + '0') ||  (!sign && num - 1 >= INT_MAX - *str + '0') )
            {
                out_range = true; break;
            }

            num += *str - '0';

            str++;
        }

        if(out_range) return sign ? INT_MAX : INT_MIN;

        return sign ? num : -num;
    }
