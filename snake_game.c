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
    
        printf("WANNA PLAY 1 or 0\n");
        scanf("%d",&s);
        if(s==1)
        {
              while (1)
              {
                draw();
                input();
                logic();
                sleep(2);
                system("cls");
              }
        }
        else
        exit(0);
}
void draw()
{
    for(i=0;i<=20;i++)
    {
        for(j=0;j<=20;j++)
        {
            if(i==0||j==0||j==20||i==20)
            {
                printf("#");
            }
            else if(i==fruitx && j==fruity)
            {
                printf("*");
            }
            else if(i==p && j==q)
            {
               // for(int l=1;l<=k/30+1;l++)
                //{
                printf("0");
                /*if (l>1)
                {
                    j++;
                }
                }*/
            }

            else
            printf(" ");
        }
        printf("\n");
    }
    printf("enter e to exit\n");
    printf("score:%d",k);
    //printf("%d",k/30);
    printf("\nenter your choice\n");
}
void setup()
{
    srand(time(0));
    fruitx=rand()%19+1;
    fruity=rand()%19+1;
   // printf("%d %d",fruitx,fruity);
   //return 0;

}
void input()
{
    char a,w,x,d;
    if(kbhit())
    {
    //scanf("%c",&c);
    switch(getch())
    {
    case 'w':
        p--;
        break;
    case 'd':
        q++;
        break;
    case 'a':
        q--;
        break;
    case 'x':
        p++;
        break;
    case 'e':
         exit(0);
         break;
    default:
        printf("enter valid choice\n");
        break;
    }
    }
    //sleep(0.01);
   // return 0;
}
void logic()
{
    sleep(1);
    if(p==fruitx&&q==fruity)
    {
       k+=10;
       setup();
    }
    else if(p==0||q==0|p==20||q==20)
    {
        printf("GAME OVER\n");
        printf("SCORE:%d",k);
        exit(0);
    }
   // return 0;
}