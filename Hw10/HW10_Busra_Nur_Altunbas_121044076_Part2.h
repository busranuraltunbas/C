/*############################################################################*/
/*HW10_Busra_Nur_Altunbas_121044076_Part2.h                                   */
/*Written by Busra Nur Altunbas on May 25, 2015                               */
/*                                                                            */
/*Desciription:                                                               */
/*The library is hold all struct information and prototypes.                  */
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
#include "Part1.h"
/*----------------------------------------------------------------------------*/
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define STR_SIZE 50
#define RECORD_SIZE 4
#define MAX_SIZE 1000

/*----------------------------------------------------------------------------*/
/*                        Structers                                           */
/*----------------------------------------------------------------------------*/
typedef struct linked_list
{
    int app_id;
    int patient_id;
    char name[STR_SIZE];
    char* history;
    int hour;
    struct linked_list* next;
    
}node_t;

/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/

node_t* build_ll(Appointment_t appointmens[], int size, const Working_hours_t*
hours);
void write_accepted_app(node_t* head, const Files_t* files);
void add_personal_data(node_t* head, const Files_t* files);
int delete_appointments(node_t** head, const Files_t* files);
void free_list(node_t* head);
/*############################################################################*/
/*                End of HW10_Busra_Nur_Altunbas_121044076_Part2.h            */
/*############################################################################*/

