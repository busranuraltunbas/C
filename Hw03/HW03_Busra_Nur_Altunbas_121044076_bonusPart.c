/*############################################################################*/
/*HW03_Busra_Nur_Altunbas_121044076_bonusPart.c                               */
/*Written by Busra Nur Altunbas on March 9, 2015                              */
/*                                                                            */
/*Desciription:                                                               */
/*This program which draw a horizontally diagram of a bouncing ball.          */
/*                                                                            */
/*Inputs:                                                                     */
/*    take heights and points from user                                       */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                         Defines                                            */
/*----------------------------------------------------------------------------*/
#define TRUE 1
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
int draw_hor_diag_of_bb(int first_height, int feet_height, char the_peak_point,
char the_road_point);
int draw_diag_step(int height, int feet_height, char the_peak_point, 
char the_road_point);
int finish_diag(int length);
/*START_OF_MAIN*/
int main()
{
    /*START_OF_VARIABLES*/
    int height,feet_height, length=1,result=0,point=1;
    char the_peak_point,the_road_point;
    /*END_OF_VARIABLES*/
    printf("Enter the height for diagram:");
    scanf("%d",&height);
    printf("Enter the feet_height for diagram:");
    scanf("%d",&feet_height);
    printf("Enter the character for peak_point for diagram:");
    scanf("\n%c",&the_peak_point);
    printf("Enter the character for road_point for diagram:");
    scanf("\n%c",&the_road_point);
    length = (height * feet_height) + height + 1;
    /*point=draw_diag_step(height, feet_height, the_peak_point, the_road_point);*/
    result=draw_hor_diag_of_bb(height,feet_height,the_peak_point,the_road_point);
    /*Grafigin sablonunu cizen fonksiyon*/
    if(finish_diag(length)==TRUE);
        return 1;
    return 0;
    /*END_OF_MAIN*/
}
/*Kullanicidan aldigi degerleri kullanip grafigi cizer.*/
int draw_hor_diag_of_bb(int first_height, int feet_height, char the_peak_point,
char the_road_point)
{
    int i=0,j=0,k=0;
    int result=0,r,length=1;
    printf("^\n");
    
    draw_diag_step(first_height, feet_height, the_peak_point, the_road_point);
    result=((first_height * feet_height*2) * (first_height -1)) + first_height;
    /*printf("result:%d\n",result);*/

    return result;
}
/*Kullanicidan aldigi degerleri kullanip grafigi cizmenin adimini gosterir.*/
int draw_diag_step(int height, int feet_height, char the_peak_point, 
char the_road_point)
{
    int i=0,j=0,k=0,l=0,m=0,n=0,o=0,road=1,space=0,point=1,r=0,abc=0,x=2,a=1;
    road=feet_height*height;
    abc=height;
    for(i=0; i<=height; i++)
    {
        printf("|");
        for(j=(height * (2*i) + x) ; j>=i; j--)
        {
            printf(" ");
        }
        printf("%c",the_peak_point);
        if(i==height)
            break;
        for(k=height; k>i; k--)
        {
            printf(" ");
        }
        printf("\n");
        
        for(o=0; o<feet_height; o++)
        {
            printf("|");
            for(r=height; r>=abc; r--)
            {
                for(l=height-1; l>i; l--)
                {
                    printf(" ");
                }
                printf("%c",the_road_point);
                for(m=1; m<=(2*i)+1; m++)
                {
                    printf(" ");
                
                }
                
                printf("%c",the_road_point);
                for(n=height-1; n>i; n--)
                {
                    printf(" ");
                }
                
            }
            
            printf("\n");
            
        }
    abc--;
    x+=height - i -a ;
    
    }


    point = (height * feet_height * 2 ) + 1;
    
    /*printf("point:%d\n",point);*/
    return point;
} 
/*Grafigin sablonunu cizer.*/
int finish_diag(int length)
{
    int p;
    printf("\nL");
    for(p=0; p<length; p++)
        printf(" - ");
    printf(">\n\n");
    
    return length;
    
}

/*############################################################################*/
/*                End of HW03_Busra_Nur_Altunbas_121044076_bonusPart.c        */
/*############################################################################*/
    
