/*############################################################################*/
/*HW01_121044076_part1.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on February 22, 2014                          */
/*                                                                            */
/*Desciription:                                                               */
/*_____________                                                               */
/*Evaluates the Function                                                      */
/*Inputs:                                                                     */
/* Values of a and b                                                          */
/* Operations                                                                 */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/


#include<stdio.h>
#include<math.h>

    /* c ve d yi define olarak tanımladım */
#define c 5 
#define d 8

int main()
{
    /*START_OF_MAIN*/
    /* Okunmasını istediğim verileri tipine göre tanımladım */
    int a,b;/* Inputtan okuyacağım değerler */
    double value1,value2,value3,value4;/*Yapılan işlemler */
    double result;/* Sonuç */
    
    /* END_OF_VARIABLES */
    
    /* Dosyayı okuyup yazmak için input ve output dosyalarının oluşturulması; */
    FILE * inp;
    FILE * outp;   
    
    /* Input ve output dosyalarını açtım ve okunup yazılması için tanımladım */
    inp  = fopen("Variables.txt", "r");
    outp = fopen("Result.txt", "w");
    
    /* Dosyayı inputtan sırasıyla okudum */
    fscanf(inp, "%d%d",&a,&b);

    /* Ekrana sonucu istenilen işlemi yaptım; */
    value1 = pow(((a+b)/(b+1)),3.8); /* ilk işlemi üst alma koduyla yazdım*/
    value2 = sqrt((log(d)/log(3.0)) + (13/7));/* iç parantezde logaritma aldım*/
    /* Ikinci işlemi ise karekök koduyla yazdım*/
    value3 = (a + (d/c)); /* üçüncü işlemde ilk önce kökün içini hesapladım*/
    value4 = pow((value3),(1/3));/* pow koduyla son işlemin küp kökünü yazdım */
    
    /* Son olarak yapılan tüm işlemleri toplayıp resulta asign ettim */
    result = value1 + value2 + value3;
    
    /* Bulduğum sonucu output dosyasında göstermek için bu kodu yazdım */
    fprintf(outp, "result: %.2f\n", result);
    /* Bulunan sonucu terminal ekranında da gösterdim */
    printf("result: %.2f\n",result);
    
    /* Açılan input ve output dosyalarını kapadım */
    fclose(inp);
    fclose(outp);
    
    return 0;
}

