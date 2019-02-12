/*
 * =====================================================================================
 *
 *       Filename:  变参函数.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/02/11 12时17分44秒
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

int max_int(int num, ...) {
    int ans = 0, temp;
    va_list arg;
    va_start(arg, num);
    while (num--) {
        temp = va_arg(arg, int);
        printf("%d\n", temp);
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_int(2, 2, 3));
    return 0;
}
