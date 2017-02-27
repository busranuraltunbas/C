/*############################################################################*/
/*HW10_Busra_Nur_Altunbas_121044076_Test2.c                                   */
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

/*START_OF_MAIN*/
int main(int argc, char** argv)
{
    int counter=0,size=0;
    Files_t  files;
    Working_hours_t hours;
    node_t *head;
    Appointment_t *array_of_appointments;
    char fileName[] = "Records.bin";
    char fileName1[] = "Patients.xml";
    char fileName2[] = "Delete.txt";
    char fileName3[] = "Records.xml";
    char fileName4[] = "Appointments.csv";
    char fileName5[] = "Parameters.txt";
    
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
    
    head =build_ll(array_of_appointments, size, &hours);

    write_accepted_app(head, &files);
     
    add_personal_data( head, &files);
    
    counter = delete_appointments(&head, &files);
    
    return 0;
    /*END_OF_MAIN*/
}


