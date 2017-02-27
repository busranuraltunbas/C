/*############################################################################*/
/*HW05_Busra_Nur_Altunbas_121044076_part1.c                                   */
/*Written by Busra Nur Altunbas on March 22, 2015                             */
/*                                                                            */
/*Desciription:                                                               */
/*Car crash simulator program                                                 */
/*                                                                            */
/*Inputs:                                                                     */
/*    Variables                                                               */
/*Outputs:                                                                    */
/*Result:                                                                     */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                        Defines                                             */
/*----------------------------------------------------------------------------*/
#define lenght 50
/*----------------------------------------------------------------------------*/
typedef enum
        {PLAY, CRASH, END}
object_state;
/*----------------------------------------------------------------------------*/
/*                        Function Prototypes                                 */
/*----------------------------------------------------------------------------*/
void make_move(char *object1, double *position1, double *speed1, int weight1, 
char *object2, double *position2, double *speed2, int weight2, object_state *game_state);

double car_crash_time(double position1, double position2, double speed1, double speed2);

void print_game_state(char object1, double position1,char object2, double position2, 
object_state game_state);

/*START_OF_MAIN*/
int main()
{
    /*START_OF_VARIABLES*/
    char object1, object2;
    double position1=0.0, position2=0.0;
    double speed1, speed2;
    int weight1, weight2;
    object_state game_state;
    /*END_OF_VARIABLES*/
    printf("Enter name of first car:");
    scanf(" %c",&object1);
    printf("\nEnter name of second car:");
    scanf(" %c",&object2);
    printf("\nEnter speed of first car:");
    scanf("%lf",&speed1);
    printf("\nEnter speed of second car:");
    scanf("%lf",&speed2);
    printf("\nEnter weight of first car:");
    scanf("%d",&weight1);
    printf("\nEnter weight of second car:");
    scanf("%d",&weight2);
    make_move(&object1, &position1, &speed1, weight1,&object2, &position2, &speed2,weight2, &game_state);
    car_crash_time( position1, position2, speed1, speed2);
    print_game_state(object1, position1,object2, position2, game_state);

    return 0;
    /*END_OF_MAIN*/
}
/*Hizlara gore arabalarin carpisma anina kadar olan hareketlerini gösterir.*/
void make_move(char *object1, double *position1, double *speed1, int weight1, 
char *object2, double *position2, double *speed2, int weight2, object_state *game_state)
{
    double vort=0.0;
    char ch='X';
    int i,k=0,m=0,n=0,l=0,s=0,p=0,a=0;
    double tire=0.0,abc=0.0;
    
    /*Yolun uzunlugunu gecmeden ilerlemek icin kullanilan dongu */
    while(((*position1) + 2 <= lenght )|| ((*position2) + 2) <= lenght)
    {
    tire = ((double)lenght - ((*position1)  + 2.0)+  (*position2));
    abc=((*position1) + (*position2) + 2);
    /*printf("tire:%.3f\n",tire);
    printf("abc:%.3f\n",abc);*/
    
        /*1.arabanin geride biraktigi yolu*/
        for(k=0; k<*position1; k++)
        {
            printf("_");

        }
        printf("%c",*object1);
        
        if((*position2>=0) && (*position1<=0))
        {
         
            for(m=lenght-2; m>0; m--)
            {
                printf("_");

            }
            if(tire<lenght)
                printf("%c",*object2);
            if(tire>lenght)
                printf("_");

        }
        else if((*position2>=0) && (*position1>=0))
        {
            /*1.araba ile 2. araba arasindaki mesafe*/
            for(l=lenght -2 - *position1; l>0; l--)
            {
                printf("_");

            }
            /*if(tire>lenght)
                break;*/
            printf("%c",*object2);
           
        }
     
        else if((*position2<0) && (*position1<0))
        {
            for(n=lenght + (*position2); n>0; n--)
            {
                printf("_");

            }
            printf("%c",*object2);
            /*2.arabanin geride biraktigi yolu*/
            for(n=0; n<-(*position2)-2; n++)
            {
                printf("_");

            }
            if(*position2<-lenght)
                break;
        
        }
        
        
        else if((*position2<=0) && (*position1>=0))
        {
            for(s=lenght-2+(*position2) - *position1; s>0 ;s--)
            {
                printf("_");

            }
            printf("%c",*object2);
            /*2.arabanin geride biraktigi yolu*/
            for(p=0; p<-(*position2); p++)
            {
                printf("_");

            }
        }
    
    
        *position1 = *position1 + *speed1;
        
        *position2 = *position2 + *speed2;
        printf("\n");
        for(i=0; i<5; i++)
        {
            printf("123456789");
            printf("0");

        }
        printf("\n");
        if(tire==0)
            break;
        /*if(tire>lenght)
            break;*/
        /*if(*position1>lenght- (2.0 + *position2))
            break;*/
        if(*position2< -(lenght- 2.0 - *position1))
            break;
        
        
         /*if(*position1<lenght+ (2.0 - *position2))
            break;
        if(*position2> (lenght+ 2.0 + *position1))
            break;*/
        /*printf("position1:%f\n",*position1);
        printf("position2: %f",*position2);*/

    }
  
}
/*Arabalarin carpisma hizlarini bulur ve return eder.*/
double car_crash_time(double position1, double position2, double speed1, double speed2)
{
    double t=0.0;
    if((speed1 < 0)  && (speed2 > 0))
        t=(double)lenght/(-(speed1) + speed2);
    else  if((speed2 < 0) && (speed1 > 0))
        t=(double)lenght/(speed1 + -(speed2)); 
    else  if((speed2 < 0) && (speed1 < 0))
        t=(double)lenght/(-(speed1) + -(speed2)); 
    else  if((speed2 > 0) && (speed1 > 0))
        t=(double)lenght/(speed1 + speed2); 
    return t;
}

void print_game_state(char object1, double position1,char object2, double position2, 
object_state game_state)
{



}

/*############################################################################*/
/*                End of HW05_Busra_Nur_Altunbas_121044076_part1.c            */
/*############################################################################*/


