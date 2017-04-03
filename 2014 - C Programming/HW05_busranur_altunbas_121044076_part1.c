/*############################################################################*/
/*HW05_121044076_part1.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on March 25, 2014                             */
/*                                                                            */
/*Desciription:                                                               */
/*Para Yatırımı Hesaplayan Algoritma                                          */
/*                                                                            */
/*Inputs:                                                                     */
/*                                                                            */
/*                                                                            */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/


#include<stdio.h>
/*Functions Prototypes*/

char intruments(char ch1);/*Yatırım yapılacak urun fonksiyonu prototipi*/
char operations(char ch);/*Operasyonların fonksiyonun prototipi*/
char trans(char ch);/*Cevirme yapan fonksiyon prototipi*/
char buy(char ch);
char sell(char ch);
char inp(char ch);
char outp(char ch);
char rptfile(char ch);
char rptcnsl(char ch);
char exitt(char ch);

/*Function definitions, etc.*/
int main(){
/*START_OF_MAIN*/
    char ch;
    char ch1;
/*END_OF_VARIABLES*/
/*Yatırım yapılacak urunun secim menusu*/
    printf("*****************INSTRUMENTS*****************\n");
    printf("                 TL: (L or l)\n");
    printf("                 USD: (D or d)\n");
    printf("                 Gold: (G or g)\n");
    printf("                 Investment Fund: (F or f)\n");
    printf("********************************************\n");
    printf("Istediginiz Yatirimin  Kodunu Giriniz:");
    scanf("%c",&ch1);  
 
/*Yapılacak operasyonların secim menusu*/    
    printf("\n*****************OPERATIONS*****************\n");
    printf(" Transaction:(T/t)\n");
    printf(" Buy:(B/b)\n");
    printf(" Sell:(S/s)\n");
    printf(" Input:(I/i)\n");
    printf(" Output:(O/o)\n");
    printf(" Report to File:(F/f)\n");
    printf(" Report to Console:(C/c)\n");
    printf(" Exit:(E/e)\n");
    printf("********************************************\n");
    printf("Istediginiz Islemin Islem Kodunu Giriniz:");
    scanf("\n%c",&ch);
 
 /*Fonksiyonların cagırılması*/   
    intruments(ch1);
    operations(ch);
    trans(ch);
    buy(ch);
    sell(ch);
    inp(ch);
    outp(ch);
    rptfile(ch);
    rptcnsl(ch);
    exitt(ch);
    return 0;
    /*END_OF_MAIN*/
}

/*Yatırım yapılacak urunun fonksiyonu*/
char intruments(char ch1){

}

/*Yapılacak operasyonların fonksiyonu*/
char operations(char ch){

    switch(ch){
        case 'T':
        case 't':printf("%c",trans(ch)); break;
        
        case 'B':
        case 'b':printf("%c",buy(ch)); break;   
         
        case 'S':
        case 's':printf("%c",sell(ch)); break;
        
        case 'I':
        case 'i':printf("%c",inp(ch)); break;
        
        case 'O':
        case 'o':printf("%c",outp(ch)); break;
        
        case 'F':
        case 'f':printf("%c",rptfile(ch)); break;
        
        case 'C': 
        case 'c':printf("%c",rptcnsl(ch)); break;
        
        case 'E':
        case 'e':printf("%c",exitt(ch)); break;
        
    }   
    return 0;
    
}

char trans(char ch){

    return 0;
}
char buy(char ch){

    return 0;
}
char sell(char ch){

    return 0;
}
char inp(char ch){

    return 0;
}
char outp(char ch){

    return 0;
}
char rptfile(char ch){

    return 0;
}
char rptcnsl(char ch){

    return 0;
}
char exitt(char ch){

return 0;
}

/****************End Of HW05_busranur_altunbas_121044076_part1******************/ 






