/*############################################################################*/
/*HW08_Busra_Nur_Altunbas_121044076_part2.c                                   */
/*Written by Busra Nur Altunbas on April 21, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*The appointments of a doctor.                                               */
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
#define MAX_SIZE 100
#define STR_SIZE 30
#define SIZE 100

#define TC_ID_FIRST_HALF_SIZE 6
#define TC_ID_SECOND_HALF_SIZE 5
#define TC_ID_SIZE 11
/*----------------------------------------------------------------------------*/
/*                        Structers                                           */
/*----------------------------------------------------------------------------*/
typedef enum{ MALE, FEMALE }Gender_t;
typedef enum { JANUARY=1,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST,
               SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER }Months_t;
typedef struct{
    int first_half;
    int second_half;

}TCId_no_t;

typedef struct{
    TCId_no_t id_no;
    char name[STR_SIZE];
    char surname[STR_SIZE];
    Gender_t gender;
    
}People_t;

typedef struct{
    int hour;
    int minute;

}Time_t;

typedef struct{
    int year;
    Months_t month;
    int day;
    Time_t time;

}Date_t;


typedef struct{
    People_t people;
    Date_t date;

}Appointment_t;
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/

int get_people(const char *file_name, People_t people[], int max_size);

int get_appointments(const char *file_name, Appointment_t appointments[], int max_size);

void write_names(Appointment_t appointments[], int size_app, const People_t 
people[], int size_people);

int check_appointments(Appointment_t appointments[], int size);

void sort_appointments(Appointment_t appointments[], int size);

void write_appointments(const char *file_name, Appointment_t appointments[], int 
size);
/*START_OF_MAIN*/
int main()
{
    int max_size=25,size=0;
    int size_people=0;
    int  size_app=0;
    People_t people[MAX_SIZE];
    Date_t date[MAX_SIZE];
    Appointment_t appointments[MAX_SIZE];
    
    size_people = get_people("People.txt", people, max_size);
    printf("size_people:%d\n",size_people);
    
    size_app = get_appointments("AppointmentReqs.txt", 
                          appointments, max_size);
    printf("size_app:%d\n",size_app);
    /*write_names( appointments, size_app, people, size_people);*/
    write_appointments("Appointments.txt",  appointments, size);
    /*END_OF_MAIN*/
    return 0;
}
/*File dan okudugu kisi bilgileri degerlerini people_t structuna atar.*/
int get_people(const char *file_name, People_t people[], int max_size)
{
    char name[STR_SIZE];
    char surname[STR_SIZE];
    char str[MAX_SIZE];
    People_t peoples;
    TCId_no_t tc_id;
    int people_record=0,i,j=0,k;
    int counter=0;
    int first[MAX_SIZE];
    int second[MAX_SIZE];
    char *tok;
    char son[MAX_SIZE];
    
    FILE *inp_p;
    inp_p = fopen(file_name,"r");
    
    while((fgets(str,SIZE,inp_p))!=NULL)
    {
        counter = 0;
        tok=strtok(str," ");
    
        while (tok != NULL)
        {
            /*printf ("1.%s\n",tok);*/
            /*if(counter == 0)
            {
                
                for(i=0; i<TC_ID_FIRST_HALF_SIZE; i++)
                {
                    first[i] = tok[i];
                    if(i = TC_ID_FIRST_HALF_SIZE-1)
                        first[TC_ID_FIRST_HALF_SIZE]='\0';
                }
                
                (&peoples)[people_record].id_no.first_half = atoi(first);
                for(j=TC_ID_FIRST_HALF_SIZE; j<TC_ID_SIZE; j++)
                {
                    second[j] = tok[j];
                    if(j = TC_ID_SIZE-1 )
                         second[TC_ID_SIZE]='\0';
                
                }
                
                (&peoples)[people_record].id_no.second_half = atoi(second);
            }*/
                      
            if(counter == 1)
                strcpy((&peoples)[people_record].name,tok);
            else if(counter == 2)
                strcpy((&peoples)[people_record].surname,tok);
            else if(counter == 3)
            {
                if(strchr(tok,'M'))
                    (&peoples)[people_record].gender =  77;
                else if(strchr(tok,'F'))
                    (&peoples)[people_record].gender =  70;
            }
            tok = strtok (NULL," ");   
            counter++;
        }
        people_record++;
    
    }
    for(k=0; k<people_record; k++)
    {
       /* printf("%d",(&peoples)[k].id_no.first_half);
        printf("%d",(&peoples)[k].id_no.second_half);*/
        printf(" %s",(&peoples)[k].name);
        printf(" %s",(&peoples)[k].surname);
        printf(" %c",(&peoples)[k].gender);
        printf("\n");
    
    }
    
    fclose(inp_p);
    return people_record;
}
/*File dan okudugu appointments degerlerini Appointment_t structuna atar.*/
int get_appointments(const char *file_name, Appointment_t appointments[], int max_size)
{
    char str1[MAX_SIZE];
    int appointments_record=0,k=0;
    int counter=0;
    char *tok;
    char son[MAX_SIZE];
    Date_t dates[STR_SIZE];
    FILE *inp_p;
    inp_p = fopen(file_name,"r");
 
    while((fgets(str1,SIZE,inp_p))!=NULL)
    {
        counter = 0;
        tok=strtok(str1," ");
    
        while (tok != NULL)
        {
            /*printf ("1.%s\n",tok);*/
            
            if(counter == 1)
                (dates)[appointments_record].year = atoi(tok);
            else if(counter == 2)
                (dates)[appointments_record].month = atoi(tok);
            else if(counter == 3)
                 (dates)[appointments_record].day = atoi(tok);
           /* else if(counter == 4)
                 (dates)[appointments_record].time = atoi(tok);*/
                 
            tok = strtok (NULL," ");
            counter++;
            
        }
        appointments_record++;
    
    }
    for(k=0; k<appointments_record; k++)
    {
        printf("%d",(dates)[k].year);
        printf(" %d",(dates)[k].month);
        printf(" %d",(dates)[k].day);
       /* printf(" %d",(&dates)[k].time);*/
        printf("\n");
    
    }
    
    fclose(inp_p);
    return appointments_record;

}
/*void write_names(Appointment_t appointments[], int size_app, const People_t
people[], int size_people)
{
    int app,ppl;

    for(ppl=0; ppl<size_app; ppl++)
    {
        printf("%s",(&people)[ppl].name);
        printf(" %s",(&people)[ppl].surname);
        printf(" %d",(&people)[ppl].gender);
        printf("\n");
    
    }

}*/

void write_appointments(const char *file_name, Appointment_t appointments[], int 
size)
{
    int k=0,l=0;
    Date_t dates[STR_SIZE];
    People_t people;
    FILE *out_p;
    out_p = fopen(file_name,"w");
    
    for(l=0; l<3; l++)
    {
       /* printf("%d",(&peoples)[l].id_no.first_half);
        printf("%d",(&peoples)[l].id_no.second_half);*/
        fprintf(out_p," %s",appointments[l].people.name);
        fprintf(out_p," %s",appointments[l].people.surname);
        fprintf(out_p," %c",appointments[l].people.gender);
    
    }
    
    for(k=0; k<3; k++)
    {
        fprintf(out_p,"%d",(dates)[k].year);
        fprintf(out_p," %d",(dates)[k].month);
        fprintf(out_p," %d\n",(dates)[k].day);
       /* printf(" %d",(&dates)[k].time);*/
    
    }
    fclose(out_p);

}
/*############################################################################*/
/*                End of HW08_Busra_Nur_Altunbas_121044076_part2.c            */
/*############################################################################*/


