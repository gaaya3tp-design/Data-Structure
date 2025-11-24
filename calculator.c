#include <stdio.h>
int main()
{
    int num1, num2, add_result, sub_result, mul_result, div_result, mod_result;
    num1 = 10;
    num2 = 20;
    add_result = num1 + num2;
    sub_result = num1 - num2;
    mul_result = num1 * num2;
    div_result = num1 / num2;  
    mod_result = num1 % num2;
    printf("Addition: %d\n", add_result);
    printf("Subtraction: %d\n", sub_result);
    printf("Multiplication: %d\n", mul_result);
    printf("Division: %d\n", div_result);
    printf("Modulus: %d\n", mod_result);
    return 0;
}
