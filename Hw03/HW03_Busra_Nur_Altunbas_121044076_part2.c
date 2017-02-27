/*############################################################################*/
/*HW03_Busra_Nur_Altunbas_121044076_part2.c                                   */
/*Written by Busra Nur Altunbas on March 9, 2015                              */
/*                                                                            */
/*Desciription:                                                               */
/*Evaluating the vertical distance of the bouncing ball                       */
/*                                                                            */
/*Inputs:                                                                     */
/*    random ratio and random first_height                                    */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>  
/*----------------------------------------------------------------------------*/
/*                         Defines                                            */
/*----------------------------------------------------------------------------*/

#define BIR 1.0
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
int calculate_the_new_height(int first_height,double ratio);
int calculate_the_vertical_distance(int first_height, double ratio);
int count_the_number(int first_height, double ratio);
int report(int first_height, double ratio,FILE* outp);

/*START_OF_MAIN*/
int main()
{
    /*START_OF_VARIABLES*/
    int first_height,count;
    double ratio;
    double rebounce,sum;
    /*END_OF_VARIABLES*/
    
    /*Output icin file acildi*/
    FILE* outp;
    outp=fopen("Result_Table.txt","w");
    
    srand(time(NULL));
    first_height=rand()%30+10;/*first_height icin random atandi.*/
    ratio=rand()%(4+4)*0.1;/*ratio icin random atandi.*/
    
    /**************************************************************************/
    /*printf("Enter the first height between 10 to 40 :");
    scanf("%d",&first_height);
    printf("Enter the ratio between 0.4 to 0.8 :");
    scanf("%lf",&ratio);*/
    /*rebounce=calculate_the_new_height(first_height,ratio);*/
    /*sum=calculate_the_vertical_distance(first_height,ratio);*/
    /*count=count_the_number(first_height,ratio);*/
    /**************************************************************************/
    
    /*Tum islemleri yapan fonksiyon*/
    /*Sonuclari file dosyasina ve consola yazan fonksiyon*/
    report(first_height,ratio,outp);

    fclose(outp);
    /*File dosyasi kapandi*/
    /*END_OF_MAIN*/
    return 0;
}
/*Yalniz rebounce degerini bulan fonksiyon */
int calculate_the_new_height(int first_height,double ratio)
{
    double rebounce=(double)first_height;
    printf("rebounce:%.0f\n",rebounce);
    while(rebounce>=BIR)
    {
        rebounce=rebounce*ratio;
        if(rebounce<=BIR)
            break;
        
    }
    return rebounce;
}
/*Yalniz total degerini bulan fonksiyon */
int calculate_the_vertical_distance(int first_height, double ratio)
{
    double rebounce=(double)first_height;
    double sum=-(first_height);
    while(rebounce>=BIR)
    {
        sum=sum+(rebounce*2);
        printf("sum:%.3f\n",sum);
        rebounce=rebounce*ratio;
        if(rebounce<=BIR)
            break;
        
    }
    return sum;
} 
/*Yalniz count degerini bulan fonksiyon */
int count_the_number(int first_height, double ratio)
{
    double sum=-(first_height);
    double rebounce=(double)first_height;
    int count=1;
    while(rebounce>=BIR)
    {
        sum=sum+(rebounce*2);
        count++;
        rebounce=rebounce*ratio;
        if(rebounce<=BIR)
            break;
    }
    return count;
}
/*Outputlari file ve consola gosteren fonksiyon */
/*Count, rebounce ve total degerlerini direk burda hesaplayip gosterir. */
int report(int first_height, double ratio,FILE* outp)
{
    double sum=-(first_height);
    double rebounce=(double)first_height;
    int count=1;
    /*printf("rebounce:%.0f\n",rebounce);*/
    fprintf(outp,"No - The Rebounching Height -- The Total Vertical Distance\n");
    printf("No - The Rebounching Height -- The Total Vertical Distance\n");
    printf("%d\t\t",count);
    fprintf(outp,"%d\t\t\t",count);
    printf("%.3f\t\t\t",rebounce);
    fprintf(outp,"%.3f\t\t\t\t",rebounce);
    while(rebounce>=BIR)
    {
        sum=sum+(rebounce*2);
        printf("%.3f\n",sum);
        fprintf(outp,"%.3f\n",sum);
        count++;
        rebounce=rebounce*ratio;
        if(rebounce<=BIR)
            break;
        printf("%d\t\t",count);
        fprintf(outp,"%d\t\t\t",count);
        printf("%.3f\t\t\t",rebounce);
        fprintf(outp,"%.3f\t\t\t\t",rebounce);
        
    }
    printf("\nThe bouncing is stopped and the task completed...\n");
    fprintf(outp,"The bouncing is stopped and the task completed...\n");
    return 0;

}
/*############################################################################*/
/*                End of HW03_Busra_Nur_Altunbas_121044076_part2.c            */
/*############################################################################*/




