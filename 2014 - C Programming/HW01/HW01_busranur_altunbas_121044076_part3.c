/*############################################################################*/
/*HW01_121044076_part2.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on February 24, 2014                          */
/*                                                                            */
/*Desciription:                                                               */
/*_____________                                                               */
/* Money Account                                                              */
/*Inputs:                                                                     */
/*Input File                                                                  */
/*                                                                            */
/*Outputs:                                                                    */
/* Result: Prices                                                             */
/*############################################################################*/


#include<stdio.h>
#include<math.h>
int main()
{
    /*START_OF_MAIN*/
    /* Verilerimi sırasıyla tipine göre tanımladım */
    int itemc1,amountitem1;
    double totalcost1;
    int itemc2,amountitem2;
    double totalcost2;
    int itemc3,amountitem3;
    double totalcost3;
    int itemc4,amountitem4;
    double totalcost4;
    double unitPrice1, unitPrice2, unitPrice3,unitPrice4;
 
    int Price,TL,kurus;
    /* END_OF_VARIABLES */
    
    /* Dosyayı okuyup yazmak için input ve output dosyalarının oluşturulması; */
    
    FILE * input;
    FILE * output;
    
    /* Input ve output dosyalarını açtım ve okunup yazılması için tanımladım */
    input  = fopen("Buys.txt","r");
    output = fopen("UnitPrices.txt","w");
    
    /* Input için oluşturduğum dosyadan input değerlerini teker teker okudum */
    fscanf(input,"%d%d%lf",&itemc1,&amountitem1,&totalcost1);
    fscanf(input,"%d%d%lf",&itemc2,&amountitem2,&totalcost2);
    fscanf(input,"%d%d%lf",&itemc3,&amountitem3,&totalcost3);
    fscanf(input,"%d%d%lf",&itemc4,&amountitem4,&totalcost4);
    
    /* Calculate the evaluation value */
    /* Alınan ürünlerin fiyatlarını hesapladım*/
    /* Ilk işlemde totalcostu ürün adedine bölerek tek ürün fiyatını buldum  */
    /* Diğer işlemlerde de o ürüne ait totalcostdan ondan önce en son totalcostu
    çıkardım ki sadece o ürünün toplam fiyatıyla işlem yapalım. O ürün fiyatını
    alınan ürün adedine bölerek tek ürün fitatını buldum */
    
    unitPrice1 = totalcost1/amountitem1;
    unitPrice2 = (totalcost2 - totalcost1) / amountitem2;
    unitPrice3 = (totalcost3 - totalcost2) / amountitem3;
    unitPrice4 = (totalcost4 - totalcost3) / amountitem4;
    
    /* Print the result */
    /* Outputta gösterilmesini istediğim verileri bu şekilde gösterdim */
    
    fprintf(output,"%d %.2f\n",itemc1,unitPrice1);
    fprintf(output,"%d  %.2f\n",itemc2,unitPrice2);
    fprintf(output,"%d %.2f\n",itemc3,unitPrice3);
    fprintf(output,"%d %.2f\n",itemc4,unitPrice4);
    
    /* Double integera çevirmek, virgüllü sayıdan kurtulmak ve mod alabilmek 
    için ilk önce fiyatımı (unitPrice1) 10 ile çarptım */
    Price = unitPrice1*10;
    
    kurus = Price%10;/* Kuruşu hesaplamak için 10 modunu aldım */
    
    TL =Price/10; /*Tl kısmı için 10a böldüm; tam sayı kısmını aldım*/
    
    /* Console ekranında ürün kodlarını ve fiyatlarını bu şekilde gösterdim */
    /* Virgülden sonra 0dan sonraki 0lar yazılmadığı için kurusu 10 ile çarparak 
    yazılmasını sağladım  */
    printf("\nThe unit price of item %dis %dTL and %dkuruş",itemc1,TL,kurus*10);
    
    
    /* Double integera çevirmek, virgüllü sayıdan kurtulmak ve mod alabilmek 
    için ilk önce fiyatımı (unitPrice1) 10 ile çarptım */
    Price = unitPrice2*10;
    
    kurus = Price%10;/* Kuruşu hesaplamak için 10 modunu aldım */
    
    TL =Price/10;/*Tl kısmı için 10a böldüm; tam sayı kısmını aldım*/
    
    printf("\nThe unit price of item %dis %dTL and %dkuruş",itemc2,TL,kurus*10);
    
    
    /* Double integera çevirmek, virgüllü sayıdan kurtulmak ve mod alabilmek 
    için ilk önce fiyatımı (unitPrice1) 10 ile çarptım */   
    Price = unitPrice3*10;
    
    kurus = Price%10;/* Kuruşu hesaplamak için 10 modunu aldım */
    
    TL =Price/10;/*Tl kısmı için 10a böldüm; tam sayı kısmını aldım*/
    
    printf("\nThe unit price of item %dis %dTL and %dkuruş",itemc3,TL,kurus*10);
    
    
    /* Double integera çevirmek, virgüllü sayıdan kurtulmak ve mod alabilmek 
    için ilk önce fiyatımı (unitPrice1) 10 ile çarptım */
    Price = unitPrice4*10;
    
    kurus = Price%10;/* Kuruşu hesaplamak için 10 modunu aldım */
    
    TL =Price/10;/*Tl kısmı için 10a böldüm; tam sayı kısmını aldım*/
    
    printf("\nThe unit price of item %dis %dTL and %dkuruş",itemc4,TL,kurus*10);
    
    
    /* Input ve output dosyalarını kapadım */
    fclose(input);
    fclose(output);

    /* END_OF_MAIN */
    return 0;
}
