#include<stdio.h>
#include<alloc.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
int data;
struct node *right,*left,*down,*up;
}node;
node *temp,*head,*end,*uend,*t,*t1,*e,*rightm,*downm,*p1[3],*p2[3];
int i,j,k,l,m[2],n,x,y;
char s[100],move,ch;
void display()
{
     setbkcolor(9);
     setcolor(6);
     cleardevice();
     rectangle(100,100,150,300);
     rectangle(150,100,200,300);
     rectangle(200,100,250,300);
     rectangle(250,100,300,300);
     line(100,250,300,250);
     line(100,200,300,200);
     line(100,150,300,150);

for(temp=head,i=0;i<4;i++,temp=temp->down)
{
 for(t=temp,j=0;j<4;j++,t=t->right)
 {
  if(t->data!=0)
  {
   if(t->data==2)
     setcolor(4);
   if(t->data==4)
     setcolor(1);
   if(t->data==8)
     setcolor(14);
   if(t->data==16)
     setcolor(2);
   if(t->data==32)
     setcolor(13);
   if(t->data==64)
     setcolor(11);
   if(t->data==128)
     setcolor(12);
   if(t->data==256)
     setcolor(8);
   if(t->data==512)
     setcolor(14);
   if(t->data==1024)
     setcolor(4);
   sprintf(s,"%d",t->data);
   outtextxy(115+j*50,125+i*50,s);

  }
 }
}
setcolor(15);
}
void randomnum()
{
m[0]=random(4);
m[1]=random(4);
}
void number_rand()
{
n=random(2);
}
int final_check()
{
int f=0,g=0;
for(temp=head,i=0;i<4;i++,temp=temp->down)
{
 for(t=temp,j=0;j<4;j++,t=t->right)
 {
  if(t->data==0)
   f=1;
  if(t->data==2)
   g=1;
}
}
if(g==1)
return(2);
else
{
 if(f==1)
  return(0);
 else
  return(1);
}
}

void check()
{

if(move=='A')
{
 for(temp=head,i=0;i<4;i++,temp=temp->down)
 {
  for(j=0,t=temp;j<3;j++,t=t->right)
  {
   if((t->data==t->right->data)&& t->data!=0)
   {
    t->data=t->data/2;
    t->right->data=0;
   }
  }
 }
}
if(move=='D')
{
 for(temp=rightm,i=0;i<4;i++,temp=temp->down)
 {
  for(j=0,t=temp;j<3;j++,t=t->left)
  {
   if((t->data==t->left->data)&& t->data!=0)
   {
    t->data=t->data/2;
    t->left->data=0;
   }
  }
 }
}
if(move=='W')
{
 for(temp=head,i=0;i<4;i++,temp=temp->right)
 {
  for(j=0,t=temp;j<3;j++,t=t->down)
  {
   if((t->data==t->down->data)&& t->data!=0)
   {
    t->data=t->data/2;
    t->down->data=0;
   }
  }
 }
}
if(move=='S')
{
 for(temp=downm,i=0;i<4;i++,temp=temp->right)
 {
  for(j=0,t=temp;j<3;j++,t=t->up)
  {
   if((t->data==t->up->data)&& t->data!=0)
   {
    t->data=t->data/2;
    t->up->data=0;
   }
  }
 }
}
}
void newnum()
{

x=0;
while(x==0)
{
randomnum();
 for(i=0,temp=head;i<m[0];i++)
  temp=temp->down;
  for(j=0;j<m[1];j++)
   temp=temp->right;
   if(temp->data==0)
 {
  number_rand();
  if(n==0)
   temp->data=1024;
  else
   temp->data=512;
  x=1;
 }
}
}
void create()
{
for(i=0;i<4;i++)
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
  for(j=0;j<3;j++)
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
temp=head;
for(i=0;i<3;i++)
temp=temp->right;
rightm=temp;
temp=head;
for(i=0;i<3;i++)
temp=temp->down;
downm=temp;
temp=head;
newnum();
newnum();
}
void movem()
{
int cp;

if(move=='W')
{
 for(temp=downm,i=0;i<4;i++,temp=temp->right)
 {
  for(t=temp,j=0;j<4;j++,t=t->up)
  {
    t1=t;
    if(t1->data==0)
     {
       while(t1->down!=NULL)
	{

	  cp=t1->data;
	  t1->data=t1->down->data;
	  t1->down->data=cp;
	  t1=t1->down;
	}
     }
  }
 }
}
if(move=='A')
{
 for(temp=rightm,i=0;i<4;i++,temp=temp->down)
 {
  for(t=temp,j=0;j<4;j++,t=t->left)
  {
   t1=t;
   if(t1->data==0)
    {
     while(t1->right!=NULL)
      {

       cp=t1->data;
       t1->data=t1->right->data;
       t1->right->data=cp;
       t1=t1->right;
      }
    }
  }
 }
}
if(move=='D')
{
 for(temp=head,i=0;i<4;i++,temp=temp->down)
 {
  for(t=temp,j=0;j<4;j++,t=t->right)
  {
    t1=t;
    if(t1->data==0)
     {
       while(t1->left!=NULL)
	{

	  cp=t1->data;
	  t1->data=t1->left->data;
	  t1->left->data=cp;
	  t1=t1->left;
	}
     }
   }
  }
 }

if(move=='S')
{
 for(temp=head,i=0;i<4;i++,temp=temp->right)
 {
  for(t=temp,j=0;j<4;j++,t=t->down)
  {
   t1=t;
   if(t1->data==0)
    {
      while(t1->up!=NULL)
       {

	cp=t1->data;
	t1->data=t1->up->data;
	t1->up->data=cp;
	t1=t1->up;
       }
    }
  }
 }
}
}



void main()
{
/* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "E:\TC\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   cleardevice();
create();
/*temp=head;
temp=temp->down;
for(i=0;i<3;i++)
temp=temp->right;
temp->data=2;
temp=head;
temp=temp->down->down;
temp=temp->right;
temp->data=2;   */
setcolor(5);
cleardevice();
settextstyle(1,0,6);
outtextxy(160,200,"REVERSE");
outtextxy(170,270,"1024");
getch();
cleardevice();
setcolor(15);
settextstyle(0,0,1);
sprintf(s,"RULES=>");
outtextxy(5,5,s);
sprintf(s,"You Have To Create The Number 2");
  outtextxy(5,20,s);
sprintf(s,"Use w,a,s,d Keys to Move");
  outtextxy(5,35,s);
sprintf(s,"Press n At Any Point To Quit...");
  outtextxy(5,45,s);
sprintf(s,"Are You Ready....");
  outtextxy(5,60,s);
getch();
cleardevice();
display();
while(k==0)
{
y=0;
 display();
 sprintf(s,"Enter Your Move");
 outtextxy(5,5,s);

 ch=getch();
 switch(ch)
 {
  case 'w':    move='W';
		break;
  case 's':  move='S';
		break;
  case 'd': move='D';
		break;
  case 'a':  move='A';
		break;
  case 'n':     k=1;
		break;
  default:      y=1;
 }
if(k==1)
{
outtextxy(5,25,"Thanks for playing.....");
break;
}
if(y==1)
{
outtextxy(5,25,"Wrong Move....");
}
else
{
 movem();
// display();
// getch();
 check();
 movem();
 newnum();
 k=final_check();
 display();
 }
if(k==2)
outtextxy(5,25,"congratulation!!!!! You Have WON THE GAME...");
if(k==1)
outtextxy(55,25,"SORRY!!! GAME OVER");

}
getch();
//getch();
//getch();
closegraph();
}
