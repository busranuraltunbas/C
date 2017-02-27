/////////////////////////////////////////////////////
//H01_121044076_Busra_Nur_Altunbas                 //
//Written by Busra Nur Altunbas on 06 October 2015 //  
//Desciription:                                    //
//Play the classical game reversi                  //
/////////////////////////////////////////////////////
#include<iostream>
const int MAX = 30;
//----------------------------------------------------------------------------//
//                       Function Prototypes                                  //
//----------------------------------------------------------------------------//
void fillTable(int *size, char arr[][MAX]);
void printTable(int *size, char arr[][MAX]);
int userCount(int *size,char arr[][MAX],int *uCoord_x, int *uCoord_y);
int computerCount(int *size,char arr[][MAX],int *cCoord_x, int *cCoord_y);
void startGame(int *size, char arr[][MAX],int *row, int *coloum);
int check_coordinate(int *size, char arr[][MAX],int *row, int *coloum);
int computerBaslangicNoktasi(int *size, char arr[][MAX],int *cBasCoord_x, int *cBasCoord_y);
int computerLegal(int *size, char arr[][MAX],int *cLegal_x, int *cLegal_y,int *legal_x, int *legal_y);

//START_OF_MAIN

using namespace std;
int main(){
    int size,i,j,a,b;
    //user ve computer countlari.
    int uCount=0, cCount=0;
    int my_row = 0, my_col;
    int row=0 ,coloum=0;
    int location_x, location_y;

    int uCoord_x, uCoord_y,cCoord_x, cCoord_y;
    int cBasCoord_x, cBasCoord_y;
    int legal_x, legal_y;
    char arr[MAX][MAX];
    
    //Arrayin bos kisimlarina nokta koyar.
    cout<<"Please enter size of game that between 4 to 20:";
    cin>>size;
    if((size >= 4) && (size <= 20))
    {
        for(i=1; i<=size; ++i)
        {
            for(j=1; j<=size; ++j)
            {
                arr[i][j] = '.';
            
            }
        }
        fillTable(&size,arr);
        printTable(&size,arr);

    }     
    //Size araligi dogru girildigi surece kullanicidan size ister.
    while((size < 4) || (size > 20))
    {
        cout<<"Please enter size of game that between 4 to 20:";
        cin>>size;
        if((size >= 4) && (size <= 20))
        {
            for(i=1; i<=size; ++i)
            {
                for(j=1; j<=size; ++j)
                {
                    arr[i][j] = '.';
                
                }
            }
            fillTable(&size,arr);
            printTable(&size,arr);
        }

    }
    //Userin oyunu baslatma yeri.
    startGame(&size, arr, &row, &coloum);
    
    //Her adimda puanlari sayar.
    uCount = userCount(&size,arr, &uCoord_x, &uCoord_y);
    cCount = computerCount(&size,arr,&cCoord_x, &cCoord_y);
    
    
    cout<<"User:" << uCount;
    cout<<" Computer:" << cCount;
    cout<<endl;
    
    //Computerin oldugu yerler.
    computerBaslangicNoktasi(&size,arr,&cBasCoord_x, &cBasCoord_y);
    
    //Computerin oynama ihtimallerine bakar.
    computerLegal(&size,arr,&cBasCoord_x, &cBasCoord_y, &legal_x, &legal_y);

    //Nerelere hamle yapilacagini check eder ve ona gore oynar.
    check_coordinate(&size,arr, &legal_x, &legal_y);
    
    //Oyunu print eder.
    printTable(&size,arr);
    
    uCount = userCount(&size,arr, &uCoord_x, &uCoord_y);
    cCount = computerCount(&size,arr,&cCoord_x, &cCoord_y);
    
    cout<<"User:" << uCount;
    cout<<" Computer:" << cCount;
    cout<<endl;
    
    
    return 0;
    //END_OF_MAIN
}
//oyunun oynanmamis tablo hali
void fillTable(int *size, char arr[][MAX])
{
    int i,j;
    char arr1;
    for(i=1; i<=*size; ++i)
    {
    
        for(j=1; j<=*size; ++j)
        {
        
            if((i==*size/2  ) && (j==*size/2 ))
            {
                 arr[i][j] = 'X';
            
            }
            if((i==*size/2 ) && (j==*size/2 + 1))
            {
                 arr[i][j] = 'O';
            
            }
            if((i==*size/2 + 1) && (j==*size/2 ))
            {
                 arr[i][j] = 'O';
            
            }
            if((i==*size/2 + 1 ) && (j==*size/2 + 1))
            {
                 arr[i][j] = 'X';
            
            }
      
        }
       
    }

}
//Oyunu print eder.
void printTable(int *size, char arr[][MAX])
{
    int i,j,k,l;
    char harf; 
    cout<<' ';
    if(*size>9)
        cout<<' ';
    for(l=0; l<*size; ++l)
    {
        harf = 97 + l;
        cout<<harf;
    }
    
    cout<<endl;
    //2D array ekrana basildi.
    if(*size>9)
    {
        for(i=1; i<=*size; ++i)
        {
            cout<<i;
            if(i<=9)
            {
                cout<<' ';
                for(j=1; j<=*size; ++j)
                {
                    cout<< arr[i][j];
                
                }
            }
            else
            {
                for(j=1; j<=*size; ++j)
                {
                    cout<< arr[i][j];
                
                }
            
            }
          
            cout<<endl;
        }
    }
    else
    {
        for(i=1; i<=*size; ++i)
        {
            cout<<i;
         
            for(j=1; j<=*size; ++j)
            {
                cout<< arr[i][j];
            
            }
            cout<<endl;
        }
    
    }

}

//User countunu hesaplar.
int userCount(int *size,char arr[][MAX],int *uCoord_x, int *uCoord_y)
{
    int uCount=0;
    int i,j;
    //int coord_x, coord_y;
    for(i=1; i<=*size; ++i)
    {
        for(j=1; j<=*size; ++j)
        {
            if(arr[i][j] == 'O')
            {
                uCount++;
            
            }
        }
    }
    for(i=0; i<*size; ++i)
    {
        for(j=0; j<*size; ++j)
        {
            if(arr[i][j] == 'O')
            {
                *uCoord_x = i;
                *uCoord_y = j;
                break;
            
            }
        }
    }
   
    
    return uCount;
}
//Computer countunu hesaplar.
int computerCount(int *size,char arr[][MAX],int *cCoord_x, int *cCoord_y)
{
    int cCount=0;
    int i,j;
    for(i=1; i<=*size; ++i)
    {
        for(j=1; j<=*size; ++j)
        {
            if(arr[i][j] == 'X')
            {
                cCount++;
            
            }
        }
    }
    for(i=1; i<=*size; ++i)
    {
        for(j=1; j<=*size; ++j)
        {
            if(arr[i][j] == 'X')
            {
                *cCoord_x = i;
                *cCoord_y = j;
                break;
            
            }
        }
    }
    
    
    return cCount;
}
//Userin oynama ihtimallerine bakar.
void startGame(int *size, char arr[][MAX], int *row, int *coloum)
{
    //degisimden onceki, o eklemeliyi sil!!!!!
    int my_row = 0, my_col;
    char location_col ;
    cout<<"Please enter the coordinate for move (like 1a):";
    cin>>my_row;
    cin>>location_col;
    my_col = location_col - 'a';
    *row = my_row;
    *coloum = my_col;
    if(((my_row == *size/2 + 1) && (my_col == *size/2 + 1) ||
        (my_row == *size/2 - 1) && (my_col == *size/2 - 1) ||
        (my_row == *size/2 + 2) && (my_col == *size/2) ||
        (my_row == *size/2) && (my_col == *size/2 - 2)))
    {
        //cout<<"Tebrikler";
        //cout<<my_col;
        arr[my_row][my_col + 1] = 'O';
        fillTable(size,arr);
        printTable(size,arr);
        check_coordinate(size,arr, row, coloum);
        printTable(size,arr);
    }
    else
           
    {
        cout<<"Please enter legal coordinate!" <<endl;
        cout<<"Enter the coordinate for move (like 1a):";
        cin>>my_row;
        cin>>location_col;
        my_col = location_col - 'a';
        *row = my_row;
        *coloum = my_col;
        if(((my_row == *size/2 + 1) && (my_col == *size/2 + 1) ||
            (my_row == *size/2 - 1) && (my_col == *size/2 - 1) ||
            (my_row == *size/2 + 2) && (my_col == *size/2) ||
            (my_row == *size/2) && (my_col == *size/2 - 2)))
        {
            arr[my_row][my_col+1] = 'O';
            fillTable(size,arr);
            printTable(size,arr);
            check_coordinate(size,arr, row, coloum);
            printTable(size,arr);
            
        }
        
    }

}
//Hem userin hem computerin oynayabilecegi yerleri check eder ve oynar.
int check_coordinate(int *size, char arr[][MAX],int *row, int *coloum)
{
    if((arr[*row][*coloum + 1] == 'O') && (arr[*row - 1][*coloum + 1] == 'X'))
    {
        //userin in yukari tarafini check eder.
        if((arr[*row - 2][*coloum + 1] == 'O'))
        {
            arr[*row - 1][*coloum + 1] = 'O';
        }
    }
    //x
    if((arr[*row][*coloum] == 'X') && (arr[*row - 1][*coloum] == 'O'))
    {
        //computer in yukari tarafini check eder.
        if(( arr[*row - 2][*coloum] == 'X' ))
        {
            arr[*row - 1][*coloum] = 'X';
        }
       
        
    }
    if((arr[*row][*coloum + 1] == 'O') && (arr[*row + 1][*coloum + 1] == 'X'))
    {
        //userin in asagi tarafini check eder.
        if((arr[*row + 2][*coloum + 1] == 'O'))
        {
            arr[*row + 1][*coloum + 1] = 'O';
        }
    }
    if((arr[*row][*coloum ] == 'X') && (arr[*row + 1][*coloum] == 'O'))
    {
        //computer in asagi tarafini check eder.
        if(( arr[*row + 2][*coloum ] == 'X' ))
        {
            arr[*row + 1][*coloum] = 'X';
        }
       
    }
    if((arr[*row][*coloum + 1 ] == 'O') && (arr[*row][*coloum ] == 'X'))
    {
        //userin sol tarafini check eder.
        if((arr[*row][*coloum - 1] == 'O'))
        {
            arr[*row][*coloum ] = 'O';
            
        }
        
    }
    if((arr[*row][*coloum ] == 'X') && (arr[*row][*coloum - 1] == 'O'))
    {
        //computerin sol tarafini check eder.
        if(( arr[*row][*coloum - 2] == 'X' ))
        {
            arr[*row][*coloum - 1] = 'X';
        }
            
        
    }
    if((arr[*row][*coloum + 1] == 'O') && (arr[*row][*coloum + 2] == 'X'))
    {
        //userin sag tarafini check eder.
        if((arr[*row ][*coloum + 3 ] == 'O'))
        {
            arr[*row][*coloum + 2] = 'O';
        }
       
    }
    if((arr[*row][*coloum ] == 'X') && (arr[*row][*coloum + 1] == 'O'))
    {
        //computerin sag tarafini check eder.
        if(( arr[*row][*coloum + 2] == 'X' ))
        {
            arr[*row][*coloum + 1] = 'X';
        }
        
       
    }
    if((arr[*row][*coloum + 1] == 'O') && (arr[*row - 1][*coloum ] == 'X'))   
    {
        //userin yukari sol caprazini check eder.
        if((arr[*row - 2][*coloum - 1 ] == 'O'))
        {
            arr[*row - 1][*coloum ] = 'O';
        }
    } 
    if((arr[*row][*coloum] == 'X') && (arr[*row - 1][*coloum -1] == 'O'))   
    {
        //computerin yukari sol caprazini check eder.
       
        if(( arr[*row - 2][*coloum -2] == 'X' ))
        {
            arr[*row - 1][*coloum -1] = 'X';
        }
        
        
    } 
    if( (arr[*row][*coloum + 1] == 'O') && (arr[*row - 1][*coloum + 2] == 'X'))
    {
        //userin yukari sag caprazini check eder.
        if((arr[*row - 2][*coloum + 3] == 'O'))
        {
            arr[*row - 1][*coloum + 2] = 'O';
        }
    }  
    if( (arr[*row][*coloum] == 'X') && (arr[*row - 1][*coloum + 1] == 'O'))
    {
        //computerin yukari sag caprazini check eder.
       
        if(( arr[*row - 2][*coloum + 2] == 'X' ))
        {
            arr[*row - 1][*coloum + 1] = 'X';
        }
        
    }      
    if( (arr[*row][*coloum + 1] == 'O') && (arr[*row + 1][*coloum] == 'X'))
    {
        //userin asagi sol caprazini check eder.
        if((arr[*row + 2][*coloum - 1] == 'O'))
        {
            arr[*row + 1][*coloum] = 'O';
        }
    }   
    if( (arr[*row][*coloum ] == 'X') && (arr[*row + 1][*coloum - 1] == 'O'))
    {
        //computerin asagi sol caprazini check eder.
       
        if(( arr[*row + 2][*coloum- 2] == 'X' ))
        {
            arr[*row + 1][*coloum - 1] = 'X';
        }
        
    }   
    if((arr[*row][*coloum + 1] == 'O') && (arr[*row + 1][*coloum + 2] == 'X'))  
    {
        //userin asagi sag caprazini check eder.
        if((arr[*row + 2][*coloum + 3] == 'O'))
        {
            arr[*row + 1][*coloum + 2] = 'O';
        }
    } 
    if((arr[*row][*coloum ] == 'X') && (arr[*row + 1][*coloum + 1] == 'O'))  
    {
        //computerin asagi sag caprazini check eder.
        if(( arr[*row + 2][*coloum + 2] == 'X' ))
        {
            arr[*row + 1][*coloum + 1] = 'X';
        }
        
    } 
    //cout<<"check fonksiyonundayim";
    return 0;
}

//Computerin nereden oyuna baslayacagine karar verir.
int computerBaslangicNoktasi(int *size, char arr[][MAX],int *cBasCoord_x, int *cBasCoord_y)
{
    if(arr[*size/2][*size/2] == 'X')
    {
        *cBasCoord_x = *size/2;
        *cBasCoord_y = *size/2;
    
    }
    else if(arr[*size/2 + 1][*size/2 + 1] == 'X')
    {
        *cBasCoord_x = *size/2 + 1;
        *cBasCoord_y = *size/2 + 1;
    
    }
    cout<<endl;
    /*cout<<"bas:"<<*cBasCoord_x;
    cout<<"bas:"<<*cBasCoord_y;*/
    return 1;
}
int computerLegal(int *size, char arr[][MAX],int *cLegal_x, int *cLegal_y, 
int *legal_x, int *legal_y)
{

    if(arr[*cLegal_x][*cLegal_y - 2] == '.')
    {
        arr[*cLegal_x][*cLegal_y - 2] = 'X';
        *legal_x = *cLegal_x;
        *legal_y = *cLegal_y - 2;
    
    }
    else if(arr[*cLegal_x - 2][*cLegal_y ] == '.')
    {
        arr[*cLegal_x - 2][*cLegal_y ] = 'X';
        *legal_x = *cLegal_x - 2;
        *legal_y = *cLegal_y;
    
    
    }
    else if(arr[*cLegal_x - 2][*cLegal_y - 2] == '.')
    {
        arr[*cLegal_x - 2][*cLegal_y - 2] = 'X';
        *legal_x = *cLegal_x - 2;
        *legal_y = *cLegal_y - 2;
    
    
    }
    /*cout<<"legalx:"<<*legal_x;
    cout<<"legaly:"<<*legal_y;*/
    
    
    return 1;
}








