//creating protype snake game in c language
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
void draw();
void setup();
void input();
void logic();
int i,j,fruitx=5,fruity=5,k=0,p=10,q=10,c,s;
int main()
{
       //for choosing whether to play or not
        printf("WANNA PLAY 1 or 0\n");
        scanf("%d",&s);
        //if user wants to play
        if(s==1)
        {   
            //for infinite loop
              while (1)
              {
                draw();
                input();
                logic();
                sleep(2);//to deplay while loop by 2 seconds
                system("cls");
              }
        }
        else
        exit(0);
}
void draw()//to print the game
{
    for(i=0;i<=20;i++) //for columns
    {
        for(j=0;j<=20;j++)//for rows
        {
            if(i==0||j==0||j==20||i==20)//for printing boundary
            {
                printf("#");
            }
            else if(i==fruitx && j==fruity)
            {
                printf("*"); //for printing fruit aka * symbol 
            }
            else if(i==p && j==q) 
            {
                printf("0"); //for printing snake aka 0 symbol 
            }

            else
            printf(" ");// for background
        }
        printf("\n");// for next line
    }
    printf("enter e to exit\n");//command for exit
    printf("score:%d",k); //for printing score
    printf("\nenter your choice\n"); //for printing to ask user choice of direction
}
void setup() //for generating a fruit 
{
    srand(time(0)); //for generating random value 
    fruitx=rand()%19+1;
    fruity=rand()%19+1;
}
void input() //for accepting value
{
    char a,w,x,d;
    if(kbhit()) //if keyboard hit
    {
    switch(getch())//for accepting character
    {
    case 'w': // for moving upwards direction
        p--;
        break;
    case 'd':// for moving rightside
        q++;
        break;
    case 'a': //for moving leftside
        q--;
        break;
    case 'x': //for moving downwards direction
        p++;
        break;
    case 'e': //for exiting from game
         exit(0);
         break;
    default:
        printf("enter valid choice\n");// other than w,a,d,x  are invalid choices
        break;
    }
    }
}
void logic()
{
    sleep(1);//for delaying for 1 seconds
    if(p==fruitx&&q==fruity) //for checking whether * hitting 0 or not
    {
       k+=10;//to increase the score
       setup();//for generating another fruit
    }
    else if(p==0||q==0|p==20||q==20) //for checking whether 0 hit the boundary
    {
        printf("GAME OVER\n"); //for printing after the condition is true
        printf("SCORE:%d",k); //for displaying the score
        exit(0); //for exiting from the game 
    }
}