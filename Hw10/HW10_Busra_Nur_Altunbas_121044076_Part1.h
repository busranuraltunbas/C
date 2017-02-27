/*############################################################################*/
/*HW10_Busra_Nur_Altunbas_121044076_Part1.h                                   */
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
/*----------------------------------------------------------------------------*/
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define STR_SIZE 50
#define START 9
#define END 17
#define RECORD_SIZE 4
/*----------------------------------------------------------------------------*/
/*                        Structers                                           */
/*----------------------------------------------------------------------------*/
typedef struct
{
    int app_id;
    int patient_id;
    int hour;

}Appointment_t;

typedef struct
{
    int start;
    int end;

}Working_hours_t;

typedef struct
{
    const char* records_file_n;
    const char* patients_file_n;
    const char* delete_file_n;
    const char* readable_records_file_n;
    const char* accepted_appo_file_n;
    const char* parameters_file_n;

} Files_t;

/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
Appointment_t* getRequests(const Files_t* files, int* size);
void write_appointments(Appointment_t appointments[], int size, const Files_t* files);
void get_main_arguments(int argc, char *argv[], Working_hours_t* hours, Files_t* files);
void print_parameters(const Files_t* files, const Working_hours_t* hours);

/*############################################################################*/
/*                End of HW10_Busra_Nur_Altunbas_121044076_Part1.h            */
/*############################################################################*/

