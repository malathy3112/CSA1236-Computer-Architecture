#include <stdio.h>
int main()  
{  
    int num, binary_num, hexa_num = 0, base = 1, rem;  
    printf (" Enter a binary number\n");  
    scanf (" %d", &num); 
    binary_num = num; 
    while ( num > 0)  
    {  
        rem = num % 10; 
        hexa_num = hexa_num + rem * base;  
        num = num / 10;  
        base = base * 16;  
    }  
  
    printf ( " The binary number is %d \t", binary_num); 
    printf (" \n The hexa number is %d \t", hexa_num);    
}
