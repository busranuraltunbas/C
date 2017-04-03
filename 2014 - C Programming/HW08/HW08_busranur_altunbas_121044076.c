/*############################################################################*/
/*HW08_busranur_altunbas_121044076.c                                          */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on April 29, 2014                             */
/*                                                                            */
/*Desciription:                                                               */
/*Part1 alt dizi adedini bulur                                                */
/*Part2 sayilari ekrana basip rakamlari toplar                                */
/*Part3de istenilen fonksiyonu yazma                                          */
/*Inputs:                                                                     */
/*                                                                            */
/*                                                                            */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/


#include<stdio.h>
/*Functions Prototypes*/
int getNumOfIncreasingSubSeq(int arr[], int size);
int printNumberRevesedOrder(int number);
int printNumber(int number);
int evaIF(int x, int y);
    /*Function definitions, etc.*/
int main(){
     /*START_OF_MAIN*/
    int arr[]={1,2,5,0,2};
    int size;
    int number;
    int x,y;
    /*END_OF_VARIABLES*/
    
    /*Part1den istenen alt dizi adedini return eder*/
    printf("%d\n",getNumOfIncreasingSubSeq(arr, 5));
    
    /*Part1deki sayilari ekrana basip toplamlari return eder*/   
    printf("Enter number:");
    scanf("%d",&number);
    /*Bu fonksiyon girilen sayilari ters çeirip tek tek yazip toplamlari return
     eder*/
    printf("Sum : %d\n\n",printNumberRevesedOrder(number));
    /*Bu fonksiyon girilen sayilari oldugu gibi tek tek yazip toplamlari return
     eder*/
    printf("Sum : %d\n\n",printNumber(number));
    
    /*Part3deki istenilen matematik fonksiyonu yapar*/  
    printf("X i giriniz:");/* Degiskenler*/
    scanf("%d",&x);
    printf("Y yi giriniz:");/* Degiskenler*/
    scanf("%d",&y);
    printf("F(%d,%d) = %d\n",x, y, evaIF(x, y));
    /*END_OF_MAIN*/
    return 0;
}
/*Part1den istenen alt dizi adedini return eder*/
int getNumOfIncreasingSubSeq(int arr[], int size){
/*Base case durumlari 3 adettir*/
    if (size == 0)
        return 0;
       
    else if (size == 1)
        return 1;

    if (size == 2){
        if(arr[0] > arr[1])
            return 2;
        else
            return 1;
            
    }
   
    /*Recursive call*/
    /*Sayilari sirayla karsilastirarak alt dizi sayisini return eder */
    /*Eger ilk sayi ikinci sayiden buyukse alt dizi vardır ve size i azaltip 1
     arttırarak adedini tuttum*/
    /*Eger ikinci sayi ilk sayiden buyukse size i azaltıp devam ettim */ 
    if (arr[0] > arr[1]) 
        return 1 + (getNumOfIncreasingSubSeq(&arr[1], size - 1));
    else 
        return  (getNumOfIncreasingSubSeq(&arr[1], size - 1));
    
}

/*Bu fonksiyon girilen sayilari ters çeirip tek tek yazip toplamlari return
eder*/
int printNumberRevesedOrder(int number){
    int recersived_num, sum=0;
    
    if(number==0){
        return 0;
    }
    else{
        /*Sayinin 10 ile modunu alarak son sayisini buldum*/    
        recersived_num = number % 10;
        /*Rakamları topladım*/
        sum = sum + recersived_num;
       
    }
        /*Sayiyi ters cevirdim*/
        printf("%d\n",number%10);
        /*Rakamlarin toplamini return ettim*/
        return sum + printNumberRevesedOrder(number/10);
     
    
}
/*Bu fonksiyon girilen sayilari oldugu gibi tek tek yazip toplamlari return
eder*/
int printNumber(int number){
int recersived_num, sum=0;
    
    if(number==0){
        return 0;
    }
    else{
        /*Sayinin 10 ile modunu alarak son sayisini buldum*/ 
        recersived_num = number % 10;
        /*Rakamları topladım*/
        sum = sum + recersived_num;
       
    }
        
        sum= sum + printNumber(number/10);
        /*Sayiyi oldugu gibi ekrana yazdim*/
        printf("%d\n",recersived_num);
        /*Rakamlarin toplamini return ettim*/
        return sum;

}
/*Part3deki istenilen matematik fonksiyonu yapar*/  
int evaIF(int x, int y){
    int result;
    if( x <= 0 || y <= 0 )
        result = 0; 
    else 
        result = evaIF( x - 1, y) + 2 * evaIF ( x, y - 1) + x + y;
    /*Sonucu return eder*/
    return result;
}


















