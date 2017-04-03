/*############################################################################*/
/*HW02_121044076_part1.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on March 04, 2014                             */
/*                                                                            */
/*Desciription:                                                               */
/*Write a Boolean Algebra Calculator Program                                  */
/*                                                                            */
/*Inputs:                                                                     */
/* x and y                                                                    */
/*                                                                            */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/



#include<stdio.h>
/*Function definitions, etc.*/

int conj(int x,int y);/*Conjunction ın protipini tanımladım */
int disj(int x,int y);/*Disjunction ın prototipini tanımladım */
int not(int x);/*Negation ın prototipini tanımladım */
int mate(int x,int y);/*Material Implication ın prototipini tanımladım*/
int excl(int x,int y);/*Exclusive Or un prototipini tanımladım */

int main ()
{
    /*START_OF_MAIN*/

    int x,y;
    /*END_OF_VARIABLES*/
    
    /* Oluşturdugum fonksiyonları burada cagırdım */   
    conj(x,y);
    disj(x,y);
    not(x);
    mate(x,y);
    excl(x,y);
    
    return 0;   
}
/* Burada fonksiyonları olusturdum ve iclerini doldurdum */
/* Burada x ve y yi and ledim*/
int conj(int x, int y){
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
    
    /*END_OF_MAIN*/
}



















