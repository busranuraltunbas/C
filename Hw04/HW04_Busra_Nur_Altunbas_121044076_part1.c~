/*************************************************************
 *                                                           *
 * HW04 Q1                                                   *
 * Student Name: Busra Nur Altunbas                          *
 * Student ID  : 121044076                                   *
 * Date        : March 15, 2015                              *
 * Points      : 30                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q1/PlainMessagesToSent.txt"
#define ENCODEDFILE "Files/Q1/EncodedMessages.txt"
#define CRYPTEDFILE "Files/Q1/CryptedMessages.txt"

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character);

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return encoded character number                           *
 *************************************************************/
int 
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads plane text, creates encoded and crypted text files  *
 *************************************************************/
/*-----------------------------------------------------------*/
/*                    End of Prototypes                      */
/*-----------------------------------------------------------*/

/*START_OF_MAIN*/
int 
main(int argc, char* argv[])
{
    /*START_OF_VARIABLES*/
    int counter;
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;
	/*END_OF_VARIABLES*/

	/* exit program and print error if plain text file could not be opened to read */
	
	if((f_plane_ptr=fopen("PlainMessagesToSent.txt","r"))==NULL)
	{
	    printf("File could not be opened to read.\n");
        return 0;
    }

	/* exit program and print error if encoded text file could not be opened to write */
	if((f_encoded_ptr=fopen("EncodedMessages.txt","w"))==NULL)
	{
	    printf("File could not be opened to write.\n");
        return 0;
    }

	counter=encode_message(f_plane_ptr, f_encoded_ptr);

	/* close plain and encoded files */
	fclose(f_plane_ptr);
	fclose(f_encoded_ptr);

	/* exit program and print error if crypted text file could not be opened to write */
	if((f_crypted_ptr=fopen("CryptedMessages.txt","w"))==NULL)
	{
	    printf("File could not be opened to write.\n");
        return 0;
    }

	/* exit program and print error if encoded text file could not be opened to read */
	if((f_encoded_ptr=fopen("EncodedMessages.txt","r"))==NULL)
	{
	    printf("File could not be opened to read.\n");
        return 0;
    }


	crypt_message(f_encoded_ptr, f_crypted_ptr);

	/* close crypted and encoded files */
	fclose(f_crypted_ptr);
	fclose(f_encoded_ptr);

	return 0;
	/*END_OF_MAIN*/
}
/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character)
{
	/* Hint: Use switch case while encoding character 
	 *		 Keep number of 1s and use it in a loop to
	 *		 write to file encoded value. You are going to
	 *		 call fprintf in the loop just number of 1s times
	 *		 Do not forget adding 0 at the end of value
	 */
    int i=0;
    switch(character) 
    {
        case 'E':
            for(i=0; i<0; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            break;
        case 'I':
            for(i=0; i<1; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case ' ':
            for(i=0; i<2; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
           
            break;
            
        case 'T':
            for(i=0; i<3; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            break;
            
        case 'C':
            for(i=0; i<4; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'N':
            for(i=0; i<5; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'A':
            for(i=0; i<6; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'G':
            for(i=0; i<7; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
        case 'B':
            for(i=0; i<8; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'Z':
            for(i=0; i<9; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'H':
            for(i=0; i<10; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'L':
            for(i=0; i<11; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'U':
            for(i=0; i<12; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
        case 'V':
            for(i=0; i<13; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'R':
            for(i=0; i<14; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'S':
            for(i=0; i<15; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
            
        case 'Y':
            for(i=0; i<16; i++)
                fprintf(f_out_ptr,"1");
            fprintf(f_out_ptr,"0");
            
            break;
	
	}
	

	/*
	 *
	 Some magic here
	 *
	 */
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file	 while(!feof(f_in_ptr)){
    
        fscanf(f_in_ptr,"%c",&ch);
        printf("%c",ch);
    }          *
 * return number of characters read from plain text          *
 *************************************************************/
int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
    char ch;
	/* Hint: Keep reading from plain text until end of file
	 *		 while reading per character call encode_and_write_to_file
	 *		 function.
	 */
	 
	int counter = 0;
    while(fscanf(f_in_ptr,"%c",&ch)!=EOF){
        encode_and_write_to_file(f_out_ptr,ch);
        counter++;
        if(ch==' ')
            counter--;
        if(ch=='\n')
            counter--;
    }
	/*printf("count1:%d",counter);*/


	/*
	 *
	 Some magic here
	 *
	 */

	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return number of characters read from encoded text file   *
 *************************************************************/
int 
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
    char ch;
	/* Hint: Keep reading from encoded text until end of file
	 *		 while reading per character check if it is equal 
	 *		 to 1 or 0 and according to character write file '*'
	 *		 '_'
	 *		 Do not forget adding '-' character to proper places
	 *       Check sample encrypted messages and read objective 3
	 *
	 */
	int counter = 0,tire=0,sum=0,inc=0,start=5;
	    
    while(fscanf(f_in_ptr,"%c",&ch)!=EOF){
        if(tire==0 && start==0)
            start=5;
      
        if(ch=='1')	
            fprintf(f_out_ptr,"*");
        else if(ch=='0')	
            fprintf(f_out_ptr,"_");
        tire++;
        if(tire==start){
            fprintf(f_out_ptr,"-");
            
            tire=0;
            start--;
            inc++;
            inc=+inc;
        }
        sum++;
    }
    counter=sum+inc;
     
	/*printf("countem:%d\n",counter);*/
	/*
	 *
	 Some magic here
	 *
	 */
   
	return counter;
}
/*############################################################################*/
/*               End of HW04_Busra_Nur_Altunbas_121044076_part1.c             */
/*############################################################################*/
