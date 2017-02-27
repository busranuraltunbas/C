/*############################################################################*/
/*HW10_Busra_Nur_Altunbas_121044076_Part2.c                                   */
/*Written by Busra Nur Altunbas on May 25, 2015                               */
/*                                                                            */
/*Desciription:                                                               */
/*The program is hold all appointment requests.                               */
/*Inputs:                                                                     */
/*    Variables                                                               */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include "HW10_Busra_Nur_Altunbas_121044076_Part2.h"

/*----------------------------------------------------------------------------*/
/*                       First Function                                       */
/*----------------------------------------------------------------------------*/
node_t* build_ll(Appointment_t appointmens[], int size, const Working_hours_t* 
hours)
{
    int i,k,l;
    node_t *node;
    node_t *head;
    node_t *tail;
    node_t *prev;
    char arr[]={'\0'};

    
    head = malloc(sizeof(node_t));
    tail = malloc(sizeof(node_t));
    head ->next = tail;
    tail -> next = NULL;
    prev = head;

    
    for(i=0; i<size; ++i)
    {
            node = malloc(sizeof(node_t));
            node->app_id = appointmens[i].app_id;
            node->patient_id = appointmens[i].patient_id;
            strcpy(node->name,arr );
            node->history = NULL;
            node->hour = appointmens[i].hour;
            node->next = tail;
            prev->next = node;
            prev = node;
    }
    
    return head;
}
/*----------------------------------------------------------------------------*/
/*                       Second Function                                      */
/*----------------------------------------------------------------------------*/
void write_accepted_app(node_t* head, const Files_t* files)
{
    int count=1,l;
    node_t *temp; 
    temp = head -> next;
    FILE *appointments_files;
    appointments_files = fopen(files->accepted_appo_file_n, "w+");
    
    if (!appointments_files) {
        printf("Unable to open file!\n");
    }
    fprintf(appointments_files,"no;id;patient_id;name;history;hour\n");
    while(temp -> next!=NULL)
    {
        fprintf(appointments_files,"%d;%d;%d;%s;%s;%d\n",count,
                                        temp->app_id,
                                        temp->patient_id,
                                        temp->name,
                                        temp->history,
                                        temp->hour);
        
        temp = temp->next;
        count++;
       
    }
    
    fclose(appointments_files);

}
/*----------------------------------------------------------------------------*/
/*                       Third Function                                       */
/*----------------------------------------------------------------------------*/
void add_personal_data(node_t* head, const Files_t* files)
{
    int n=0,i=0,h=0,k=0,m=0,l=0;
    char arr1[]={'\0'};
    char str[MAX_SIZE];
    char str_name[MAX_SIZE];
    char str_history[MAX_SIZE];
    char history_next[MAX_SIZE];
    char str1[MAX_SIZE]="    <Patient>";
    int count=0;
    str1[14]='\0';
    strcat(str1,"\n");
    FILE *patients_file_n;
    patients_file_n = fopen(files->patients_file_n,"r");
     
    if (!patients_file_n) {
        printf("Unable to open file!\n");
    }
  
    
    head->history = (char *)(node_t*)malloc(sizeof(node_t));
    
    while((fgets(str,MAX_SIZE,patients_file_n))!=NULL)
    {   
    n=0;
    i=0;
    h=0;
    k=0;
    m=0;
    l=0;
        if((strcmp(str,str1))!=0)
        {
               
            if(count == 2)
            {
                
                for(n=14; n<(strlen(str)-8); n++)
                {
                    str_name[i] = str[n];
                    i++;
                }
                str_name[i] ='\0';
                strcpy(head->name,str_name);
                
            }
            
            else if(count == 3)
            {
                for(h=17; h<(strlen(str)-1); h++)
                {
                    if(str[17]=='<')
                    {
                        head->history = NULL;
                    }
                    else
                    {
                        str_history[k] = str[h];
                        k++;
                    }
                    
                }
                str_history[k] ='\0';
                
            }
            else if(count == 4)
            {
            
                if(str[4]=='<')
                {
                    head->history = NULL;
                }     
                else
                {           
                    strcat(str_history," ");
                    strncat(str_history,str,(strlen(str)-1));
                }
            }
            else if(count == 5)
            {
                if(str[17]=='.')
                {
                    head->history = NULL;
                }
                else
                {
                    for(l=0; l<strlen(str)-11; l++)
                    {
                        history_next[m] = str[l];
                        m++;
                    
                    }
                    history_next[m] ='\0';
                    strcat(str_history," ");
                    strcat(str_history,history_next);
                    
                    head->history = (char*)str_history;
                }
            }
            count++;
        }
        
        else
        {
            count = 1;
            
            
        }
       
    }
    fclose(patients_file_n );

}
/*----------------------------------------------------------------------------*/
/*                       Fourth Function                                      */
/*----------------------------------------------------------------------------*/
int delete_appointments(node_t** head, const Files_t* files)
{
    int ids,counter=0;
    
    FILE *delete_file_n;
    delete_file_n = fopen(files->delete_file_n,"r");
     
    if (!delete_file_n) {
        printf("Unable to open file!\n");
    }
    while((fscanf(delete_file_n,"%d",&ids)!=EOF) && ((*head) -> next -> next!=NULL))
    {
            /*printf("idmm:%d\n",(*head)-> next->app_id);*/
                                     
        if((((*head)-> next)->app_id) == ids)
        {
            counter++;
    
        }
        
        (*head) = (*head)->next ;
    
    }
    fclose(delete_file_n);
    return counter;
}
/*############################################################################*/
/*                End of HW10_Busra_Nur_Altunbas_121044076_Part2.c            */
/*############################################################################*/










