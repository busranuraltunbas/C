/*############################################################################*/
/*HW10_Busra_Nur_Altunbas_121044076_Test1.c                                   */
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
#include <stdio.h>
#include <stdlib.h>
#include "HW10_Busra_Nur_Altunbas_121044076_Part1.h"

/*START_OF_MAIN*/
int main(int argc, char** argv)
{

    Files_t  files;
    Working_hours_t hours;
    int size=0;
    char fileName[] = "Records.bin";
    char fileName1[] = "Patients.xml";
    char fileName2[] = "Delete.txt";
    char fileName3[] = "Records.xml";
    char fileName4[] = "Appointments.csv";
    char fileName5[] = "Parameters.txt";
    Appointment_t *array_of_appointments;
    files.records_file_n = (const char *)fileName;
    files.patients_file_n = (const char *)fileName1;
    files.delete_file_n = (const char *)fileName2;
    files.readable_records_file_n = (const char *)fileName3;
    files.accepted_appo_file_n= (const char *)fileName4;
    files.parameters_file_n= (const char *)fileName5;
    hours.start = START;
    hours.end = END;
    size = RECORD_SIZE;
    
    array_of_appointments = getRequests(&files,&size);
    
    write_appointments(array_of_appointments, size, &files);
    
    get_main_arguments(argc, argv, &hours, &files);
    print_parameters(&files, &hours);
  

    return 0;
    /*END_OF_MAIN*/
}

