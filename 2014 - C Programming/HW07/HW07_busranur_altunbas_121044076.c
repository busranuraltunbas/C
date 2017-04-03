#include<stdio.h>
#define MAXSIZE 25
#define COLOUMNSIZE 8
#define PIECES_SIZE 2


enum direction_t{LEFT,UP,RIGHT};


int getInitState(FILE*, int table[][COLOUMNSIZE], int);
void printGame(int table[][COLOUMNSIZE], int);
int playGame(char *);
int makeMove(int table[][COLOUMNSIZE], int, int, int, int, int);
void getPieces(int table[][COLOUMNSIZE], int,int pieces1[][PIECES_SIZE],int pieces2[][PIECES_SIZE],int*,int*  );
void getOppositeView(int tableIn[][COLOUMNSIZE], int rowC);
void printPieces(int output[][2],int rowC,int );
int isBlocked(int table[][COLOUMNSIZE], int rowC, int playerNo, int coorY, int coorX);
void saveGame(char *savingFileName, int table[][COLOUMNSIZE], int rowC);
    /*Function definitions, etc.*/
int main(){
    /*START_OF_MAIN*/
    char *initFileName = "Initial.txt";
    /*END_OF_VARIABLES*/
    playGame(initFileName);
    return 0;
    /*END_OF_MAIN*/
}


int playGame(char *initFileName){

    /*Okudugum dosya*/
    FILE *initFilePtr;
    
    /*Degiskenler*/
    int rowC,rowCP1,rowCP2;
    
    /*Dama taslarini tutan array*/
    int table[MAXSIZE][COLOUMNSIZE];
    
    /*1.oyuncunun taslarinin koordinatlarini tutan array*/
    int pieces1[MAXSIZE][PIECES_SIZE];
    
    /*2.oyuncunun taslarinin koordinatlarini tutan array*/
    int pieces2[MAXSIZE][PIECES_SIZE];
    
    /*Okudugum dosya*/
    initFilePtr = fopen(initFileName,"r");     
    
	printf("\n\n*** DAMA TASLARIMIZ***\n");
	
	/*Table arrayini doldurur*/
	rowC = getInitState(initFilePtr, table, rowC);
	
	/*Pieces1 ve pieces2 2D arraylarini belirler, rowCP1 Ve rowCP2 degerlerini bulur*/
	getPieces(table, rowC, pieces1, pieces2,&rowCP1,&rowCP2);
	
	/*Table i ekrana yazdirir*/
	printGame(table, rowC);
	
	/*Table in 2.nin oyuncunun bakis acisindan goruntusunu ekrana yazar*/
    getOppositeView(table, rowC);
    
    /*Table in suanki durumunu SG_checkers.txt dosyasina kaydeder */
    saveGame("SG_checkers.txt", table, rowC);
    
    /*Oyucularin taslarini ekrana yazar*/
    printPieces(pieces1, rowCP1,1);
    printPieces(pieces2, rowCP2,2);
    
    /*enum degiskeni*/
    enum direction_t direction =RIGHT;
    
    /*printf("%d\n",direction);*/
    
    /*Dosyayi kapatir*/
    fclose(initFilePtr);
    
    return 0;
}

/*Dosyadan okudugu degerleri table arrayine doldurur ve row countu return eder*/
int getInitState(FILE *inptr, int table[][COLOUMNSIZE], int rowC){

	char status; /*Her integer sayi ile alinan karakteri tutar*/
	rowC=0; /*row countin ilk deger atamasi*/
	int colC=0; /*column count*/

    /*Dosyadan okudugu degerleri table arrayine doldurur*/
	while(fscanf(inptr,"%d%c",&table[rowC][colC],&status)!=EOF)
	{
		if(status=='\n')
		{
			(rowC)++;
			(colC)=0;
		}
		else
			(colC)++;
	}
	
	/*Table ın satir sayisini return eder*/
	return rowC;
	
}
/*Tamamlanamadı*/
int makeMove(int table[][COLOUMNSIZE], int rowC, int playerNo, int coorY, 
                int coorX, int direction){
    

    return 0;
}
/*Pieces1 ve pieces2 2D arraylarini belirler ve rowCP1 Ve rowCP2 degerlerini bulur*/
void getPieces(int table[][COLOUMNSIZE], int rowC,int pieces1[][PIECES_SIZE],
                int pieces2[][PIECES_SIZE], int *rowCP1,int *rowCP2 )
{
    
    /*Dongu degiskenleri*/
    int i,j;
   
    /*row countlarin ilk deger ataması*/
    *rowCP2 = 0; 
    *rowCP1 = 0; 
    
    
    /*1.oyuncunun taslarinin koordinatlarını bulup pieces1 2D arrayine atar ve
    pieces1nin rowCP1 ile row countini belirler*/
    for(i=0;i<rowC;i++)
	{
	
		for(j=0;j<COLOUMNSIZE;j++){
		
		    if (table[i][j]==1){
		        pieces1[*rowCP1][0]=j+1; /*y*/
		        pieces1[*rowCP1][1]=i+1; /*x*/
		        (*rowCP1)++;
		    }
		    
        }
    }
    
    /*2.oyuncunun taslarinin koordinatlarını bulup pieces2 2D arrayine atar ve
    pieces2nin rowCP2 ile row countini belirler*/
    for(i=0;i<rowC;i++)
	{
		for(j=0;j<COLOUMNSIZE;j++){
		   
            if (table[i][j]==2){
		        pieces2[*rowCP2][0]=j+1; /*y*/
		        pieces2[*rowCP2][1]=i+1; /*x*/
		        (*rowCP2)++;
		    }
        }
    }
 
    
}
/*Herhangi oyuncunun taslarinin yerlerini ekrana yazar
 *Hangi oyuncunun taslarini ekrana yazacagimizi belirlemek icin playerNo parametresi aldim*/
void printPieces(int output[][PIECES_SIZE],int rowCP, int playerNo ){
    int i;
    
    printf("player %d = ",playerNo);
    
    /*Herhangi oyuncunun taslarinin yerlerini ekrana yazan dongu */
    for(i=0;i<rowCP;i++) 
	{
	    printf("[ %d, %d ]", output[i][1], output[i][0]);
		
    }
    printf("\n");

}

/*Bu fonksiyon table i ekrana yazdirir*/
void printGame(int table[][COLOUMNSIZE], int rowC){
    /*Dongü degiskenleri*/
    int i=0,j=0;
    
    /*Table ı ekrana yazdiran dongu*/
    for(i=0;i<rowC;i++)
	{
		for(j=0;j<COLOUMNSIZE;j++)
		{
		    /*Dosyadaki -1leri X basar*/
		    if(table[i][j]==-1){
		        printf("X  ");
		        continue;
		    }
		    /*Dosyadaki 0 lari - basar*/
		    else if(table[i][j]==0){
		        printf("-  ");
		        continue;
		    }
		    /*Arrayi ekrana yazdirir*/
		    else 
			    printf("%d  ",table[i][j]);
		}	
		printf("\n");
	}
  
}

/*Bu fonksiyon table i 2.nin oyuncunun bakis acisindan goruntusu*/
void getOppositeView(int tableIn[][COLOUMNSIZE], int rowC){
    int j,i;
    printf("***********************\n");
    
    /*Matrisimizi tersten ekrana yazar */
    for(i=rowC-1; i>=0; i--)
	{
		for(j=COLOUMNSIZE-1; j>=0; j--){
		
            if(tableIn[i][j]==-1){
                printf("X  ");
                continue;
            }

            else if(tableIn[i][j]==0){
                printf("-  ");
                continue;
            } 
            else 
                printf("%d  ",tableIn[i][j]);
		}	    
			
		printf("\n");
	}

}

/*Gidecegi yer engelse yada rakibin tasi varsa 1 return eder degilse 0 return eder*/
int isBlocked(int table[][COLOUMNSIZE], int rowC, int playerNo, int coorY, int coorX){
    
    /*Rakibin numarasına 1 diyelim*/
    int opponentNo=1;
    
    /*eger player no 1se rakinbin nosu 2dir*/
    if (opponentNo==playerNo)
        opponentNo=2;
        
    /*Gidecegi yer engelse yada rakibin tasi varsa 1 return eder*/    
    if(table[coorX][coorY]==-1 || table[coorX][coorY]==opponentNo  )
        return 1;
    else
        return 0;
}


int isTerminated(int table[][COLOUMNSIZE], int rowC){

     
    return 0;    
}

void saveGame(char *savingFileName, int table[][COLOUMNSIZE], int rowC){
    /*Döngü degişkeni*/
    int i=0,j=0;
    /*Kaydedilecek dosyanin pointeri*/
    FILE * savingFilePtr;
    /*Dosyayi acar*/
    savingFilePtr=fopen(savingFileName,"w");
 
    for(i=0;i<rowC;i++)
	{
		for(j=0;j<COLOUMNSIZE;j++){
		
		if(table[i][j]==-1){
		    fprintf(savingFilePtr,"X  ");
		    continue;
		  }
		  
		  else if(table[i][j]==0){
		    fprintf(savingFilePtr,"-  ");
		    continue;
		  } 
		  else 
			fprintf(savingFilePtr,"%d  ",table[i][j]);
		}	
			
		fprintf(savingFilePtr,"\n");
		
	}
	
    /*Dosyayi kapatir*/
    fclose(savingFilePtr);
}







		    
