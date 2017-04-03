#include<stdio.h>

/*############################################################################*/
/*HW02_121044076_part3.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on March 04, 2014                             */
/*                                                                            */
/*Desciription:                                                               */
/*Doing Menu                                                                  */
/*                                                                            */
/*Inputs:                                                                     */
/*x, y, z                                                                     */
/*                                                                            */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/

#include<stdio.h>
/*Function definitions, etc.*/

int conj(int x,int y);/*Conjunction ın protipini tanımladım */
int disj(int x,int y);/*Disjunction ın prototipini tanımladım */
int not(int x);       /*Negation ın prototipini tanımladım */
int mate(int x,int y);/*Material Implication ın prototipini tanımladım*/
int excl(int x,int y);/*Exclusive Or un prototipini tanımladım */

/* Testimiz icin olusturdugumuz fonksiyonun prototipi */
void testMonotone();

int main ()
{
    /*START_OF_MAIN*/
    
    int x,y,z;
    char ch;
    /* END_OF_VARIABLES */

/* Burada testimiz icin olusturdugumuz fonksiyonu cagırdım */
    testMonotone();
    conj(x,y);
    
/* Burada menu olusturdum */    
    printf("1.Conjunction\n");
    printf("2.Disjunction\n");
    printf("3.Negation\n");
    printf("4.Material Implication\n");
    printf("5.Exclusive Or\n");
    printf("6.Test the calculator with Monotone Laws\n");
    printf("7.Exit\n");
    printf("enter character:\n");
    scanf("%c",&ch);
    
    switch(ch){
        case 'C': printf("%d",conj(x, y)) ; break;
        case 'D': printf("%d",disj(x, y)) ; break;
        case 'N': printf("%d",not(x)) ; break;
        case 'M': printf("%d",mate(x, y)) ; break;
        case 'O': printf("%d",excl(x, y)) ; break;
        case 'T': testMonotone()  ; break;
        case 'E': return 0; break;
        
    }
    
    return 0; 
}

/* Burada fonksiyonları olusturdum ve iclerini doldurdum */
/* Burada x ve y yi and ledim*/
int conj(int x, int y)
{
    if (x==1){
        if (y==1)
            return 1;
        else 
            return 0;
    }  
    if (x==0){
        if (y==1)
            return 0;
        else 
            return 0;
    }
}
/* Burada x ve y yi or ladım*/
int disj(int x, int y){
    if (x==1){
        if(y==1)
            return 1;
        else 
            return 1;
                
    }

    if (x==0){
        if (y==0)
            return 0;
         else 
            return 1;
     }
     

}
/* Burada x in not ını aldım */
int not (int x){
    if (x==1){
        return 0;
    
    }
    else 
        return 1;
}
/* Burada x in not ını aldım, temp1e atadım*/
/* Temp1 ile y yi orladım, temp2 y atadım */
/* yapılan islemi döndürdüm */

int mate (int x, int y){
    int temp1,temp2;
    temp1=not(x);
    temp2=disj(temp1,y);
    return temp2;
}
/* Burada x ve y yi orlayıp temp1e atadım */
/* x ve y yi andleyip temp2ye atadım*/
/* and ledigim x ve ynin not ını aldım,temp3e atadım */
/* temp1 ile temp3 ü and ledim*/
/* yapılan islemi döndürdüm */

int excl (int x, int y){
    int temp1,temp2,temp3,temp4;
    temp1=disj(x,y);
    temp2=conj(x,y);
    temp3=not (temp2);
    temp4=conj(temp1,temp3);
    return temp4;

}
/* Burada test icin fonksiyon olusturdum ve icini doldurdum*/
void testMonotone(){

/* Testimin sonucunu result.txt dosyayı olusturup yazdırdım*/
    int x,y,z; 
    FILE * output;
    output = fopen("result.txt","w");
    
/*1. Associativity of V : x V (y V z) = (x V y) V z*/
/*1.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */

    fprintf(output,"1.kural için:\n");
    
    if (disj(1,(disj(1,1)))==(disj(disj(1,1),1))) 
    fprintf(output,"x=1, y=1, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (disj(1,(disj(1,0)))==(disj(disj(1,1),0))) 
        fprintf(output,"x=1, y=1, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
            
    if (disj(1,(disj(0,1)))==(disj(disj(1,0),1))) 
    fprintf(output,"x=1, y=0, z=1 for TRUE\n");
    else 
    fprintf(output,"FALSE\n");
    
        if (disj(1,(disj(0,0)))==(disj(disj(1,0),0))) 
        fprintf(output,"x=1, y=0, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
    
    if (disj(0,(disj(0,1)))==(disj(disj(0,0),1))) 
    fprintf(output,"x=0, y=0, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE \n");
    
    
        if (disj(0,(disj(1,0)))==(disj(disj(0,1),0))) 
        fprintf(output,"x=0, y=1, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
    
    
    if (disj(0,(disj(1,1)))==(disj(disj(0,1),1))) 
    fprintf(output,"x=0, y=1, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
    
        if (disj(0,(disj(0,0)))==(disj(disj(0,0),0))) 
        fprintf(output,"x=0, y=0, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
    
/* 2.  Associativity of Λ : x Λ (y Λ z) = (x Λ y) Λ z */
/*2.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */
    
    fprintf(output,"\n2.kural için:\n");
    
    if (conj(1,(conj(1,1)))==(conj(conj(1,1),1))) 
    fprintf(output,"x=1, y=1, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (conj(1,(conj(1,0)))==(conj(conj(1,1),0))) 
        fprintf(output,"x=1, y=1, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
        
    if (conj(1,(conj(0,1)))==(conj(conj(1,0),1))) 
    fprintf(output,"x=1, y=0, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
    
        if (conj(1,(conj(0,0)))==(conj(conj(1,0),0))) 
        fprintf(output,"x=1, y=0, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
    
    if (conj(0,(conj(0,1)))==(conj(conj(0,0),1))) 
    fprintf(output,"x=0, y=0, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (conj(0,(conj(1,0)))==(conj(conj(0,1),0))) 
        fprintf(output,"x=0, y=1, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
    if (conj(0,(conj(1,1)))==(conj(conj(0,1),1))) 
    fprintf(output,"x=0, y=1, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (conj(0,(conj(0,0)))==(conj(conj(0,0),0))) 
        fprintf(output,"x=0, y=0, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
/*3. Commutativity of V : x V y = y V x */       
/*3.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */
        
    fprintf(output,"\n3.kural için:\n");
        
    if (disj(1,1)==disj(1,1))
    fprintf(output,"x=1, y=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (disj(1,0)==disj(0,1))
        fprintf(output,"x=1, y=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
    if (disj(0,1)==disj(1,0))
    fprintf(output,"x=0, y=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (disj(0,0)==disj(0,0))
        fprintf(output,"x=0, y=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
/*4. Commutativity of Λ : x Λ y = y Λ x */        
/*4.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */
    fprintf(output,"\n4.kural için:\n");
        
    if (conj(1,1)==conj(1,1))
    fprintf(output,"x=1, y=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (conj(1,0)==conj(0,1))
        fprintf(output,"x=1, y=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
    if (conj(0,1)==conj(1,0))
    fprintf(output,"x=0, y=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n");
    
        if (conj(0,0)==conj(0,0))
        fprintf(output,"x=0, y=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n");
        
/*5. Distributivity of Λ over V : x Λ (y V z) = (x Λ y) V (x Λ z) */        
/*5.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */       
    fprintf(output,"\n5.kural için:\n"); 
     
    if (conj(1,disj(1,1))==disj(conj(1,1),conj(1,1))) 
    fprintf(output,"x=1, y=1, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n"); 
    
        if (conj(1,disj(1,0))==disj(conj(1,1),conj(1,0))) 
        fprintf(output,"x=1, y=1, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n"); 
      
    if (conj(1,disj(0,1))==disj(conj(1,0),conj(1,1))) 
    fprintf(output,"x=1, y=0, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n"); 
    
        if (conj(1,disj(0,0))==disj(conj(1,0),conj(1,0))) 
        fprintf(output,"x=1, y=0, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n"); 
        
    if (conj(0,disj(0,1))==disj(conj(0,0),conj(0,1))) 
    fprintf(output,"x=0, y=0, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n"); 
    
        if (conj(0,disj(1,0))==disj(conj(0,1),conj(0,0))) 
        fprintf(output,"x=0, y=1, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n"); 
    
    if (conj(0,disj(1,1))==disj(conj(0,1),conj(0,1))) 
    fprintf(output,"x=0, y=1, z=1 for TRUE\n");
    else 
    fprintf(output," FALSE\n"); 
    
        if (conj(0,disj(0,0))==disj(conj(0,0),conj(0,0))) 
        fprintf(output,"x=0, y=0, z=0 for TRUE\n");
        else 
        fprintf(output," FALSE\n"); 
        
/*6. Identity for V : x V 0 = x */
/*6.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */        
    fprintf(output,"\n6.kural için:\n");  
    if  (disj(1,0)==1) 
    fprintf(output,"x=1, 0 for TRUE\n");   
    else
    fprintf(output,"FALSE\n");    
        
        if  (disj(0,0)==0) 
        fprintf(output,"x=0, 0 for TRUE\n");   
        else
        fprintf(output,"FALSE\n"); 
/*7. Identity fir Λ : x Λ 1 = x */           
/*7.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */            
    fprintf(output,"\n7.kural için:\n");  
    if  (conj(1,1)==1) 
    fprintf(output,"x=1, 1 for TRUE\n");   
    else
    fprintf(output,"FALSE\n");    
        
        if  (conj(0,1)==0) 
        fprintf(output,"x=0, 1 for TRUE\n");   
        else
        fprintf(output,"FALSE\n");    
/*8. Annihilator for Λ : x Λ 0 = 0 */
/*8.kuralın dogrulugunu her ihtimali deneyerek ispatladım (8 ihtimal) */               
     fprintf(output,"\n8.kural için:\n");  
     if  (conj(1,0)==0) 
     fprintf(output,"x=1, 0 for TRUE\n");   
     else
     fprintf(output,"FALSE\n");    
        
        if  (conj(0,0)==0) 
        fprintf(output,"x=0, 0 for TRUE\n");   
        else
        fprintf(output,"FALSE\n"); 
        
    fclose(output);/*Burada olusturdugum output dosyasını kapadım */
    /*END_OF_MAIN*/
}

















