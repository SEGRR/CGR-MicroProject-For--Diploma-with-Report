
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<dos.h>
int x=300,y=150;
int down[7];
int right[7];
int left[7];
int flag=0;
int flag_target[10]={0,0,0,0,0,0,0,0,0,0};

void aim(int a,int b)
{
 left[0]=a-20;
 left[1]=a-40;
 left[2]=a-60;
 left[3]=a-80;
 left[4]=a-100;
 left[5]=a-120;
 left[6]=a-140;

right[0]=a+20;
right[1]=a+40;
right[2]=a+60;
right[3]=a+80;
right[4]=a+100;
right[5]=a+120;
right[6]=a+140;

down[0]=b+20;
down[1]=b+40;
down[2]=b+60;
down[3]=b+80;
down[4]=b+100;
down[5]=b+120;
down[6]=b+140;



line(left[0],b+3,left[0],b-3);
line(left[1],b+5,left[1],b-5);
line(left[2],b+5,left[2],b-3);
line(left[3],b+5,left[3],b-5);
line(left[4],b+5,left[4],b-3);
line(left[5],b+5,left[5],b-5);
line(left[6],b+5,left[6],b-3);

line(right[0],b+3,right[0],b-3);
line(right[1],b+3,right[1],b-5);
line(right[2],b+3,right[2],b-3);
line(right[3],b+3,right[3],b-5);
line(right[4],b+3,right[4],b-3);
line(right[5],b+3,right[5],b-5);
line(right[6],b+3,right[6],b-3);

line(a+3,down[0],a-3,down[0]);
line(a+5,down[1],a-5,down[1]);
line(a+3,down[2],a-3,down[2]);
line(a+5,down[3],a-5,down[3]);
line(a+3,down[4],a-3,down[4]);
line(a+5,down[5],a-5,down[5]);
line(a+3,down[6],a-3,down[6]);




}

void about()
{
cleardevice();

outtextxy(250,50,"HOW TO PLAY ?");
outtextxy(10,150,"-to move your scope to right press 'd'");
outtextxy(10,170,"-to move your scope to  left press 'a'");
outtextxy(10,200,"-to move your scope to  up press 'w'");
outtextxy(10,230,"-to move your scope to down press 's'");
outtextxy(10,260,"-to shooot bullet  press 'space'");
outtextxy(10,290,"-if your bullet hits your score will increase ");
outtextxy(10,320," -you are not a terminator!!! you have limited bullets ");



outtextxy(250,350," press any key to countinue ");

getch();


}


void loading()
{
int i;

 outtextxy(200,200,"LOADING.....");
 rectangle(200,240,450,280);
for(i=1;i<=250;i++)
{
 delay(10);
 line(200+i,240,200+i,280);

}

about();

cleardevice();

}

void level1()
{

setbkcolor(CYAN);
{
int top=20;
if(flag==1)
{
    // IT WILL CHECK IS SOOTED OR NOT
  top=sqrt(((right[3]-115)*(right[3]-115))+((down[3]-275)*(down[3]-275)));
}
if(top>15 && flag_target[0]==0)
{line(100,350,115,310);
line(130,350,115,310);    // CREATING TOWER ONE 
line(115,310,115,290);   //IF BULLET DOSENT HIT HEAD IT WILL REAMIN SAME
line(115,290,100,310);
line(115,290,130,310);   
circle(115,275,15);
} else{flag_target[0]=1;}

rectangle(80,250,150,350);
line(80,315,150,315);
line(80,350,80,getmaxy());
line(85,350,85,getmaxy());     // IF MAN IS HIT ONLY TOWER WILL REAMIN
line(150,350,150,getmaxy());
line(145,350,145,getmaxy());
line(90,350,90,315);
line(110,350,110,315);
line(130,350,130,315);
line(145,350,145,315);
}
//tower2
{
int top=20;
if(flag==1)
{
top=sqrt(((right[3]-415)*(right[3]-415))+((down[3]-275)*(down[3]-275)));
}
if(top>15  && flag_target[1]==0)
{line(400,350,415,310);
line(430,350,415,310);
line(415,310,415,290);
line(415,290,400,310);     // CREATING TOWER ONE
line(415,290,430,310);     //IF BULLET DOSENT HIT HEAD IT WILL REAMIN SAME
circle(415,275,15);
}else{flag_target[1]=1;}
rectangle(380,250,450,350);
line(380,315,450,315);
line(380,350,380,getmaxy());
line(385,350,385,getmaxy()); 
line(450,350,450,getmaxy());
line(445,350,445,getmaxy());  // IF MAN IS HIT ONLY TOWER WILL REAMIN
line(390,350,390,315);
line(410,350,410,315);
line(430,350,430,315);
line(445,350,445,315);
}


flag=0;
}


int menu()
{
char choice;
int X,Y,rec[4],i;
X=(getmaxx()/2)-150;
Y=getmaxy();
rec[0]=X+40;
rec[2]=rec[0]+200;
rec[1]=Y+30;
rec[3]=Y+200;
settextstyle(1,0,2);
setbkcolor(BLACK);
setcolor(WHITE);
for(i=0;i<=400;i+=5)
{
delay(50);
cleardevice();
outtextxy(X+50,Y-i,"LONEWOLF");

rectangle(rec[0],rec[1]-i,rec[2],rec[3]-i);

outtextxy(rec[0]+50,(rec[1]+20)-i,"PLAY");

line(rec[0],(rec[1]+56)-i,rec[0]+200,(rec[1]+56)-i);

outtextxy(rec[0]+40,(rec[1]+76)-i,"ABOUT");

line(rec[0],(rec[1]+112)-i,rec[0]+200,(rec[1]+112)-i);

outtextxy(rec[0]+50,(rec[1]+136)-i,"QUIT");


}
choice=getch();
switch(choice)
{
  case 'p':
  cleardevice();
   loading();
       break;

   case 'q':
        exit(1);
        break;
    case 'a':
      about();
       break;
}
cleardevice();
return 0;
}



int main()
{ int score=0;
int gd=DETECT,gm;
    //scope
int dist=100,ammo;   //target
char c,AMMO[3];
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
menu();

ammo=5;
while(1)
{

char wind[10],dist[10];



outtextxy(getmaxx()-240,20,"wind:40");
outtextxy(getmaxx()-260,40,"distance:400");


outtextxy(10,30,"Ammo:");

sprintf(AMMO,"%d",ammo);

outtextxy(100,30,AMMO);


setfillstyle(0,BLACK);
level1();

circle(x,y,160);

line(x-160,y,x+160,y);

line(x,y-160,x,y+160);


aim(x,y);

c=getch();
   switch(c)
   {
    case 'a':
        x-=10;
        break;
    case 'd':
          x+=10;
          break;
     case 's':
          y+=10;
          break;
      case 'w':
           y-=10;
           break;

     case 'q':
          menu();
          break;
      case ' ':
         y-=20;
         ammo--;
         flag=1;

   }

   if(ammo==0)
   {   settextstyle(0,0,3);
      outtextxy(200,200,"GAME OVER!!");
       getch();
       menu();
setbkcolor(WHITE);

   }


if(flag_target[0]==1 && flag_target[1]==1)
{
     outtextxy(200,200,"MISSION PASS");
     outtextxy(200,220,"RESPECT+");
      getch();
       menu();
}


   cleardevice();
}
closegraph();

return 0;







}
