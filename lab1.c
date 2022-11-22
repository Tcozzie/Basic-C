/* Tiegan Cozzie
 * Csci112 Lab1
 * September 2, 2022*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float discount20(int total){ // returns the discount recieved by the transaction (20%)
    return(total*.2);
}
float discount15(int total){ // returns the discount recieved by the transaction (15%)
    return(total*.15);
}

bool inMilitary(void){ // determines if user is in the military
    char ans;
    printf("In military (y or n)?\t\t");
    scanf(" %c",&ans);
    switch(ans){
        case('Y'):
        case('y'):
            return(true);
            break;
        case('N'):
        case('n'):
            return(false);
            break;
        default: // if user doesn't enter 'y' or 'n' it ends the program
            printf("ERROR: Bad input\n");
            exit(1); // ends program
            return(false);
    }
}

int main(void){
    float totalSpent;
    float salesTax;
    bool military;
    float discountedTotal;
    printf("Cost of purchase:\t\t$");
    scanf("%f",&totalSpent);
    military=inMilitary();

    if((military==true)&&(totalSpent>=200)){ //if in military and spent over $200 
        discountedTotal=discount20(totalSpent); // gets discount for 20%
        printf("Military discount (20%%)\t\t $%.2f\n",discountedTotal);
        totalSpent=totalSpent-discountedTotal; // subtracts discount from total
        printf("Discounted total\t\t$%.2f\n",totalSpent);
    }
    else if((military==true)&&(totalSpent<200)){ // if in military and spent less than $200
        discountedTotal=discount15(totalSpent); // gets discount for 15%
        printf("Military discount (15%%)\t\t $%.2f\n", discountedTotal);
        totalSpent=totalSpent-discountedTotal; // subtracts discount from total
        printf("Discounted total\t\t $%.2f\n",totalSpent);
    }
    salesTax=totalSpent*.06; // determines the proper sales tax
    printf("Sales tax (6%%)\t\t\t $%.2f\n",salesTax);
    totalSpent=totalSpent+salesTax; // add sales tax to total
    printf("Total\t\t\t\t $%.2f\n",totalSpent);
}



