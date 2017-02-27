/*############################################################################*/
/*HW03_Busra_Nur_Altunbas_121044076_part1.c                                   */
/*Written by Busra Nur Altunbas on March 9, 2015                              */
/*                                                                            */
/*Desciription:                                                               */
/*Sayi tahmin etme oyunu                                                      */
/*                                                                            */
/*Inputs:                                                                     */
/*    random sayi, kullanicidan number                                        */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>  
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
int RNG(); 			
int tahmin();		
int CalculateTheDifference(int number, int guess);	
int WarnThePlayer(int fark,int number);	
/*START_OF_MAIN*/
int main()
{
    /*START_OF_VARIABLES*/
    int number,guess,fark;
    char ch;
    /*END_OF_VARIABLES*/
    /*Kullanici cikmak isteyene kadar oyuna devam eder. */
	printf("Enter a character from console “p” or “P” for play ");
    printf("and “e” or “E” to exit\n");
    scanf(" %c",&ch);
    number = RNG();
    while((ch=='P') || (ch=='p'))
    {
        if(fark == 0)
        {	
            number = RNG();
            printf("!!CONGRATULATIONS!!\n");
            printf("Do you want to continue?\n“P” or “p” for continue and ");
            printf("“E” or “e” for exit :\n");
            scanf(" %c",&ch);
            if((ch=='E') || (ch=='e'))
	            return 0;
	        else if((ch!='E') || (ch!='e') && (ch!='P') || (ch!='p') ) 
	            printf("You entered wrong character\n"); 
	            return 0;  
            guess = tahmin();
            fark = CalculateTheDifference(number,guess);
            WarnThePlayer(fark,number);
        } 
        else{
            
            guess = tahmin();
            fark = CalculateTheDifference(number,guess);
            WarnThePlayer(fark,number);
        }
    }
    if((ch=='E') || (ch=='e'))
        return 0;
    else if((ch!='E') || (ch!='e') && (ch!='P') || (ch!='p') ) 
        printf("You entered wrong character\n"); 
        
        return 0; 
        /*END_OF_MAIN*/
}
/*Random sayi atar.*/
int RNG()
{
    int number; /* random number*/
    srand(time(NULL));
    number=rand()%10;
    /*printf("random:%d\n",number);*/
    return number;
}
/*Kullanicinin tahmin yaptıgı foknsiyon*/
int tahmin()
{
    int guess; /*user's guess*/ 
    printf("Tahmininizi giriniz:");
    scanf("%d",&guess);
    return guess;
}
/*Tahmin ile random sayinin farkini alarak ayni olup olmadıgını,farkini bulur.*/
int CalculateTheDifference(int number, int guess)
{
    int fark; 
    if(number >= guess)
        fark = number - guess;
    else if(guess > number)
        fark = guess - number;
    return fark;
}
/*Uyarilarin yapildigi fonksiyondur.*/
int WarnThePlayer(int fark,int number)
{
	int fark1,guess;
	char ch;
	    if(fark!=0){
            printf("Try again!\n");     
            if(fark >= 5)
                printf("You are too far from the number\n");
            else if(fark >= 3 && fark <5)
                printf("You are far from the number\n");
            else if(fark <= 2 && fark >0)
                printf("You are close to the number\n");
       	}
}


/*############################################################################*/
/*                End of HW03_Busra_Nur_Altunbas_121044076_part1.c            */
/*############################################################################*/
