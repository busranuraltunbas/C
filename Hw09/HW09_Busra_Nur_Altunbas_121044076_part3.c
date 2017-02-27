/*############################################################################*/
/*HW09_Busra_Nur_Altunbas_121044076_part3.c                                   */
/*Written by Busra Nur Altunbas on April 28, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*The program is estimating the number of bacteria.                           */
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
#define SIZE 100
/*----------------------------------------------------------------------------*/
/*                        Structers                                           */
/*----------------------------------------------------------------------------*/
typedef struct {
    int tube1;
    int tube2;
    int tube3;

}triplet_t;

typedef struct {
    int mpn;
    int lower;
    int upper;
    triplet_t triplets;

}Row;
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/

void Into_Binary(FILE *text_input, FILE *binary_output);
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[], int maxsize);

/*START_OF_MAIN*/
int main()
{
    int count=0,maxsize=10,i;
    char c1='-';
    Row bacterias;
    FILE *text_input;
    FILE *binary_output;
    FILE *binary_input_file;
    Row mpn_table[SIZE];
    Into_Binary(text_input, binary_output);
    /*Binary file a yazip yazmadigini okuyarak test ettim.*/
    binary_output = fopen("converted.bin","rb");/*binary file okumasi*/ 
    while(fread(&bacterias,sizeof(Row),1,binary_output)!=0)
    {
        printf("%d%c%d%c%d %d %d %d\n",bacterias.triplets.tube1,c1,
        bacterias.triplets.tube2,c1,bacterias.triplets.tube3,bacterias.mpn,
        bacterias.lower,bacterias.upper);
    
    }
    fclose(binary_output);
   
    count = Load_Mpn_table(binary_input_file,mpn_table,maxsize);
    /*for(i=0; i<count; i++)
    {
        printf("%s\n",mpn_table[i]);
    
    }*/
    return 0;
    /*END_OF_MAIN*/
}
/*Txt file dan degerleri oku ve binary file a yazar.*/
void Into_Binary(FILE *text_input, FILE *binary_output)
{
    char c1,c2;
    Row bacterias;
    text_input = fopen("a.txt","r");
    binary_output = fopen("converted.bin","wb");/*binary file yazmasi*/
    
    while(fscanf(text_input,"%d%c%d%c%d%d%d%d",&bacterias.triplets.tube1,&c1,
         &bacterias.triplets.tube2,&c1,&bacterias.triplets.tube3,&bacterias.mpn,
         &bacterias.lower,&bacterias.upper)!=EOF)
    {
        fwrite(&bacterias,sizeof(Row),1,binary_output);
    
    }
    fclose(text_input);
    fclose(binary_output);
}
/*Binary filedan okudugu degerlerle arrayi doldurur.*/
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[], int maxsize)
{
    Row bacterias;
    int count = 0;
    char c1;
    binary_input_file = fopen("converted.bin","rb");
    while(fread(&bacterias,sizeof(Row),1,binary_input_file)!=0)
    {
        /*printf("%d%c%d%c%d %d %d %d\n",bacterias.triplets.tube1,c1,
        bacterias.triplets.tube2,c1,bacterias.triplets.tube3,bacterias.mpn,
        bacterias.lower,bacterias.upper);*/
        mpn_table[count] = bacterias;
        count++;
    }

    fclose(binary_input_file);
    return count;
}
/*############################################################################*/
/*                End of HW09_Busra_Nur_Altunbas_121044076_part3.c            */
/*############################################################################*/






