/*############################################################################*/
/*HW00_Busra_Nur_Altunbas_121044076_part1.c                                   */
/*-----------------------------------                                         */
/*Written by Busra Nur Altunbas on February 15, 2015                          */
/*                                                                            */
/*Description                                                                 */
/*-----------                                                                 */
/*Takes the Integral of a given 1st degree polynomial                         */
/*Inputs:                                                                     */
/*  -Coefficients of the 1st degree polynomial                                */
/*  -Zero input value of the resulting polynomial                             */
/*Outputs:                                                                    */
/*  -Resulting 2nd degree polynomial                                          */
/*############################################################################*/
/*                                                                            */
/*--------------------------------------------------------------------------  */
/*                               Includes                                     */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

/*START_OF_MAIN*/
int
main(){
    double ia0,ia1;/*coefficients of the input poly*/
    double p0;/*P(0) value of the resulting poly*/
    double ra0,ra1,ra2;/*coefficients of the resulting poly*/
    /*END_OF_VARIABLES*/
    
    /*Get the 1st degree input polynomial*/
    printf("Enter the coefficients of the polynomial (from higher to lower order)>");
    scanf("%lf%lf",&ia1,&ia0);
    
    /*Get the zero input value of the resulting poly*/
    printf("\nEnter P(0) value for the resulting polinomial>");
    scanf("%lf",&p0);
    
    /*Calculate the resulting poly*/
    ra2 = ((double)1/(double)2)*ia1;
    ra1 = ia0;
    ra0 = p0;
    
    /*Output the resulting poly*/
    printf("\nThe resulting polinomial is: %5.3fx^2 + %5.3fx + %5.3f\n",ra2,ra1,ra0);
    
    /*END_OF_MAIN*/
    return 0;
}
/*############################################################################*/
/*               End of HW00_Busra_Nur_Altunbas_121044076_part1.c             */
/*############################################################################*/

