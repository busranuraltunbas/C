/*############################################################################*/
/*HW00_Busra_Nur_Altunbas_121044076_part2.c                                   */
/*-----------------------------------                                         */
/*Written by Busra Nur Altunbas on February 15, 2015                          */
/*                                                                            */
/*Description                                                                 */
/*-----------                                                                 */
/*Takes the 2nd degree polynomial and multiplication that                     */
/*Inputs:                                                                     */
/*  -Coefficients of the 2nd degree two polynomials                           */
/*Outputs:                                                                    */
/*  -Resulting Multiplication of 2nd degree polynomials                       */
/*############################################################################*/
/*                                                                            */
/*--------------------------------------------------------------------------  */
/*                               Includes                                     */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

/*START_OF_MAIN*/
int main()
{
    double x_kare1,x1,c1;/*Ikinci dereceden birinci denklemin kat sayileri*/
    double x_kare2,x2,c2;/*Ikinci dereceden ikinci denklemin kat sayileri*/
    double multp_x_dort,multp_x_kup,multp_x_kare,multp_x,multp;/*Outputlarin katsayileri*/
    /*END_OF_VARIABLES*/
    
    /*Ilk denklemin x^2, x ve sabit degerin katsayileri*/
    printf("Enter the coefficients of the 1st polynomial (from higher to lower order)>");
    scanf("%lf%lf%lf",&x_kare1,&x1,&c1);
    
    /*Iknci denklemin x^2, x ve sabit degerin katsayileri*/
    printf("\nEnter the coefficients of the 2nd polynomial (from higher to lower order)>");
    scanf("%lf%lf%lf",&x_kare2,&x2,&c2);
    
    /*Outputlarin katsayilerinin hesabi*/
    /*x^4 un katsayisinin hesabi*/
    multp_x_dort = x_kare1 * x_kare2;
    /*x^3 un katsayisinin hesabi*/
    multp_x_kup = ((x1 * x_kare2) + (x2 * x_kare1));
    /*x^2 nin katsayisinin hesabi*/
    multp_x_kare = ((x_kare2 * c1) + (x_kare1 * c2) +(x1 * x2));
    /*x in katsayisinin hesabi*/
    multp_x = (x1 * c2) + (x2 * c1);
    /*sabit sayinin hesabi*/
    multp = c1 * c2;

    /*Sonucun denklem seklinde gosterimi*/
    printf("\nThe result:%.1fx^4 + %.1fx^3 + %.1fx^2 + %.1fx + %.1f\n",
    multp_x_dort,multp_x_kup,multp_x_kare,multp_x,multp);
    /*END_OF_MAIN*/
    return 0;
}
/*############################################################################*/
/*               End of HW00_Busra_Nur_Altunbas_121044076_part2.c             */
/*############################################################################*/

