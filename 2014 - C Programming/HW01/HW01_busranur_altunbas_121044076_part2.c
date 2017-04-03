/*############################################################################*/
/*HW01_121044076_part2.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on February 23, 2014                          */
/*                                                                            */
/*Desciription:                                                               */
/*_____________                                                               */
/*Calculate of Average Age                                                    */
/*Inputs:                                                                     */
/* Numbers of Students                                                        */
/* Birth Years of Students                                                    */
/*Outputs:                                                                    */
/* Result: Average Age                                                        */
/*############################################################################*/


#include<stdio.h>
#include<math.h>

int main()
{
    /*START_OF_MAIN*/
    /* Okunmasını istediğim verileri sırasıyla tipine göre tanımladım */
    /* Ogrenci numaralarını ve dogum tarihlerini tanımladım */
    int studentNumber1, birthYear1 ;
    int studentNumber2, birthYear2 ;
    int studentNumber3, birthYear3 ;
    int yas1,yas2,yas3, averageAge;
    
    /* END_OF_VARIABLES */
    
    /* Dosyayı okuyup yazmak için input ve output dosyalarının oluşturulması; */ 
    FILE * input;
    FILE * output;
    
    /* Input ve output dosyalarını açtım ve okunup yazılması için tanımladım */
    input  = fopen("BirthYears.txt","r");
    output = fopen("AverageAges.txt","w");
    
    /* Dosyayı inputtan teker teker okudum */
    fscanf(input,"%d%d",&studentNumber1,&birthYear1);
    fscanf(input,"%d%d",&studentNumber2,&birthYear2);
    fscanf(input,"%d%d",&studentNumber3,&birthYear3);

    /* Calculate the evaluation value */
    /* Her ogrencinin  yaşlarını hesapladım  */
    yas1 = 2014 - birthYear1;
    yas2 = 2014 - birthYear2;
    yas3 = 2014 - birthYear3;
    
    /* Yaşların ortalamasını aldım */
    averageAge = (yas1 + yas2 + yas3)/3;
    
    /* Print the result */
    /* Ortalamayı output dosyasında gösterdim */
    fprintf(output," Average Age:%d\n", averageAge);
    
    /* Ortalamayı terminal ekranında  gösterdim */
    printf(" Average Age:%d\n", averageAge);
    
    /* Input ve output dosyalarını kapadım */
    fclose(input);
    fclose(output);
    
    /* END_OF_MAIN */

return 0;
}
