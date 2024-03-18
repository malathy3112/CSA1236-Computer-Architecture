#include <stdio.h>
int main()  
{  
    int num, binary_num, octal_num = 0, base = 1, rem;  
    printf (" Enter a binary number\n");  
    scanf (" %d", &num); 
    binary_num = num; 
    while ( num > 0)  
    {  
        rem = num % 10; 
        octal_num = octal_num + rem * base;  
        num = num / 10;  
        base = base * 8;  
    }  
  
    printf ( " The binary number is %d \t", binary_num); 
    printf (" \n The octal number is %d \t", octal_num);    
}
