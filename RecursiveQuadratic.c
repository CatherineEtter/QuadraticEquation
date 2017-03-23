/*
============================================================
=   Catherine Etter
=   C Program for Programming II | Spring 2017
=   This program will: 
=    Calculate the answer to the quadratic equation 
=    using an explicit method: (8x^2+5x+3) 
=    and a recursive method: f(x)=(x-1)+((16*x)-3)
============================================================
*/

#include <stdio.h>
#include <stdlib.h>


void main(void)
{    
    int getX();
    int RecursiveQuad(int x);
    int ExplicitQuad(int x);
    char again='y';
    char newline;
    int x;
    
    printf(" This program calculates the following quadratic funciton\n");
    printf(" recursively and explicitly: f(x)=%dx^2+%dx+%d \n",8,5,3);
    
    while(again=='y'||again=='Y') //Lets user choose to enter new value if repeat=1.
    {
        x=getX();
        
        printf(" Solved Explicitly: %d\n",ExplicitQuad(x));
        printf(" f(x)=%dx^2+%dx+%d\n\n",8,5,3);
        printf(" Solved Recursivly: %d\n",RecursiveQuad(x));
        printf(" f(x)=f(x-1)+(%dx%d)\n\n",16,-3);
        
        //reads in \n character so fgets() in getX() does not stop at the \n.
        printf("Want to try again? (y/n)"); 
        scanf(" %c%c",&again,&newline);
    }
    
    printf("Goodbye!\n");
}



int getX() //gets value for x.
{
    char str[10];
    int x;
    
    do
    {
        //Uses atoi to protect x from non-ints. Only int parts of doubles are used and letters get converted to 0.
        printf("\nEnter a positive value for x: "); 
        fgets(str,10,stdin);
        x=atoi(str); 
        
        x<0? printf(" Number is not positive\n") : printf(" You Entered: %d\n",x);
        
    }while(x<0); //Runs again if negative number is entered.
    
    return x;
}



int RecursiveQuad(int x) //Solves quadratic formula recursively.
{
    if (x==0) //The recursive part
    {
        return 3;
    }
    else
    {
        return (RecursiveQuad(x-1)+((16*x)-3));
    }
}



int ExplicitQuad(int x) //Solves quadratic formula the standard way.
{
    return ((8*(x*x))+5*x+3);
}
