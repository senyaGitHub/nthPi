#include <stdio.h>


long int arctan(long int x,  long int one){
    long int power = one / x;
    long int total = power;
    long int x_squred = x * x;
    long int divisor = 1;
    while(1){
        power = - power / x_squred;
        divisor += 2;
        int delta = power / divisor;
        if(delta == 0) break;
        
        total += delta; 

    }
    return total;  
}

long int arctan_euler(long int x, long int one){
    long int x_squared = x * x;
    long int x_squared_plus_1 = x_squared + 1;
    long int term = (x * one) / x_squared_plus_1;
    long int total = term;
    long int two_n = 2;
    long int divisor;
    while(1){
        divisor = (two_n+1) * x_squared_plus_1;
        term *= two_n;
        term = term / divisor;
        if(term == 0) break;
        total += term;
        two_n += 2;
    }
    return total;
}



int main(void){
    long int x = 4 * arctan(1, 1000000000);
    long int y = 4 * arctan_euler(1, 1000000000000000000);
    printf("%li, this one uses pi michin \n", x);
    printf("%li, this one uses pi michin and Euler's arctan \n", y);
}