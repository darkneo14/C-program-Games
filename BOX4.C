#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<alloc.h>
#include<dos.h>
#include<graphics.h>
 union REGS in,out;
int xp,bt,yp,xp1,yp1,bt1,ax,bx,ay,by;           //for mouse status..
int m,mov;
char ch,s[50],str[50];
typedef struct node{
int data;
struct node *up,*down,*left,*right;
}node;
node *t,*t1,*e,*e1,*head=NULL,*u,*temp,*uend;
void display()
{

    int i,j;
    cleardevice();
for(i=0,t=head;i<7;i++,t=t->down)
{
 for(j=0,t1=t;j<7;j++,t1=t1->right)
 {
  if(t1->data!=0)
   {
    if(t1->data==1)
     {
      setcolor(15);        //red
      setfillstyle(SOLID_FILL,4);
      rectangle(100+j*50,100+i*50,150+j*50,150+i*50);
      floodfill(125+j*50,125+i*50,15);
     }
    if(t1->data==2)
     {
      setcolor(15);        //blue
      setfillstyle(SOLID_FILL,1);
      rectangle(100+j*50,100+i*50,150+j*50,150+i*50);
      floodfill(125+j*50,125+i*50,15);
     }
    if(t1->data==3)
     {
      setcolor(15);        //green
      setfillstyle(SOLID_FILL,2);
      rectangle(100+j*50,100+i*50,150+j*50,150+i*50);
      floodfill(125+j*50,125+i*50,15);
     }
    if(t1->data==4)
     {
      setcolor(15);        //yellow
      setfillstyle(SOLID_FILL,3);
      rectangle(100+j*50,100+i*50,150+j*50,150+i*50);
      floodfill(125+j*50,125+i*50,15);
     }
     if(t1->data==5)
     {
      setcolor(15);        //yellow
      setfillstyle(SOLID_FILL,14);
      rectangle(100+j*50,100+i*50,150+j*50,150+i*50);
      floodfill(125+j*50,125+i*50,15);
     }

    }
}
}
setcolor(15);
}
void movem()
{
 int i,j;
 mov=0;
 for(i=0,t=head;i<7;i++,t=t->down)
 {
  for(j=0,t1=t;j<7;j++,t1=t1->right)
  {
   if(t1->data==0)
   {
    if(t1->up->data!=0)
     mov=1;
    e=t1;
    while(e->up!=NULL)
    {
     e->data=e->up->data+e->data;
     e->up->data=e->data-e->up->data;
     e->data=e->data-e->up->data;
     e=e->up;
    }
   }
  }
 }
 display();
 delay(500);
}


void check()
{
  int i,j,a=0;
  for(i=0,t=head;i<7;i++,t=t->down)
   {
    if(a==1)
    break;
    for(j=0,t1=t;j<7;j++,t1=t1->right)
     {
      if(i<=4)
       {
	if((t1->data==t1->down->data)&&(t1->data==t1->down->down->data)&&(t1->data!=0))
	 {
	  a=1;
	  t1->down->down->data=t1->down->data=t1->data=0;
	  e=t1->down->down;
	  break;
	 }
       }
      if(j<=4)
       {
	if((t1->data==t1->right->data)&&(t1->data==t1->right->right->data)&&(t1->data!=0))
	 {
	   a=1;
	   t1->data=t1->right->data=t1->right->right->data=0;
	   break;
	 }
       }
      }
     }
     if(a==1)
     check();
}
void create()
{
int i,j;
for(i=0;i<7;i++)
{
 temp=(node*)malloc(sizeof(node));
 temp->right=temp->left=temp->down=temp->up=NULL;
 temp->data=0;
 if(i==0)
  head=temp;
 else
 {
  uend->down=temp;
  temp->up=uend;
 }
 e=temp;
  for(j=0;j<7;j++)
  {
   t=(node*)malloc(sizeof(node));
   t->right=t->left=t->down=t->up=NULL;
   t->data=0;
   e->right=t;
   t->left=e;
   if(i!=0)
   {
    uend=uend->right;
    uend->down=t;
    t->up=uend;
   }
   e=t;
  }
 uend=temp;
}

}





     int callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);
	      return(1);
       }
       void mouseposi(int *x,int *y,int *b)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      *b=out.x.bx;
	      *x=out.x.cx;
	      *y=out.x.dx;
	}
       void mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);

       }




void getcd()
{
ay=(xp-100)/50;
ax=(yp-100)/50;
bx=(yp1-100)/50;
by=(xp1-100)/50;
}
int checkcd()
{
if(ax==bx+1)
{
 if(ay==by)
  return(1);
 else
  return(0);
}
if(ax==bx-1)
{
 if(ay==by)
  return(1);
 else
  return(0);
}
if(ay==by+1)
{
 if(ax==bx)
  return(1);
 else
  return(0);
}
if(ay==by-1)
{
 if(ax==bx)
  return(1);
 else
  return(0);
}
return(0);
}

int checkb()
{
int i,j,k=0;
for(i=0,t=head;i<7;i++,t=t->down)
{
 for(j=0,t1=t;j<7;j++,t1=t1->right)
  {
   if(t1->data!=0)
    k=1;
   }
}
return(k);
}
void level1()
{
int i,j;
t=head;
t=t->down;
for(i=0;i<3;i++)
t=t->right;
t->data=1;
t=head->down->down;
for(i=0;i<3;i++)
t=t->right;
t->data=2;
t=head->down->down->down;
for(i=0;i<3;i++)
t=t->right;
t->data=1;
for(i=0,t=head;i<4;i++)
t=t->down;
for(i=0;i<2;i++)
t=t->right;
t->data=1;
t=t->right;
t->data=3;
t=t->right;
t->data=3;
for(i=0,t=head;i<5;i++)
t=t->down;
t=t->right;
//t=t->right;
t->data=1;
t=t->right;
t->data=2;
t=t->right;
t->data=2;
t=t->right;
t->data=3;
t=t->right;
t->data=3;
t=t->down;
t=t->right;
t->data=3;
t=t->left;
t->data=2;
t=t->left;
t->data=1;
t=t->left;
t->data=3;
t=t->left;
t->data=1;
t=t->left;
t->data=2;
t=t->left;
t->data=2;
}

void level2()
{
int i,j;
for(i=0,t=head;i<7;i++,t=t->down)
{
 for(j=0,t1=t;j<7;j++,t1=t1->right)
   t1->data=0;
}
for(i=0,t=head;i<4;i++)
t=t->down;
t=t->right->right;
t->data=1;
t=t->right;
t->data=2;
t=t->right;
t=t->down;
t->data=3;
t=t->left;
t->data=2;
t=t->left;
t->data=2;
t=t->down;
t->data=1;
t=t->right;
t->data=1;
t=t->right;
t->data=3;
t=t->right;
t->data=3;
}
void level3()
{
int i,j;
for(i=0,t=head;i<7;i++,t=t->down)
{
 for(j=0,t1=t;j<7;j++,t1=t1->right)
   t1->data=0;
}
t=head;
t=t->down->down;
t=t->right->right;
t->data=1;
t=t->down;
t->data=2;
t=t->left;
t->data=1;
t=t->down;
t->data=2;
t=t->right;
t->data=3;
t=t->right;
t->data=1;
t=t->down;
t->data=3;
t=t->left;
t->data=4;
t=t->left;
t->data=5;
t=t->left;
t->data=2;
t=t->down;
t->data=5;
t=t->right;
t->data=4;
t=t->right;
t->data=5;
t=t->right;
t->data=4;
t=t->right;
t->data=3;
}






void main()
{
int i,j,gd=DETECT,gm=0,z=0,move=2;
initgraph(&gd,&gm,"");
setcolor(5);
create();
settextstyle(1,0,5);
outtextxy(150,100,"WELCOME");
outtextxy(200,160,"TO");
outtextxy(160,220,"SWAP  THE");
outtextxy(190,280,"BOX");
getch();
cleardevice();
settextstyle(0,0,1);
level1();
display();
callmouse();
m=1;
move=2;
while(move!=0&&m!=0)
{
z=0;
sprintf(str,"moves= %d",move);
outtextxy(5,45,str);

while(z==0)
{
z=0;
bt=0;
outtextxy(50,25,"Enter Your Move");
while(bt!=1)
{
//mouseposi(&xp,&yp,&bt);
in.x.ax=3;
	      int86(51,&in,&out);
	      bt=out.x.bx;
	      xp=out.x.cx;
	      yp=out.x.dx;
}


//sprintf(s,"%d, %d, %d",bt,xp,yp);
//outtextxy(5,25,s);
ch=getch();
bt1=0;
if(ch=='n')
exit(0);
while(bt1!=1)
{
//mouseposi(&xp1,&yp1,&bt1);
in.x.ax=3;
	      int86(51,&in,&out);
	      bt1=out.x.bx;
	      xp1=out.x.cx;
	      yp1=out.x.dx;
}
sprintf(s,"%d, %d, %d",bt1,xp1,yp1);
outtextxy(5,25,s);
getcd();
z=checkcd();
if(z==0)
outtextxy(5,15,"Wrong Input...Try Again");
}
for(i=0,t=head;i<ax;i++)
 t=t->down;
for(j=0;j<ay;j++)
 t=t->right;
for(i=0,e=head;i<bx;i++)
 e=e->down;
for(j=0;j<by;j++)
 e=e->right;
i=e->data;
e->data=t->data;
t->data=i;
display();
check();
movem();
while(mov!=0)
{
check();
movem();
}

ch=getch();
if(ch=='n')
break;
//delay(500);
display();
move--;
m=checkb();
}
if(move==0 && m==1)
outtextxy(5,25,"GAME  OVER!!!!!");
if(m==0)
{
outtextxy(5,25,"YOU WON!!!");
outtextxy(5,40,"To Play Next Level Enter 'y'");
outtextxy(5,60,"Press 'n' to Exit");
ch=getch();
cleardevice();
if(ch=='n')
{
outtextxy(5,25,"Thanx for Playing.");
outtextxy(5,40,"Exiting");
getch();
exit(0);
}
else
{
level2();
display();

m=1;
move=2;
while(move!=0&&m!=0)
{
z=0;
sprintf(str,"moves= %d",move);
outtextxy(5,45,str);

while(z==0)
{
z=0;
bt=0;
outtextxy(50,25,"Enter Your Move");
while(bt!=1)
{
//mouseposi(&xp,&yp,&bt);
in.x.ax=3;
	      int86(51,&in,&out);
	      bt=out.x.bx;
	      xp=out.x.cx;
	      yp=out.x.dx;
}


//sprintf(s,"%d, %d, %d",bt,xp,yp);
//outtextxy(5,25,s);
ch=getch();
bt1=0;
if(ch=='n')
exit(0);
while(bt1!=1)
{
//mouseposi(&xp1,&yp1,&bt1);
in.x.ax=3;
	      int86(51,&in,&out);
	      bt1=out.x.bx;
	      xp1=out.x.cx;
	      yp1=out.x.dx;
}
sprintf(s,"%d, %d, %d",bt1,xp1,yp1);
outtextxy(5,25,s);
getcd();
z=checkcd();
if(z==0)
outtextxy(5,15,"Wrong Input...Try Again");
}
for(i=0,t=head;i<ax;i++)
 t=t->down;
for(j=0;j<ay;j++)
 t=t->right;
for(i=0,e=head;i<bx;i++)
 e=e->down;
for(j=0;j<by;j++)
 e=e->right;
i=e->data;
e->data=t->data;
t->data=i;
display();
check();
movem();
while(mov!=0)
{
check();
movem();
}
//sprintf(str,"move= %d",move);
//outtextxy(5,45,str);
ch=getch();
if(ch=='n')
break;
//delay(500);
display();
move--;
m=checkb();
}
}
}
if(move==0 && m==1)
outtextxy(5,25,"GAME  OVER!!!!!");
if(m==0)
{
outtextxy(5,25,"YOU WON!!!");
outtextxy(5,40,"To Play Next Level Enter 'y'");
outtextxy(5,60,"Press 'n' to Exit");
ch=getch();
cleardevice();
if(ch=='n')
{
outtextxy(5,25,"Thanx for Playing.");
outtextxy(5,40,"Exiting");
getch();
exit(0);
}
else
{
level3();
display();

m=1;
move=1;
while(move!=0&&m!=0)
{
z=0;
sprintf(str,"moves= %d",move);
outtextxy(5,45,str);

while(z==0)
{
z=0;
bt=0;
outtextxy(50,25,"Enter Your Move");
while(bt!=1)
{
//mouseposi(&xp,&yp,&bt);
in.x.ax=3;
	      int86(51,&in,&out);
	      bt=out.x.bx;
	      xp=out.x.cx;
	      yp=out.x.dx;
}


//sprintf(s,"%d, %d, %d",bt,xp,yp);
//outtextxy(5,25,s);
ch=getch();
bt1=0;
if(ch=='n')
exit(0);
while(bt1!=1)
{
//mouseposi(&xp1,&yp1,&bt1);
in.x.ax=3;
	      int86(51,&in,&out);
	      bt1=out.x.bx;
	      xp1=out.x.cx;
	      yp1=out.x.dx;
}
sprintf(s,"%d, %d, %d",bt1,xp1,yp1);
outtextxy(5,25,s);
getcd();
z=checkcd();
if(z==0)
outtextxy(5,15,"Wrong Input...Try Again");
}
for(i=0,t=head;i<ax;i++)
 t=t->down;
for(j=0;j<ay;j++)
 t=t->right;
for(i=0,e=head;i<bx;i++)
 e=e->down;
for(j=0;j<by;j++)
 e=e->right;
i=e->data;
e->data=t->data;
t->data=i;
display();
check();
movem();
while(mov!=0)
{
check();
movem();
}
//sprintf(str,"move= %d",move);
//outtextxy(5,45,str);
ch=getch();
if(ch=='n')
break;
//delay(500);
display();
move--;
m=checkb();
}
}
}
if(move==0 && m==1)
outtextxy(5,25,"GAME  OVER!!!!!");
if(m==0)
{
outtextxy(5,25,"Congratulations....YOU WON!!!");
}
 getch();
}











