/*############################################################################*/
/*HW07_Busra_Nur_Altunbas_121044076_part1.c                                   */
/*Written by Busra Nur Altunbas on April 14, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*A: Finds and returns size of a string.                                      */
/*B: Finds how many times a given string is used in a given string.           */
/*Inputs:                                                                     */
/*    Variables                                                               */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define MAXSIZE 100
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/

int find_size(const char *string);
int char_number(const char *string, const char *wish_to_find);

/*START_OF_MAIN*/
int main()
{
    char string[MAXSIZE];
    char wish_to_find[MAXSIZE];
    int size,count=0;
    /*END_OF_VARIABLES*/
    printf("Stringinizi giriniz:");
    fgets(string,MAXSIZE,stdin);
    size = find_size(string);
    printf("Stringin size'i %d.\n",size);
    printf("Bulmak istediginiz stringi giriniz:");
    fgets(wish_to_find,MAXSIZE,stdin);
    count = char_number(string, wish_to_find);
    printf("%d kez kullanildi.\n",count);
    return 0;
    /*END_OF_MAIN*/
}
/*Girilen stringin size'ini bulur ve return eder.*/
int find_size(const char *string)
{
    int size;
    if(string[0] == '\n') 
        return  0;
    else if(string[0] == '\0')
        return  0;
    else
        return (1 + find_size(&string[1]));

    
}
/*Girilen stringde aranan stringin sayisini bulur ve return eder.*/
int char_number(const char *string, const char *wish_to_find)
{
    int count,size;
    size = find_size(wish_to_find);
    
    if(string[0]=='\n') 
        count = 0;
    else if(string[0]=='\0')
        count = 0;
    else 
    {
        count = (char_number(&string[1],wish_to_find));
        if(string[0] == wish_to_find[0])
        {
            if ((strncmp(string,wish_to_find,size))==0)
                count++;
        
        }
          
    }  

    return count;
}
/*############################################################################*/
/*                End of HW07_Busra_Nur_Altunbas_121044076_part1.c            */
/*############################################################################*/
