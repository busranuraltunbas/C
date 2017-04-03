/*############################################################################*/
/*HW03_121044076_part1.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on March 11, 2014                             */
/*                                                                            */
/*Desciription:                                                               */
/*_____________                                                               */
/*                                                                            */
/*Inputs:                                                                     */
/*angle                                                                       */
/*exponent                                                                    */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/

#include<stdio.h>
/*PART1*/
/*Pi  sayısını define ettim*/
#define PI 3.14
double calculateOfTaylor(double angle, int exponent);
/*part1 için taylor teoremine giris icin fonksiyon olusturdum*/


int main()
{
/*START_OF_MAIN*/
    double angle;/* girilmesi gereken acı*/
    int exponent;/*x in ussu*/
    char letter;/*secim icin secenek */
/* END_OF_VARIABLES */    
    printf("%f\n",calculateOfTaylor(angle, exponent));
  
    return 0;
}

double calculateOfTaylor(double angle, int exponent){  
    char letter;
/*Console dan veya ekrandan bilgi almak icin secenek sundum*/    
    printf("(CONSOLE) C or c ,(FILE) F or f \n");
    printf("Enter a letter:\n" );
    scanf("%c",&letter);  
/*Kullanıcı klavyeden c girdigi takdirde consoldan okuma gerceklesecek*/
    if(letter == 'c' || letter == 'C'){
  
    printf("Enter an angle:" );
    scanf("%lf",&angle);
    printf("Enter an exponent:");
    scanf("%d",&exponent);
  
    }
/*Kullanıcı klavyeden f girdigi takdirde filedan okuma gerceklesecek*/
    else if(letter == 'f' || letter== 'F'){
    
    FILE * input;
    input=fopen("Angle.txt","r");
    fscanf(input,"%lf",&angle);
    fscanf(input,"%d",&exponent);
    fclose(input);
    }
    else{
/*Farklı bi harf girildiğinde ise hata verecek */
    printf("ERROR");
    }
    return 0;
   
    }
    
/* END_OF_MAIN */ 













  

