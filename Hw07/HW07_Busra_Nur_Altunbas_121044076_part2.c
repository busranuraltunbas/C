/*############################################################################*/
/*HW07_Busra_Nur_Altunbas_121044076_part2.c                                   */
/*Written by Busra Nur Altunbas on April 14, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*Calculate distinct ways                                                     */
/*                                                                            */
/*Inputs:                                                                     */
/*    Variables                                                               */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/

int combination(int n , int k);
int ways(int n);
int ways_rec(int n, int k);

/*START_OF_MAIN*/
int main()
{
    int n,k=0,fact=0,comb=0,sum_ways=0,count=0,result=0;
    /*END_OF_VARIABLES*/
    printf("Enter the n value: ");
    scanf("%d",&n);
    /*comb = combination(n ,k);
    printf("combination : %d\n",comb);*/
    /*result = ways_rec(n, k);
    printf("result: %d\n",result);*/
    sum_ways = ways(n);
    printf("You can climb in %d different ways.\n",sum_ways);
    return 0;
    /*END_OF_MAIN*/
}
/*Kombinasyon islemini yapan fonksiyon.*/
int combination(int n , int k)
{
    int comb;
    if (k==0 || k>=n)
        return 1;
    comb = combination(n-1, n-k) + combination(n-1, k);
    return  comb;
	

}
/*Tum ihtimalleri toplar.*/
int ways(int n)
{
    int k=0,sum_ways=0;
    int control=n;
    sum_ways += ways_rec(control, k);
    return sum_ways;
}
/*Kombinasyon islemini tum ihtimallerde kullanan fonksiyon.*/
int ways_rec(int n, int k)
{
    int result;
    if(k>n)
        return 0; 
    if (k==n)
        return 1;
    else{
        result = combination(n, k); 
        result += ways_rec(n-1, k+1);
      
    }
    return result;
}
/*############################################################################*/
/*                End of HW07_Busra_Nur_Altunbas_121044076_part2.c            */
/*############################################################################*/


