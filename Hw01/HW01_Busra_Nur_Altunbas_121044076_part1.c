/*############################################################################*/
/*HW01_Busra_Nur_Altunbas_121044076_part1.c                                   */
/*-----------------------------------                                         */
/*Written by Busra Nur Altunbas on February 22, 2015                          */
/*                                                                            */
/*Description                                                                 */
/*-----------                                                                 */
/*Evaluates the fog and gof functions                                         */
/*Inputs:                                                                     */
/*  -x and y                                                                  */
/*Outputs:                                                                    */
/*  -Resulting fx, fy, gof and fog                                            */
/*############################################################################*/
/*                                                                            */
/*--------------------------------------------------------------------------  */
/*                               Includes                                     */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
/*----------------------------------------------------------------------------*/
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define Y 8.0
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
double gx(int x, double y);
double fx(int x, double y);
double gof(double fx1, double y);
double fog(double gx1, double y);

/*----------------------------------------------------------------------------*/
/*                          End of Prototypes                                 */
/*----------------------------------------------------------------------------*/

/*START_OF_MAIN*/
int main()
{
    int x;/*Inputtan alinan tanimlama*/
    double y;/*Define olan Y degerini atadigim deger*/
    double fx1,gx1;/*fx ve gx i hesaplama tanimlamalari*/
    FILE * inp;/*Okunacak degerin input dosyasi*/
    y = Y;
    /*END_OF_VARIABLES*/
    
    inp = fopen("Variables.txt","r");/*Okunacak input dosyasinin acilmasi*/
    fscanf(inp,"%d",&x);/*Okumalar*/
    gx1=gx(x,y);/*gx i bulan fonksiyon*/
    fx1=fx(x,y);/*fx i bulan fonksiyon*/
    gof(fx1,y);/*gof u bulan fonksiyon*/
    fog(gx1,y);/*fog u bulan fonksiyon*/
    
    fclose(inp);/*Input dosyasinin kapatilmasi*/
    return 0;
}
/*Bu fonksiyon input file dan x i alir ve y ile gx fonksiyonunu hesaplar.*/
double gx(int x, double y)
{
    double gx;
    FILE * outp;/*Output icin acilan file */
    outp = fopen("Results1.txt","a");/*Output file in acilmasi*/
    gx = x + (1.0 / (x + (y /( 2.0 * x))));/*gx i hesaplama formulu*/
    printf("g(x)= %f\n",gx);
    fprintf(outp,"%f\n",gx);
    fclose(outp);/*Output dosyasinin kapatilmasi*/
    return gx;
}
/*Bu fonksiyon input file dan x i alir ve y ile fx fonksiyonunu hesaplar.*/
double fx(int x, double y)
{
    double fx1,us,us1,us2;
    FILE * outp;/*Output icin acilan file */
    outp = fopen("Results1.txt","a");/*Output file in acilmasi*/
    /*fx i hesaplama formulu*/
    us = (pow(3.0,x) / ((2.0 * x) + 1.0));
    us1 = ((double)(x+y) / (double)x) + (sqrt(log(us)));
    us2 = pow(us1,2.5);
    fx1 = sin(us2);
    printf("f(x)= %f\n",fx1);
    fprintf(outp,"%f\n",fx1);

    fclose(outp);/*Output dosyasinin kapatilmasi*/
    return fx1;
}
/*Bu fonksiyon fx fonksiyonunun sonucunu alir ve y ile gofx fonksiyonunu hesaplar.*/
double gof(double fx1, double y)
{
    double gofx;
    FILE * outp;
    outp = fopen("Results1.txt","a");
    /*fx fonksiyonunu kullanarak gofx in hesaplanmasi*/
    gofx = (double)fx1 + (1.0 / ((double)fx1  + (y /( 2.0 * (double)fx1 ))));
    printf("gof(x)= %f\n",gofx);
    fprintf(outp,"%f\n",gofx);
    
    fclose(outp);
    return 0;
}
/*Bu fonksiyon gx fonksiyonunun sonucunu alir ve y ile fogx fonksiyonunu hesaplar.*/
double fog(double gx1, double y)
{
    double fogx,us,us1,us2;
    FILE * outp;
    outp = fopen("Results1.txt","a");
    /*gx fonksiyonunu kullanarak fogx in hesaplanmasi*/
    us = (pow(3.0,gx1) / ((2.0 * gx1) + 1.0));
    us1 = ((double)(gx1+y) / (double)gx1) + (sqrt(log(us)));
    us2 = pow(us1,2.5);
    fogx = sin(us2);
    printf("fog(x)= %f\n",fogx);
    fprintf(outp,"%f\n",fogx);
    fclose(outp);

    return 0;
}

/*############################################################################*/
/*               End of HW01_Busra_Nur_Altunbas_121044076_part1.c             */
/*############################################################################*/




