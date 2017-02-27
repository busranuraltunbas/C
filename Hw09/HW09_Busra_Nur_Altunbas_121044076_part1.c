/*############################################################################*/
/*HW09_Busra_Nur_Altunbas_121044076_part1.c                                   */
/*Written by Busra Nur Altunbas on April 28, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*The program is the database.                                                */
/*Inputs:                                                                     */
/*    Variables                                                               */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*----------------------------------------------------------------------------*/
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define STR_SIZE 50
#define SIZE 50
#define MAX_SIZE 100
/*----------------------------------------------------------------------------*/
/*                        Structers                                           */
/*----------------------------------------------------------------------------*/
typedef struct {
    char name[STR_SIZE];
    char surname[STR_SIZE];
    char department[STR_SIZE];
    char class1[STR_SIZE];
    char class2[STR_SIZE];
    double salary;
}type_I;


typedef struct {
    char name[STR_SIZE];
    char surname[STR_SIZE];
    double salary;
    char degree;

}type_E;

typedef union {
    type_I inst;
    type_E empl;

}type_person;

typedef struct {
    char person_dcd;
    type_person inform ;

}combine_type;
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
void read_and_write(const char *file_txt, const char *file_bin);
combine_type salary_rise(combine_type person_info);
void read_binary(const char *file_bin1,combine_type person_info);
/*START_OF_MAIN*/
int main()
{   
    int i=0;
    combine_type person_info;
    read_and_write("person_info.txt","person_info.bin");
    read_binary("person_info.bin",person_info);
    
    
    return 0;
    /*END_OF_MAIN*/
}
/*File dan okuyup stringleri tek tek structa yazar, doldurur.*/
/**/
void read_and_write(const char *file_txt, const char *file_bin)
{
    char str[MAX_SIZE];
    char *name;
    char *surname;
    char *department;
    char *class1,*class2;
    char *tok;
	char *salary, *degree;
    combine_type person_info;
    FILE * inp;
    FILE * bin_out;
    inp = fopen(file_txt,"r");
    bin_out = fopen(file_bin,"wb+");
    while(fgets(str,MAX_SIZE,inp)!=NULL)
    {
        /*printf("%s\n",str);*/
        tok = strtok(str,",");
   
        /*printf("%s\n",tok);*/
        if(str[0]=='I')
        {
		    name =strtok(NULL," ");
		    surname = strtok(NULL,",");
			department = strtok(NULL,",");
		    class1 = strtok(NULL,",");
			class2 = strtok(NULL,",");
		    salary = strtok(NULL,",");

            person_info.person_dcd = 'I';
            /*printf("%c\n",person_info.person_dcd);*/

			strcpy(person_info.inform.inst.name,name);
            strcpy(person_info.inform.inst.surname,surname);
           /* printf("%s\n",person_info.inform.inst.name);
            printf("%s\n",person_info.inform.inst.surname);*/

            strcpy(person_info.inform.inst.department,department);
           /* printf("%s\n",person_info.inform.inst.department);*/

            strcpy(person_info.inform.inst.class1,class1);
           /* printf("%s\n",person_info.inform.inst.class1);*/

            strcpy(person_info.inform.inst.class2,class2);
            /*printf("%s\n",person_info.inform.inst.class2);*/

            person_info.inform.inst.salary = atoi(salary);
            person_info = salary_rise(person_info);
            /*printf("%f\n",person_info.inform.inst.salary);*/
           
        }

        else if(str[0]=='E')
        {
		    name =strtok(NULL," ");
		    surname = strtok(NULL,",");
        	salary = strtok(NULL,",");
			degree = strtok(NULL,",");

            person_info.person_dcd = 'E';
            /*printf("%c\n",person_info.person_dcd);*/

            strcpy(person_info.inform.empl.name,name);
            strcpy(person_info.inform.empl.surname,surname);
            /*printf("%s\n",person_info.inform.empl.name);
            printf("%s\n",person_info.inform.empl.surname);*/

            person_info.inform.empl.salary = atoi(salary);
            /*printf("%f\n",person_info.inform.empl.salary);*/

            person_info.inform.empl.degree = degree[1];
            person_info = salary_rise(person_info);
            /*printf("%c\n",person_info.inform.empl.degree);*/
          
        }
        fwrite(&person_info,sizeof(combine_type),1,bin_out);
    } 
    fclose(inp);
    fclose(bin_out);   
}

/*Kisinin isine gore maasina zam yapilir.*/
combine_type salary_rise(combine_type person_info)
{
    if(person_info.person_dcd == 'E')
    {
        if(person_info.inform.empl.degree == 'a')
        {
            person_info.inform.empl.salary += ((0.175)*(double)((double)person_info.inform.empl.salary));
        
        }
        else if(person_info.inform.empl.degree == 'b')
        {
            person_info.inform.empl.salary += ((0.12)*(double)((double)person_info.inform.empl.salary));
        } 
        else if(person_info.inform.empl.degree == 'b')
        {
             person_info.inform.empl.salary += ((0.09)*(double)((double)person_info.inform.empl.salary));
        } 
        /*printf("%f\n",person_info.inform.empl.salary);*/
    }      
    else  if(person_info.person_dcd == 'I')
    {
        person_info.inform.inst.salary += (0.05)*((double)person_info.inform.inst.salary/2.0) + (0.053)*((double)person_info.inform.inst.salary/2.0);
        /*printf("%f\n",person_info.inform.inst.salary);*/
    }
    return person_info;
}
/**/
void read_binary(const char *file_bin1,combine_type person_info)
{
    FILE *binary_input_file;
    binary_input_file = fopen(file_bin1,"rb");
    while( fread(&person_info,sizeof(combine_type),1,binary_input_file)!=0)
    {
        if(person_info.person_dcd == 'I')
        {
            printf("%c",person_info.person_dcd );
            printf(" %s",person_info.inform.inst.name);
            printf(" %s",person_info.inform.inst.surname);
            printf(" %s",person_info.inform.inst.department);
            printf(" %s",person_info.inform.inst.class1);
            printf(" %s",person_info.inform.inst.class2);
            printf(" %f\n",person_info.inform.inst.salary);

        }
        else if(person_info.person_dcd == 'E')
        {
            printf("%c",person_info.person_dcd );
            printf(" %s",person_info.inform.empl.name);
            printf(" %s",person_info.inform.empl.surname);
            printf(" %f",person_info.inform.empl.salary);
            printf(" %c\n",person_info.inform.empl.degree);
        
        }
        printf("\n");
        
    }
 
    fclose(binary_input_file);
}

/*############################################################################*/
/*                End of HW09_Busra_Nur_Altunbas_121044076_part1.c            */
/*############################################################################*/




