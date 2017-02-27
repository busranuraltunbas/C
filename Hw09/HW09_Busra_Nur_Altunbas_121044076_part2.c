/*############################################################################*/
/*HW09_Busra_Nur_Altunbas_121044076_part2.c                                   */
/*Written by Busra Nur Altunbas on April 28, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*Part2'nin main kismi.                                                       */
/*Inputs:                                                                     */
/*    Variables                                                               */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
#include"complex.c"

/*START_OF_MAIN*/
int main(void)
{
    complex_t com1,com2;
    /* Gets two complex numbers */
    printf("Enter the real and imaginary parts of a complex number\n");
    printf("seperated by a space> ");
    scan_complex(&com1);
    printf("Enter a second complex number> ");
    scan_complex(&com2);

    /* Forms and displays the sum */
    printf("\n");
    print_complex(com1);
    printf(" + ");
    print_complex(com2);
    printf(" = ");
    print_complex(add_complex(com1,com2));
    
    /* Forms and displays the difference */
    printf("\n\n");
    print_complex(com1);
    printf(" - ");
    print_complex(com2);
    printf(" = ");
    print_complex(subtract_complex(com1,com2));
    
    /* Forms and displays the absolute value of the first number */
    printf("\n\n|");
    print_complex(com1);
    printf("| = ");
    print_complex(abs_complex(com1));
    printf("\n");
    
    return 0;
    
}
/*############################################################################*/
/*                End of HW09_Busra_Nur_Altunbas_121044076_part2.c            */
/*############################################################################*/

