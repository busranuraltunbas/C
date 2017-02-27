/*############################################################################*/
/*HW07_Busra_Nur_Altunbas_121044076_part3.c                                   */
/*Written by Busra Nur Altunbas on April 14, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*Find a path on a grid maze                                                  */
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
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define COL_SIZE 5
#define ROW_SIZE 5
/*----------------------------------------------------------------------------*/
typedef enum{notavailable,available,right_down}Grid_t;
typedef enum{FALSE, TRUE}Bool;
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/

void read_table(FILE *input_file, Grid_t table[][COL_SIZE]);
void print_path(char path[][COL_SIZE], int n);
Bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],
int size, int location_x, int location_y);

/*START_OF_MAIN*/
int main()
{
    /*START_OF_VARIABLES*/
    int y,x,sayi,size,n;
    int location_x=0, location_y=0;
    Grid_t table[ROW_SIZE][COL_SIZE];
    char path[ROW_SIZE][COL_SIZE];
    
    /*END_OF_VARIABLES*/
    FILE * input_file;
    /*File okuma yapildi*/
    input_file = fopen("table.txt","r");
    read_table(input_file, table);
    /*Path arrayi en basta junk deger atamasin diye bosluk ile dolduruldu.*/
    for(y=0; y<ROW_SIZE; y++)
    {
        for(x=0; x<COL_SIZE; x++)
        {
        
            path[y][x]=' ';
        
        }
    
    }
    find_path(table, path, size, location_x, location_y);
    print_path(path, n);

    return 0;
    /*END_OF_MAIN*/
}
/*File'dan okudugu degerleri arraya atar.*/
void read_table(FILE *input_file, Grid_t table[][COL_SIZE])
{
    int y,x,sayi;
    for(y=0; y<ROW_SIZE; y++)
    {
       
        for(x=0; x<COL_SIZE; x++)
        {
           
             if(!feof(input_file))
             {
                fscanf(input_file,"%d",&sayi);
                table[y][x]= sayi;
             }
    
        }
        
    }
    /*File'dan okuyup arraye yazdigi degerleri ekrana basar.*/
    for(y=0; y<ROW_SIZE; y++)
    {
        for(x=0; x<COL_SIZE; x++)
        {
        
            printf(" %d",table[y][x]);
        
        }
    
        printf("\n");
    }


}
/*Labirentin izledigi yolu basar.*/
void print_path(char path[][COL_SIZE], int n){
    int y,x;
    printf(" Labirentin cikis icin izledigi yol\n");
    for(y=0; y<ROW_SIZE; y++)
    {
        for(x=0; x<COL_SIZE; x++)
        {
            
            printf(" %c",path[y][x]);
           
        
        }
    
        printf("\n");
    }
    return;


}
/*Recursive ile arraydeki degerlere gore labirentte hareket eder.*/
/*1 ise asagı, yukari, sag, sol hareket eder.*/
/*2 ise sag asagi yani capraz hareket eder.*/
/*0 ise hareket etmez.*/
Bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],
                                         int size, int location_x, int location_y)
{
    if( location_x < 0 || location_x >= COL_SIZE )
        return FALSE;
    if( location_y < 0 || location_y >= ROW_SIZE )
        return FALSE;  
    if( (table[location_y][location_x] == notavailable)) 
        return FALSE;
    if( location_y == ROW_SIZE-1 && location_x == COL_SIZE-1 )
    {
        path[location_y][location_x]='*';
        return TRUE;  
    }   
    /*1 olma durumu*/
    if(table[location_y][location_x]==available)
    {
        if(find_path(table, path, size, location_x, location_y+1) == TRUE)
        {
            path[location_y][location_x]='*';
        
            return find_path(table, path, size, location_x, location_y+1);
        }
            
        if(find_path(table, path, size, location_x+1, location_y) == TRUE)
        {
            path[location_y][location_x]='*';
        
            return find_path(table, path, size, location_x+1, location_y);
        }
        

    }
    /*2 olma durumu*/
    else  if(table[location_y][location_x]==right_down)
    {
        if(find_path(table, path, size, location_x+1, location_y+1) == TRUE)
        {
            path[location_y][location_x]='*';
        
            return find_path(table, path, size, location_x+1, location_y+1);
        }
            

    }
    else
        return FALSE;


}

/*############################################################################*/
/*                End of HW07_Busra_Nur_Altunbas_121044076_part3.c            */
/*############################################################################*/
















