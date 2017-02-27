/*############################################################################*/
/*HW01_Busra_Nur_Altunbas_121044076_part3.c                                   */
/*-----------------------------------                                         */
/*Written by Busra Nur Altunbas on February 22, 2015                          */
/*                                                                            */
/*Description                                                                 */
/*-----------                                                                 */
/*Calculates the total fuel cost                                              */
/*Inputs:                                                                     */
/*  -Cars informations                                                        */
/*Outputs:                                                                    */
/*  -Resulting the total fuel cost                                            */
/*############################################################################*/
/*                                                                            */
/*--------------------------------------------------------------------------  */
/*                               Includes                                     */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>

/*START_OF_MAIN*/
int main()
{
    int car1,car2,car3;/*Arabalarin modelleri*/
    double amount1,amount2,amount3;/*Arabalarin benzin litre miktari*/
    double price1,price2,price3;/*Arabalarin benzin fiyati*/
    double total_km1,total_km2,total_km3;/*Arabalarin kac kilometre yaktiklari*/
    double cost1,cost2,cost3;/*Toplam benzin fiyatlari*/
    int new_cost1,new_cost2,new_cost3;/*Gerekli tanimlamalar*/
    int  old_cost1,old_cost2,old_cost3;/*Integer yapmak icin atamalarim*/
    /*END_OF_VARIABLES*/
    
    FILE * inp;/*Araba bilgilerini aldigim input dosyasi*/
    FILE * outp;/*Total benzin fiyatlarini gosterdigim output dosyasi*/
    
    inp = fopen("Cars.txt","r");/*Input dosyasinin acilmasi*/
    outp = fopen("TotalFuelCosts.txt","w");/*Output dosyasinin acilmasi*/
    
    fscanf(inp,"%d%lf%lf%lf",&car1,&amount1,&price1,&total_km1);/*Okumalar*/
    fscanf(inp,"%d%lf%lf%lf",&car2,&amount2,&price2,&total_km2);/*Okumalar*/
    fscanf(inp,"%d%lf%lf%lf",&car3,&amount3,&price3,&total_km3);/*Okumalar*/
    
    cost1 = amount1 * price1 * total_km1;/*Toplam benzin fiyatinin hesaplanmasi*/
    cost2 = amount2 * price2 * total_km2;/*Toplam benzin fiyatinin hesaplanmasi*/
    cost3 = amount3 * price3 * total_km3;/*Toplam benzin fiyatinin hesaplanmasi*/
    
    old_cost1 = (int)cost1;/*Fiyatin tl olarak gosterilmesi icin integera cast olayi*/
    old_cost2 = (int)cost2;/*Fiyatin tl olarak gosterilmesi icin integera cast olayi*/
    old_cost3 = (int)cost3;/*Fiyatin tl olarak gosterilmesi icin integera cast olayi*/
    
    fprintf(outp,"%d %.2f\n",car1,cost1);/*Sonucun output dosyasinda gosterilmesi*/
    fprintf(outp,"%d %.2f\n",car2,cost2);/*Sonucun output dosyasinda gosterilmesi*/
    fprintf(outp,"%d %.2f\n",car3,cost3);/*Sonucun output dosyasinda gosterilmesi*/
    
    /*Fiyatin kurus olarak gosterimi,virgülden sonrasi icin yapilan hesaplama*/
    cost1 = cost1 * 100;
    new_cost1 = (int)cost1%100;
    
    cost2 = cost2 * 100;
    new_cost2 = (int)cost2%100;
    
    cost3 = cost3 * 100;
    new_cost3 = (int)cost3%100;
    
    /*Consola da gosterim*/
    printf("The total fuel cost of the car %d is %d TL %d Kurus.\n",car1,old_cost1,new_cost1);
    printf("The total fuel cost of the car %d is %d TL %d Kurus.\n",car2,old_cost2,new_cost2);
    printf("The total fuel cost of the car %d is %d TL %d Kurus.\n",car3,old_cost3,new_cost3);
    
    fclose(inp);/*Input dosyasinin kapatilmasi*/
    fclose(outp);/*Output dosyasinin kapatilmasi*/
    
    return 0;
}
/*############################################################################*/
/*               End of HW01_Busra_Nur_Altunbas_121044076_part3.c             */
/*############################################################################*/

