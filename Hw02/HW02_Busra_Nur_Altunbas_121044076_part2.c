/******************************************************************************/
/****  written by BUSRA NUR ALTUNBAS			                          *****/
/****  	121044076 , on 2 march,2015				                          *****/
/****  This program calculates students grades                            *****/
/****  	input: two midterms and final grades                              *****/
/****	output:contributions,avarage,grades                               *****/
/******************************************************************************/
/*--------------------------------------------------------------------------  */
/*                               Includes                                     */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#define COURSECREDIT 3.0
#define MIDTERM 30.0
#define FINAL 40.0

/**** FUNTIONS PROTOTYPE*  ****/
double calculate_grade(int mid1, int mid2, int final); /*dosyadan okunan degerleri alip 
																					notu hesapliyor*/
double calculateGPA(double grade); /*not araligina gore harf notunu buluyor ve gerekli harf 
														harf kredisiyle carpip 20ye bolerek sonucu buluyor*/

int main()
{
	/*START_OF_MAIN*/
	/*START_OF_VARIABLES*/
	char name, surname;
	int midterm1, midterm2, final;
	double grade, contribution;
	
	FILE *inp,
			*outp;
	 /*END_OF_VARIABLES*/		
	
	inp=fopen("Students.txt", "r"); /*dosyalari actim */
	outp=fopen("Grades.txt", "w");
	
	/*ilk kisi*/
	fscanf(inp, "%c%c %d %d %d", &name, &surname, &midterm1, &midterm2, &final);
	 /*dosyadan ilk kisi icin degerleri okudum */
	grade=calculate_grade(midterm1, midterm2, final); /*grade hesaplandi */
	contribution=calculateGPA(grade); /*grade ile iliskili contribution degeri bulundu */
	fprintf(outp, "%c%c\t%.1f\n", name, surname, grade); /*dosyaya yazdirdim*/
	printf("NS\tGRADE\tCONTRIBUTION\n");
	printf("%c%c\t%.1f\t  %.3f\n", name, surname, grade, contribution); /*ekrana yazdirdim*/

	/*ikinci kisi*/
	fscanf(inp, " %c%c %d %d %d", &name, &surname, &midterm1, &midterm2, &final);
	grade=calculate_grade(midterm1, midterm2, final);
	contribution=calculateGPA(grade);
	fprintf(outp, "%c%c\t%.1f\n", name, surname, grade);
	printf("%c%c\t%.1f\t  %.3f\n", name, surname, grade, contribution);

	/*ucuncu kisi*/
	fscanf(inp, " %c%c %d %d %d", &name, &surname, &midterm1, &midterm2, &final);
	grade=calculate_grade(midterm1, midterm2, final);
	contribution=calculateGPA(grade);
	fprintf(outp, "%c%c\t%.1f\n", name, surname, grade);
	printf("%c%c\t%.1f\t  %.3f\n", name, surname, grade, contribution);

	/*dorduncu kısı*/
	fscanf(inp, " %c%c %d %d %d", &name, &surname, &midterm1, &midterm2, &final);
	grade=calculate_grade(midterm1, midterm2, final);
	contribution=calculateGPA(grade);
	fprintf(outp, "%c%c\t%.1f\n", name, surname, grade);
	printf("%c%c\t%.1f\t  %.3f\n", name, surname, grade, contribution);			

	/*besinci kisi*/
	fscanf(inp, " %c%c %d %d %d", &name, &surname, &midterm1, &midterm2, &final);
	grade=calculate_grade(midterm1, midterm2, final);
	contribution=calculateGPA(grade);
	fprintf(outp, "%c%c\t%.1f\n", name, surname, grade);
	printf("%c%c\t%.1f\t  %.3f\n", name, surname, grade, contribution);
	
	return 0;
	/*END_OF_MAIN*/
}

double calculate_grade(int mid1, int mid2, int final)
{
	double grade;
	
		grade=mid1*MIDTERM/100.0+mid2*MIDTERM/100.0+final*FINAL/100.0;
	return grade;	
}

double calculateGPA(double grade)
{
	char letter;
	double contribution;
	
	/*harf notunu buldum*/
	if(grade>= 85 && grade<=100)
        letter='A';
    else if(grade>= 70 && grade<=84)
        letter='B';
    else if(grade>= 65 && grade<=69)
        letter='C';
    else if(grade>= 40 && grade<=64)
        letter='D';
    else if(grade<= 39)
        letter='F';

	switch(letter) /*harf notuna gore gerekli krediyle ders kredisini carptim ve 20ye boldum*/
	{
		case 'A':
			contribution=4*COURSECREDIT/20.0;
			break;
		case 'B':
			contribution=3*COURSECREDIT/20.0;
			break;
		case 'C':
			contribution=2*COURSECREDIT/20.0;
			break;
		case 'D':
			contribution=1*COURSECREDIT/20.0;
			break;
		case 'E':
			contribution=0*COURSECREDIT/20.0;
			break;
		default:
			contribution=0.0;
			printf("Grade GPA sinirlari icinde degil!!!\n");
			break;
	}
	
	return contribution;
}
