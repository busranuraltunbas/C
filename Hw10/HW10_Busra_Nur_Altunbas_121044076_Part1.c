/*############################################################################*/
/*HW10_Busra_Nur_Altunbas_121044076_Part1.c                                   */
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

#include "HW10_Busra_Nur_Altunbas_121044076_Part1.h"
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                       First Function                                       */
/*----------------------------------------------------------------------------*/

Appointment_t* getRequests(const Files_t* files, int* size) {
    
    int i;
    int size_t;
    Appointment_t *array_of_appointments;

    FILE *binary_records_file;
    binary_records_file = fopen(files->records_file_n, "rb");
    
    if (!binary_records_file) {
        printf("Unable to open file!\n");
    }
 
    array_of_appointments = (Appointment_t*) calloc(*size, sizeof (Appointment_t));
    fread(&size_t, sizeof (int), 1, binary_records_file);
    
    for(i=0; i<*size; ++i)
    {
        fread(&array_of_appointments[i], sizeof (Appointment_t), 1, binary_records_file);
    
    }
    fclose(binary_records_file);

    return array_of_appointments;

}

/*----------------------------------------------------------------------------*/
/*                       Second Function                                      */
/*----------------------------------------------------------------------------*/
void write_appointments(Appointment_t appointments[], int size, const Files_t* files) {
    int i;

    FILE *xml_records_file;
    
    xml_records_file = fopen( files->records_file_n, "w");
 
    fprintf(xml_records_file, "<Size>%d</Size>\n", size);
    fprintf(xml_records_file, "<Records>\n");
    for (i = 0; i < size; i++) {
        fprintf(xml_records_file, "\t<Appointment>\n");
        fprintf(xml_records_file, "\t\t<app_id>%d</app_id>\n", appointments[i].app_id);
        fprintf(xml_records_file, "\t\t<patient_id>%d</patient_id>\n", appointments[i].patient_id);
        fprintf(xml_records_file, "\t\t<hour>%d</hour>\n", appointments[i].hour);
        fprintf(xml_records_file, "\t</Appointment>\n");
    }
    fprintf(xml_records_file, "</Records>\n");

    fclose(xml_records_file);
}

/*----------------------------------------------------------------------------*/
/*                       Third Function                                       */
/*----------------------------------------------------------------------------*/
void get_main_arguments(int argc, char *argv[], Working_hours_t* hours, Files_t* files) {
    
    int k, w_start = 0;
    FILE *inp;
    FILE *out;
    char str[STR_SIZE];
    if (argc >1) {
       
        for(k=1; k<argc; ++k)
        {
            if(strcmp(argv[k],"-r")==0)
                files->records_file_n = (const char *)(argv[k+1]);
            else if(strcmp(argv[k],"-p")==0)
                 files->patients_file_n = (const char *)(argv[k+1]);
            else if(strcmp(argv[k],"-d")==0)
                 files->delete_file_n = (const char *)(argv[k+1]);
            else if(strcmp(argv[k],"-x")==0)
                 files->readable_records_file_n = (const char *)(argv[k+1]);
            else if(strcmp(argv[k],"-c")==0)
                 files->accepted_appo_file_n = (const char *)(argv[k+1]);
            else if(strcmp(argv[k],"-t")==0)
                 files->parameters_file_n = (const char *)(argv[k+1]);
            else if(strcmp(argv[k],"-s")==0){
                hours->start = atoi(argv[k+1]);
            }
            else if(strcmp(argv[k],"-e")==0){
                hours->end = atoi(argv[k+1]);
            }
        }

    }

}

/*----------------------------------------------------------------------------*/
/*                       Fourth Function                                      */
/*----------------------------------------------------------------------------*/
void print_parameters(const Files_t* files, const Working_hours_t* hours) {

    
    FILE *parameters_files;
    parameters_files = fopen(files->parameters_file_n, "w");
    
    if (!parameters_files) {
        printf("Unable to open file!\n");
    }
    
    fprintf(parameters_files,"%s\n",files->records_file_n);
    fprintf(parameters_files,"%s\n",files->patients_file_n);
    fprintf(parameters_files,"%s\n",files->delete_file_n);
    fprintf(parameters_files,"%s\n",files->readable_records_file_n);
    fprintf(parameters_files,"%s\n",files->accepted_appo_file_n);
    fprintf(parameters_files,"%s\n",files->parameters_file_n);
    fprintf(parameters_files,"%d\n",hours->start);
    fprintf(parameters_files,"%d\n",hours->end);
    fclose(parameters_files);
    
}
/*############################################################################*/
/*                End of HW10_Busra_Nur_Altunbas_121044076_Part1.c            */
/*############################################################################*/





