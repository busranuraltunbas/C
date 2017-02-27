/*############################################################################*/
/*HW03_Busra_Nur_Altunbas_121044076_part3.c                                   */
/*Written by Busra Nur Altunbas on March 9, 2015                              */
/*                                                                            */
/*Desciription:                                                               */
/*This program which draw a vertical diagram of a bouncing ball.              */
/*                                                                            */
/*Inputs:                                                                     */
/*    take heights and points from user*/
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/

#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
int draw_ver_diag_of_bb(int first_height, int feet_height, char the_peak_point,
char the_road_point);
int draw_diag_step(int height, int feet_height, char the_peak_point, 
char the_road_point);
int finish_diag(int length);
/*START_OF_MAIN*/
int main()
{
    /*START_OF_VARIABLES*/
    int height,feet_height,point=1,length=1,length1=1,length2=1,result=0;
    char the_peak_point; 
    char the_road_point;
    /*END_OF_VARIABLES*/
    
    /*Kullanicidan cizim icin uzunluklari ve karakterleri alir*/
    printf("Enter the height for diagram:");
    scanf("%d",&height);
    printf("Enter the feet_height for diagram:");
    scanf("%d",&feet_height);
    printf("Enter the character for peak_point for diagram:");
    scanf("\n%c",&the_peak_point);
    printf("Enter the character for road_point for diagram:");
    scanf("\n%c",&the_road_point);
    /*point = draw_diag_step(height, feet_height, the_peak_point, the_road_point);*/
    length = (height * feet_height) + 1;
    /*Seklin tamamini cizen fonksiyon*/
    result = draw_ver_diag_of_bb(height,feet_height,the_peak_point,the_road_point);
    /*Grafigin taslagini cizen fonksiyon*/
    /*Burada istenilen islem 3 kere cagirilir.*/
    length = finish_diag(length);
    result = draw_ver_diag_of_bb(4,4,'x','-');
    length1 = (4 * 4) + 1;
    length1 = finish_diag(length1);
    result = draw_ver_diag_of_bb(2,4,'m','-');
    length2 = (2 * 4) + 1;
    length2 = finish_diag(length2);
    /*END_OF_MAIN*/
    return 0;
}
/*Kullanicidan aldigi degerleri kullanip grafigi cizer.*/
int draw_ver_diag_of_bb(int first_height, int feet_height, char the_peak_point,
char the_road_point)
{
    int result=0,r,length=1;
    printf("^\n");
    for(r=first_height; r>=1; r--)
    {   
       
        result+= (first_height * feet_height * 2)+1;
        draw_diag_step(first_height, feet_height, the_peak_point, the_road_point); 
        first_height--;
    }
    first_height--;
    /*printf("result:%d\n",result);*/
    return result;

}
/*Kullanicidan aldigi degerleri kullanip grafigi cizmenin adimini gosterir.*/
int draw_diag_step(int height, int feet_height, char the_peak_point, 
char the_road_point)
{
    int i,j,k,l,m,n,o,road=1,space=0,point=1;
    road=feet_height*height;
    
    for(i=0; i<height; i++)
    {
        printf("|");
        for(j=0; j<space; j++)
        {
            printf(" ");
        
        }
        for(k=0; k<feet_height; k++)
        {
            printf("%c",the_road_point);
        
        }
        printf("\n");
        space+=feet_height;
    
    }
    printf("|");
    for(l=0; l<space; l++)
    {
        printf(" ");
    
    }
    printf("%c",the_peak_point);
    printf("\n");
    
    
    for(m=0; m<height; m++)
    {
    printf("|");   
        space-=feet_height;        
        for(n=0; n<space; n++ )
        {
            printf(" ");
        }
        
        for(o=0; o<feet_height; o++)
        {
            printf("%c",the_road_point);
        
        }
        printf("\n");
    
    }
    point = (height * feet_height * 2) + 1;
    /*printf("point:%d\n",point);*/
    return point;
}
/*Grafigin sablonunu cizer.*/
int finish_diag(int length)
{
    int p;
    printf("L");
    for(p=0; p<length; p++)
        printf(" - ");
    printf(">\n\n");
    
    return length;
    
}
/*############################################################################*/
/*                End of HW03_Busra_Nur_Altunbas_121044076_part3.c            */
/*############################################################################*/





