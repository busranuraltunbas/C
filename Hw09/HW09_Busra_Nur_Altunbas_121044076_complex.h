/*############################################################################*/
/*HW09_Busra_Nur_Altunbas_121044076_complex.h                                 */
/*Written by Busra Nur Altunbas on April 28, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*Part2'nin library kismi.                                                    */
/*Inputs:                                                                     */
/*    Variables                                                               */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/
/*----------------------------------------------------------------------------*/
/*                        Structs                                             */
/*----------------------------------------------------------------------------*/
/* User-defined complex number type */
typedef struct {
    double real, imag;

}complex_t;

/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
int scan_complex(complex_t *c);
void print_complex(complex_t c);
complex_t add_complex(complex_t c1, complex_t c2);
complex_t subtract_complex(complex_t c1, complex_t c2);
complex_t multiply_complex(complex_t c1, complex_t c2);
complex_t divide_complex(complex_t c1, complex_t c2);
complex_t abs_complex(complex_t c);

/*----------------------------------------------------------------------------*/
/*                          End of Prototypes                                 */
/*----------------------------------------------------------------------------*/
/*############################################################################*/
/*                End of HW09_Busra_Nur_Altunbas_121044076_complex.h          */
/*############################################################################*/

