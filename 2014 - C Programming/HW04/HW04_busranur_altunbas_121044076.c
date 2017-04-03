/*############################################################################*/
/*HW04_121044076_part1.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on March 18, 2014                             */
/*                                                                            */
/*Desciription:                                                               */
/*Doing Menu                                                                  */
/*                                                                            */
/*Inputs:                                                                     */
/*products.txt                                                                */
/*                                                                            */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/


#include<stdio.h>
/*Function definitions, etc.*/
int main(){

/*START_OF_MAIN*/
    char letter,type;
    int code,buy,sale,current,num,inp_status;
/* END_OF_VARIABLES */
/*dosyadan okuma veya oluşturma için tercih sundum*/
    printf("Ürünleri nasıl okumak istersiniz?\n");
    printf("Dosyadan ise d ye, oluşturmak için m ye basınız:\n");
    scanf("%c",&letter); 
/*d ye basıldığı sürece file dan okuma yapacak*/
        if(letter == 'd' || letter== 'D'){
    FILE * input;
    input=fopen("products.txt","r");
    fscanf(input,"%d %c %d %d %d",&code,&type,&buy,&sale,&current); 
   
/*menünün consoledan görüntüsü*/
    printf("********************MENU********************\n");
    printf("[1]  List all records\n" );
    printf("[2]  Search by type\n"); 
    printf("[3]  Search by type and code \n"); 
    printf("[4]  Filter by quantity \n"); 
    printf("[5]  Exit\n"); 
    printf("********************************************\n");
    printf("Bir sayı giriniz:");
    scanf("%d",&num);
  
/*menünün ayarlarını burada yaptım*/  
    switch(num){
     
 /*1e basıldığı sürece file daki listeyi consola yazacak*/  		
    case 1: while(inp_status!=EOF){
    printf("%d %c %d %d %d\n",code,type,buy,sale,current);
	fscanf(input,"%d %c %d %d %d\n",&code,&type,&buy,&sale,&current); 
	inp_status=fscanf(input,"%d %c %d %d %d\n",&code,&type,&buy,&sale,&current);
		
        	} break;
      
    }  
/*file ı burada kapattım*/             
 fclose(input);
    }
/*burada dosya oluşturdum*/ 
        else if(letter == 'm' || letter== 'M'){
        FILE * output;
        output=fopen("products.txt","w");
        fprintf(output,"Codu giriniz:%d\n",code);
        fscanf(output,"%d",&code);
        fprintf(output,"type ı giriniz:%c\n",type);
        fscanf(output,"%c",&type);
        fprintf(output,"buy ı giriniz:%d\n",buy);
        fscanf(output,"%d",&buy);
        fprintf(output,"sale i giriniz:%d\n",sale);
        fscanf(output,"%d",&sale);
        fprintf(output,"current i giriniz:%d\n",current);
        fclose(output);
/*oluşan dosyayı kapattım*/
        }
return 0;
}
/*END_OF_MAIN*/






