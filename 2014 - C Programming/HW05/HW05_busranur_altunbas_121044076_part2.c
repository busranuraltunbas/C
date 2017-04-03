/*############################################################################*/
/*HW05_121044076_part2.c                                                      */
/*_______________________                                                     */
/*Written by Busra Nur Altunbas on March 25, 2014                             */
/*                                                                            */
/*Desciription:                                                               */
/*Fonksiyonlar yardımıyla istenilen özellikte ekrana karakter basma           */
/*                                                                            */
/*Inputs:                                                                     */
/*                                                                            */
/*                                                                            */
/*Outputs:                                                                    */
/* Result:                                                                    */
/*############################################################################*/


#include<stdio.h>
/*Functions Prototypes*/
void drawReccurOf2Triangles(int m,int n,int k, char c,int e);
void drawReccurOf4Triangles(int m,int n,int k, char c,int e,int rH, int rV);
/*Function definitions, etc.*/
int main(){

/*START_OF_MAIN*/
    int m,n,k,e,rH,rV;
    char c;
/*END_OF_VARIABLES*/    
    printf("enter the height of the pattern (m):\n");
    scanf("%d",&m);
    printf("enter the number of empty columns between each triangle (n):\n");
    scanf("%d",&n);
    printf("enter number of recurrence (k):\n");
    scanf("%d",&k);
    printf("enter the character (c):");
    scanf("\n%c",&c);
    printf("enter the number of empty columns before start of the pattern (e): ");
    scanf("%d",&e);
    printf("horizontal recurrence of the pattern:");
    scanf("%d",&rH);
    printf("vertical recurrence of the pattern:");
    scanf("%d",&rV);
/*Burada yazdıgım fonksiyonları cagırdım*/
    drawReccurOf2Triangles(m,n,k,c,e);
    drawReccurOf4Triangles(m,n,k,c,e,rH,rV);
        
return 0;
/*END_OF_MAIN*/
}
/*Ilk sekil icin olusturdugum fonksiyon*/
    void drawReccurOf2Triangles(int m,int n,int k,char c,int e){
/*i satiri, j sutunu temsil ediyor*/ 
/*p, bosluk icin kullandıgım harf*/ 
/*s, sekli yan yana bastirmak icin kullandıgım harf*/ 
/*l, ikinci patterni bastırmak icin kullandığım harf */ 
/*b, ikinci satırdaki boslugu koymak icin kullandıgım harf*/

    int i,j,p,s,l=1,b=0;
    
    printf("\n\n~~~     2      R E C T A N G L E    ~~~\n\n\n");
   
    for(i=m; i>0; i--){   
        for(p=0; p<e; p++){ /*sekil bası boslugu icin dongu*/
            printf(" ");
        }
        for(p=0; p<b; p++){ /*sekiller arası bosluk icin dongu*/
            printf(" ");
        }
            for(s=0; s<k; s++){ /*sekil dongusu*/
                for(j=0; j<2*i-1; j++){
                    printf("%c",c);
            
                }
                for(p=0; p<n; p++){ /*sekiller arası bosluk icin dongu*/
                    printf(" ");
            
                }
            
                for(m=0; m<l; m++){ /*sekil dongusu*/
                    printf("%c",c);
                }
                for(p=0; p<n; p++){ /*bosluk dongusu*/
                    printf(" ");
            
                }
        }
            l+=2;/*yildiz sayısındaki artıs miktarı*/
            ++b;/*sekiller arası boslugu arttırdım*/
            printf("\n");
    }
    
    }
/******************************************************************************/   
/*Ikinci sekil icin olusturdugum fonksiyonum*/ 
   
    void drawReccurOf4Triangles(int m,int n,int k, char c,int e,int rH, int rV){

    int i,j,p,s,l=1,b=0,a,v;
    int pattern = m;
   
    printf("\n\n~~~     4      R E C T A N G L E    ~~~\n\n\n");


    for(v=0; v<rV; v++){ /*Sekli kac defa alt alta basacagımı gosteren dongu*/
    b = 0;
    l = 1; 
        for(i=m; i>0; i--){
            for(p=0; p<e; p++){ /*sekil bası boslugu icin dongu*/
                printf(" ");
            }
            for(p=0; p<b; p++){ /*sekiller arası bosluk icin dongu*/
                printf(" ");
            }
        
            for(s=0; s<rH; s++){ /*yan yana yildiz basan dongu*/     
        
                for(j=0; j<2*i-1; j++){ /*sekil dongusu*/
                    printf("%c",c);
            
                }
                for(p=0; p<n; p++){ /*bosluk dongusu*/
                    printf(" ");
            
                }
            
                for(pattern=0; pattern<l; pattern++){ /*sekil dongusu*/
                    printf("%c",c);
                }
                for(p=0; p<n; p++){ /*bosluk dongusu*/
                    printf(" ");
            
                }
            }        
    l+=2;/*yildiz sayısındaki artıs miktarı*/
    ++b;/*sekiller arası boslugu arttırdım*/
        printf("\n");
    }
  
    b = 0;
    l = 1;

    pattern = m;
  
    for(i=m; i>0; i--){
        
        for(a = 0; a < m; ++a ){
            printf(" ");
        }       
        
        for(p=0; p<b; p++){ /*sekiller arası bosluk icin dongu*/
            printf(" ");
        }
        
        for(s=0; s<rH; s++){ /*yan yana yildiz basan dongu*/      
        
            for(j=0; j<2*i-1; j++){ /*sekil dongusu*/
                printf("%c",c);
        
            }
            for(p=1; p<n; p++){ /*bosluk dongusu*/
                printf(" ");
            }
        
            for(pattern=0; pattern<l; pattern++){ /*sekil dongusu*/
                printf("%c",c);
            }
            for(p=1; p<n; p++){ /*bosluk dongusu*/
                printf(" ");
            }
        } 
            
        l+=2;/*yildiz sayısındaki artıs miktarı*/
        ++b;/*sekiller arası boslugu arttırdım*/
    
        printf("\n");
    }
    
    }   
   }
   
/****************End Of HW05_busranur_altunbas_121044076_part2******************/    
    
    
    
    
    
 
    
    
    
    
    
    
    
