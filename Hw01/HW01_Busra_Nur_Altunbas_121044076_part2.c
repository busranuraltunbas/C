/*############################################################################*/
/*HW01_Busra_Nur_Altunbas_121044076_part2.c                                   */
/*-----------------------------------                                         */
/*Written by Busra Nur Altunbas on February 22, 2015                          */
/*                                                                            */
/*Description                                                                 */
/*-----------                                                                 */
/*Calculates the f(x,y)                                                       */
/*Inputs:                                                                     */
/*  -Two unknows lineer equations coefficients                                */
/*Outputs:                                                                    */
/*  -Resulting x, y, f(x,y)                                                   */
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
    double cof_x1,cof_y1;/*Birinci denklemin katsayileri*/
    double cof_x2,cof_y2;/*Ikinci denklemin katsayileri*/
    double cof_x,cof_y;/*Hesalanacak denklemin katsayileri*/
    int result1,result2,result1x,result2x;/*Birinci,ikinci denklemin sonuclari*/
    /*xi yok etmek icin iki denklemin de xin katsayisiyle carpilmis hali*/
    int result_x,result_y,sonuc;/*sonuclar icin tanimlamalar*/
    double x1,y1,x2,y2,new_x,new_y;/*x ve y yi bulmak icin tanimlamalar*/
    /*END_OF_VARIABLES*/
    
    FILE * inp1;/*Iki denklemin katsayilarinin bulundugu input dosyasi*/
    FILE * inp2;/*f(x,y) deleminin katsayilerinin bulundugu input dosyasi*/
    FILE * outp;/*f(x,y) fonksiyonun sonuclarinin bulundugu output dosyasi*/
    
    inp1 = fopen("EqCoefficients.txt","r");/*okunacak input dosyasinin acilmasi*/
    inp2 = fopen("FuncCoefficients.txt","r");/*okunacak input dosyasinin acilmasi*/
    outp = fopen("Results2.txt","w");/*Yazilacak output dosyasinin acilmasi*/
    
    fscanf(inp1,"%lf%lf%d",&cof_x1,&cof_y1,&result1);/*Okumalar*/
    fscanf(inp1,"%lf%lf%d",&cof_x2,&cof_y2,&result2);/*Okumalar*/
    fscanf(inp2,"%lf%lf",&cof_x,&cof_y);/*Okumalar*/
    printf("> %.1fx + %.1fy = %d\n",cof_x1,cof_y1,result1);
    printf("> %.1fx + %.1fy = %d\n\n",cof_x2,cof_y2,result2);
    
    /*x ve y degerlerinin bulunmasi icin x in katsayisiyle iki denklemi carpip
    x i goturerek y degerinin bulunmasi */
    /*Birinci denklemin 2.xin katsayisiyle carpilmasi*/
    x1 = cof_x1 * cof_x2;
    y1 = cof_y1 * cof_x2;
    result1x = result1 * cof_x2;
    
    /*Ikinci denklemin 1.xin katsayisiyle carpilmasi*/
    x2 = cof_x2 * cof_x1;
    y2 = cof_y2 * cof_x1;
    result2x = result2 * cof_x1;
    
    /*x ve y degerlerinin bulunmasi*/
    new_y = (double)(result1x - result2x) / (y1 - y2);/*y nin degeri*/
    new_x = ((double)result1 - (cof_y1 * new_y)) / cof_x1;/*x in degeri*/
    
    /*f(x,y) nin hesaplanmasi*/
    result_x = cof_x * new_x;/*x in inputtaki x in katsayisiyle carpimi*/
    result_y = cof_y * new_y;/*y nin inputtaki y nin katsayisiyle carpimi */
    sonuc = result_x + result_y;/*f(x,y) nin sonucu*/
    
    fprintf(outp,"%.0f %.0f %d\n",new_x,new_y,sonuc);
    printf("%.0f  %.0f  %d\n",new_x,new_y,sonuc);
    
    fclose(inp1);/*Dosyanin kapatilmasi*/
    fclose(inp2);/*Dosyanin kapatilmasi*/
    fclose(outp);/*Dosyanin kapatilmasi*/
      
    return 0;
}
/*############################################################################*/
/*               End of HW01_Busra_Nur_Altunbas_121044076_part2.c             */
/*############################################################################*/

