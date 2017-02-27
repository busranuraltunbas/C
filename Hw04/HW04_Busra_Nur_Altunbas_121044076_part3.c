/*************************************************************
 *                                                           *
 * HW04 Q3                                                   *
 * Student Name: Busra Nur Altunbas                          *
 * Student ID  : 121044076                                   *
 * Date        : March 16, 2015                              *
 * Points      : 50                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define CHARACTERFILE "Files/Q3/CharacterList.txt"
#define SAMPLEFILE "Files/Q3/Sample.txt"
#define ENCODEDFILE "Files/Q3/XUniversityEncoded.txt"
#define PLAINTEXTFILE "Files/Q3/XUniversityMessage.txt"

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b);

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b);

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num);

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c);

/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3);

/*************************************************************
 * Learns XUniversity's encoding system from given files ,   *
 * decodes their encoded messages and writes as plain text to*
 * a file                                                    *
 *************************************************************/
/*-----------------------------------------------------------*/
/*                    End of Prototypes                      */
/*-----------------------------------------------------------*/

/*START_OF_MAIN*/
int 
main(int argc, char* argv[])
{
    /*START_OF_VARIABLES*/
	FILE *f_character_list_ptr, *f_sample_file_ptr, *f_encoded_ptr,
		*f_plain_text_ptr;
	int character_number;
	char c1, c2, c3;
	int counter=0;
	/*END_OF_VARIABLES*/
	 
	/* exit program and print error if character list file could not be opened to read */
	if((f_character_list_ptr=fopen("CharacterList.txt","r"))==NULL)
	{
	    printf("File could not be opened to read.\n");
        return 0;
    }
	
	/* call read_character_list function and get return value *
	 * if number of letter read is not equal to three exit    *
	 * program                                                */
	 
	counter = read_character_list(f_character_list_ptr, &c1, &c2, &c3);
	if(counter!=3)
	    return 0;
	
	/* close character list file */
	fclose(f_character_list_ptr);

	/* exit program and print error if sample file could not be opened to read */
	if((f_sample_file_ptr=fopen("Sample.txt","r"))==NULL)
	{
	    printf("File could not be opened to read.\n");
        return 0;
    }

	/* Call count_letters function and swap letters inside function *
	 * according to number of counts                                */
	 count_letters(f_sample_file_ptr, &c1, &c2, &c3);
	 	
	
	/* close sample file */
	fclose(f_sample_file_ptr);

	/* exit program and print error if encoded file could not be opened to read */
	if((f_encoded_ptr=fopen("XUniversityEncoded.txt","r"))==NULL)
	{
	    printf("File could not be opened to read.\n");
        return 0;
    }
	
	/* exit program and print error if plain text file could not be opened to write */
	if((f_plain_text_ptr=fopen("XUniversityMessage.txt","w"))==NULL)
	{
	    printf("File could not be opened to write.\n");
        return 0;
    }
	
	/* Call decode function */	
	decode(f_encoded_ptr, f_plain_text_ptr, c1, c2, c3);

	/* close encoded and plain text file */
	fclose(f_encoded_ptr);
	fclose(f_plain_text_ptr);

	return 0;
	/*END_OF_MAIN*/
}

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b)
{
	/*
	 *
	 Some magic here
	 
	 *
	 */
	 int temp=0;
	 temp = *a;
	 *a = *b;
	 *b = temp;
}

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b)
{
	/*
	 *
	 Some magic here
	 *
	 */
	 char temp;
	 temp = *a;
	 *a = *b;
	 *b = temp;
	 
}

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num)
{
    int temp=0;
    if(a_num < b_num )
    {
        swap_int(&a_num, &b_num);
        swap_char(a, b);
        
    }
    
    if(a_num < c_num )
    {
        swap_int(&a_num, &c_num);
        swap_char(a, c);
       
    }
    
    if(b_num < c_num )
    {
        swap_int(&b_num, &c_num);
        swap_char(b, c);
       
    }
	
}

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c)
{
	/* Hint: Look for difference with 'A' to understand 
	 * character is a big letter or not. Use ASCII codes to
	 * determine if it is a big letter or not          
	 */
    if((c>=65) && (c<=90))
        return TRUE;
    else
        return FALSE;

	/*
	 *
	 Some magic here
	 *
	 */
}

/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3)
{	
	int counter = 0;
	char ch;
	/*
	 *
	 Some magic here
	 *
	 */

     while(fscanf(f_in_ptr,"%c",&ch)!=EOF){
        if(is_letter(ch)==TRUE){
            counter++;
            /*printf("%c",ch);*/
           
            if((counter==1) && (counter<=4))
                *c1=ch;
            else if((counter==2 )&& (counter<=4))
                *c2=ch;
            else if((counter==3) && (counter<=4))
                *c3=ch;
            else if((counter==2) && (counter<3))
                *c3='\0';
        }
        
     }
     
	return counter;
}

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3)
{
    int counter=0;
    char ch;
    int count_c1=0,count_c2=0,count_c3=0;
	/* Hint: Read character by character and increment counter
	 * of proper counter of read character.
	 */

	/*
	 *
	 Some magic here
	 *
	 */

     while(fscanf(f_in_ptr,"%c",&ch)!=EOF){
        if((ch>=65) && (ch<=90)){
            if(ch==*c1)
                count_c1++;
            if(ch==*c2)
                count_c2++;
            if(ch==*c3)
                count_c3++;

        }
        
    }
    
    sort(c1, count_c1, c2, count_c2, c3, count_c3);
    
}

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3)
{
	char ch;
	int number_of_ones=0,number_of_zeros=0,counter=0;
	/* Hint: While reading from encoded text file keep reading 
	 *		 character by character. Use ASCII difference from 0
	 *		 to determine number is 0 or 1. If we try reading it
	 *		 as integer, it overflows. Overflow is bad if you are 
	 *		 not hacker and do not want to crash system deliberately.
	 */
    
	/*
	 *
	 Some magic here
	 *
	 */
    while(fscanf(f_in_ptr,"%c",&ch)!=EOF){
    counter++;
        if(ch==49)
            number_of_ones++;
        /*printf("%c",ch);*/
        if(ch==48){
        
            switch(number_of_ones){
                case 0:
                    fprintf(f_out_ptr,"%c",c1);
                    break;
                case 1:
                    fprintf(f_out_ptr,"%c",c2);
                    break;
                case 2:
                    fprintf(f_out_ptr,"%c",c3);
                    break;
            }
            number_of_ones=0;
        }
    }
	 
}
/*############################################################################*/
/*               End of HW04_Busra_Nur_Altunbas_121044076_part3.c             */
/*############################################################################*/

