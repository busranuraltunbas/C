/******************************************************************************/
/****  written by BUSRA NUR ALTUNBAS			                          *****/
/****  	121044076 , on 2 march,2015				                          *****/
/****  This program guesses an integer number                             *****/
/****  	chooses a random number and                                       *****/          
/****	asks this number to the user			                          *****/
/******************************************************************************/
/*--------------------------------------------------------------------------  */
/*                               Includes                                     */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>  /*for srand */

/**** FUNTIONS PROTOTYPE*  ****/
int RNG(); 			/* choose a random number*/
int tahmin();		/* the user guess a number*/
int CalculateTheDifference(int number, int guess);	/* calculate the difference between users number and random number */

/* if the user find random number he/she will pass*/
/*  otherwise this function leads the user as far away or close the number*/
void WarnThePlayer(int fark,int number);	

int main()
{
    /*START_OF_MAIN*/
    /*START_OF_VARIABLES*/
    int number,guess,fark;
    /*END_OF_VARIABLES*/
    
    number = RNG();
    guess = tahmin();
    fark = CalculateTheDifference(number,guess);
    WarnThePlayer(fark,number);
	
	return 0;
	/*END_OF_MAIN*/
}
int RNG()
{
    int number; /* random number*/
    srand(time(NULL));
    number=rand()%10;
    /*printf("random:%d\n",number);*/
    return number;
}
int tahmin()
{
    int guess; /*user's guess*/ 
    printf("Tahmininizi giriniz:\n");
    scanf("%d",&guess);
    return guess;
}
int CalculateTheDifference(int number, int guess)
{
    int fark; /*teh dişfference between random number and guess*/
    if(number >= guess)
        fark = number - guess;
    else if(guess > number)
        fark = guess - number;
    return fark;
}
void WarnThePlayer(int fark,int number)
{
	int fark1,guess;
    if(fark == 0)	/*if the numbers are the same use win*/
        printf("CONGRADULATION\n");
    else{
        /*  How close the number you are*/
        if(fark >= 5)
            printf("You are too far from the number\n");
        else if(fark >= 3 && fark <5)
            printf("You are far from the number\n");
        else if(fark <= 2 && fark >0)
            printf("You are close to the number\n");
        /*otherwise guess last time*/    
        printf("Tekrar deneyiniz!\n");     
        guess = tahmin();
        fark1 = CalculateTheDifference(guess,number);
        if(fark1 == 0)
	        printf("CONGRADULATION\n");                      
	    else 
        	printf("YOU LOST\n");           
       	}
       	
}




