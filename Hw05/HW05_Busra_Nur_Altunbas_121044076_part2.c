/*############################################################################*/
/*HW05_Busra_Nur_Altunbas_121044076_part2.c                                   */
/*Written by Busra Nur Altunbas on March 22, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*Arrayle ilgili islemler                                                     */
/*                                                                            */
/*Inputs:                                                                     */
/*    size and elements of array                                              */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>
/*----------------------------------------------------------------------------*/
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define MAX_SIZE 100
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/

int max_array(int array[MAX_SIZE], int n);
int second_max_array(int array[MAX_SIZE], int n);
int sum_all_array (int array[MAX_SIZE], int n);
int count_array(int array[MAX_SIZE], int n, int value);
bool search_array (int array[MAX_SIZE], int n, int value);

/*START_OF_MAIN*/
int main()
{
    /*START_OF_VARIABLES*/
    int newArray[MAX_SIZE];
    int size;
    int i,j,k,maximum,secondMax,sum,counter,value=0,search=0;
    
    printf("Size array ? : ");

    scanf("%d",&size);
       
    printf("Enter array value : ");
    
    for(i = 0; i < size ; i++)
        scanf("%d",&newArray[i]);
      
   
   printf("My array={");  
   
   for(i = 0; i < size ; i++){
        printf("%d",newArray[i]);
        
        if(i+1 < size)
            printf(",");
   } 
    
    printf("}\n");
    
    printf("++++++++++++++++++++++++++++++++++++++\n");
    maximum = max_array(newArray,size);
    printf("Maximum array is %d\n",maximum);
    
    printf("++++++++++++++++++++++++++++++++++++++\n");
    secondMax = second_max_array(newArray,size);
    printf("Maximum second array is %d\n",secondMax);
    
        
    printf("++++++++++++++++++++++++++++++++++++++\n");
    sum = sum_all_array(newArray,size);
    printf("Sum of all array is %d\n",sum);
    
    
    printf("++++++++++++++ COUNTER ++++++++++++++++\n");
    
    for(j = 0; j < size; j++)
    {
        counter = count_array(newArray,size,newArray[j]);   
        printf("Count of value %d is %d\n",newArray[j],counter);
        
        if(newArray[j] == newArray[j+1]){
            break;
        }
                     
    }
    
    printf("++++++++++++++++++++++++++++++++++++++\n");  
    
    for(k = 0; k < size; k++)
    {
        search = search_array(newArray,size,newArray[k]);   
        /*printf("%d is %d\n",newArray[k],search);*/
        
        if(newArray[k] == newArray[k+1]){
            break;
        }
                     
    }
    /*search_array (newArray, size, value);*/
    printf("++++++++++++++++++++++++++++++++++++++\n");  
      
    
    return 0;
    /*END_OF_MAIN*/
}


/*Arrayin en büyük elemanini bulur.*/

/*************LARGEST*******************/
int max_array(int array[MAX_SIZE], int n)
{
    int largest = array[0];
    int i;
    
    for(i = 0; i < n; i++)
    {
        if(array[i] > largest)
        {

            largest = array[i];
        }
    }
    
    return largest;
}

/*Arrayin en büyük ikinci elemanini bulur.*/
/**************SECOND LARGEST**************/
int second_max_array(int array[MAX_SIZE], int n)
{
    int largest = 1;
    int secondLargest = 0;
    int i,temp;
    
    for(i = 0; i < n; i++)
    {
        if(array[i] > largest)
        {
            secondLargest = largest;
            largest = array[i];
        }
        
        
        else if(array[i] > secondLargest)
        {   
            secondLargest = array[i]; 
        }
    }
    
    
    return secondLargest;   

}

/*Arrayin elemanlarinin toplamlarini bulur.*/
/*************SUM ALL ARRAY*****************/
int sum_all_array (int array[MAX_SIZE], int n)
{
    int sum = 0;
    int i;
    
    for(i = 0; i < n ; i++)
    {
        sum += array[i]; 
    }

    return sum;
}

/*Arrayin elemanlarinin adetlerini bulur.*/
/************COUNT OF VALUE***************/
int count_array(int array[MAX_SIZE], int n, int value)
{
    int counter = 0;
    int i;
    
    for(i = 0; i < n ; i++)
    {
        if(array[i] == value)
        counter++; 
    }

    return counter;
    
}

/*Arrayin elemanlarinin indexlerini bulur.*/
/************INDEX OF VALUES***************/
bool search_array (int array[MAX_SIZE], int n, int value)
{
    int a=0,location=-1;
    for(a = 0; a < n ; a++)
    {
        if((array[a] == value) && (location==-1))
            location=a;
    }
    printf("%d is at [%d]\n",value,location);
   
    return 0;  
}

/*############################################################################*/
/*                End of HW05_Busra_Nur_Altunbas_121044076_part2.c            */
/*############################################################################*/


















