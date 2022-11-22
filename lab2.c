#include <stdio.h>


/* Tiegan Cozzie
 * Csci 112
 * September 9, 2022
 * Lab 2 */

int getNumber(void){ // gets number from user
    printf("Enter a number to check (0 to end): ");
    int num;
    scanf(" %d",&num);
    return(num); 
}

int main(void){
    int in=getNumber(); // gets number from user
    while(in!=0){ // if user enters "0" then program ends
        int temp=in;
        int reverseNum=0;
        int remainder=0;
        int total=0;
        while(temp!=0){ // checks to see if loop gets to the end of number
            remainder=temp%10; // grabs the last int from users whole input
            total+=remainder; // totals all numbers together from users input
            reverseNum=reverseNum*10+remainder; // reversing the whole number the user inputed
            temp/=10; //removes the last number just read from the inputed integer
        }
        while(reverseNum!=0){ // returning the reversed integer back to normal for printing
            remainder=reverseNum%10; // grabs the last int from the reversed input
            printf("%d ",remainder); // prints that last number (first number from original input)
            reverseNum/=10; // removes the last number just read from the reversed integer
            if(reverseNum==0){ // if there are no more numbers in the integer it will finish the equation
                printf("= %d\n",total);
            }else{ // adds a "+" if there are still numbers remaining to be read
                printf("+ ");
            }
        }
        if(total%9==0){ // checks if number is divisible by 9
            printf("Since %d is divisible by 9, %d is divisible by 9\n",total,in);
        }else{
            printf("Since %d is not divisible by 9, %d is not divisible by 9\n",total,in);
        }
        in=getNumber(); // asks for a new input by the user and loops again
    }
    return(0);
}
