/*
 * =====================================================================================
 *
 *       Filename:  print.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/02/12 22时35分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>

int __pass(va_list *args) { return 0; }

int __decimal(va_list *args) {
    int number = va_arg(*args, int);
    uint32_t temp_number = number;
    int ret = 0, k = 0, flag = (number < 0);
    if (flag) temp_number = -number;
    #define PUT(ch) putc(ch, stdout), ret++;
    if (temp_number == 0) {
        PUT('0');
        goto out;
    }
    if (flag) PUT('-');
    k = (uint32_t)log10(temp_number);
    do {
        PUT(temp_number / (uint32_t)pow(10, k) + '0');
        temp_number %= (uint32_t)pow(10, k);
    } while (k--);
    #undef PUT
out :
    return ret;
}

int print(const char *frm, ...) {
    int ret = 0;
    int (*hash_func[128])(va_list *);
    for (int i = 0; i < 128; i++) {
        hash_func[i] = __pass;
    }
    hash_func['d'] = __decimal;
    
    va_list args;
    va_start(args, frm);
    while (frm[0]) {
        switch (frm[0]) {
            case '%': 
                frm++;
                ret += hash_func[frm[0]](&args);
                break;
            default :
                putc(frm[0], stdout);
                ret++;
                break;
        }
        frm++;
    }
    return ret;
}

int main() {
    print("hello word\n");
    print("number : %d %d\n", 120, 110);
    print("number : %d %d\n", INT32_MAX, INT32_MIN);
    
    return 0;
}
