#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<alloc.h>
#include<dos.h>
#include<graphics.h>
 union REGS in,out;
/*      0- green
	1- red
	2- blue
	3- purple
	4- yellow
	10- green special
	11- red special
	12- bule special
	13- purple special
	14- yellow special

*/


typedef struct node{
int data;
struct node *down,*right,*left,*up;
}node;
node *t,*e,*u,*t1,*e1,*head,*temp,*uend,*head1,*head2,*head3,*uend1;
int ax,ay,bx,by,z,r,bt,bt1,xp,yp,xp1,yp1,mo,m=6,n=6;
char s[50];
void display()
{
int i,j;
cleardevice();
setcolor(5);
for(i=0,e=head1;i<n;i++,e=e->down)
{
 for(j=0,e1=e;j<m;j++,e1=e1->right)
   {
    rectangle(50+j*50,50+i*50,100+j*50,100+i*50);
//    if(e1->data>0)
  //  floodfill(125+j*50,125+i*50,5);
   }
}
if(head2!=NULL)
{
for(i=0,e=head1;i<n;i++,e=e->down)
{
 for(j=0,e1=e;j<m;j++,e1=e1->right)
   rectangle(100+m*50+j*50,50+i*50,150+j*50,100+i*50);
}
}
for(i=0,t=head;i<n;i++,t=t->down)
{
 for(j=0,t1=t;j<m;j++,t1=t1->right)
 {
   setlinestyle(0,0,1);
  // printf("%d",t1->data);
    if(t1->data==0)
     {
      setcolor(5);        //green
      setfillstyle(SOLID_FILL,2);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
     }
    if(t1->data==1)
     {
      setcolor(5);        //red
      setfillstyle(SOLID_FILL,4);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
     }
    if(t1->data==2)
     {
      setcolor(5);        //blue
      setfillstyle(SOLID_FILL,1);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
     }
    if(t1->data==3)
     {
      setcolor(5);        //purple
      setfillstyle(SOLID_FILL,5);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
     }
    if(t1->data==4)
     {
      setcolor(5);        //yellow
      setfillstyle(SOLID_FILL,14);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
     }
    if(t1->data==10)
     {
      setcolor(5);        //green striped
      setfillstyle(SOLID_FILL,2);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
      setlinestyle(1,1,2);
      line(55+j*50,75+i*50,95+j*50,75+i*50);
      line(75+j*50,55+i*50,75+j*50,95+i*50);
     }
    if(t1->data==11)
     {
      setcolor(5);        //red stripped
      setfillstyle(SOLID_FILL,4);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
      line(55+j*50,75+i*50,95+j*50,75+i*50);
      line(75+j*50,55+i*50,75+j*50,95+i*50);
     }
    if(t1->data==12)
     {
      setcolor(5);        //blue stripped
      setfillstyle(SOLID_FILL,1);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
      line(55+j*50,75+i*50,95+j*50,75+i*50);
      line(75+j*50,55+i*50,75+j*50,95+i*50);
     }
    if(t1->data==13)
     {
      setcolor(5);        //purple stripped
      setfillstyle(SOLID_FILL,5);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
      line(55+j*50,75+i*50,95+j*50,75+i*50);
      line(75+j*50,55+i*50,75+j*50,95+i*50);
     }
    if(t1->data==14)
     {
      setcolor(5);        //yellow stripped
      setfillstyle(SOLID_FILL,14);
      circle(75+j*50,75+i*50,15);
      floodfill(75+j*50,75+i*50,5);
      line(55+j*50,75+i*50,95+j*50,75+i*50);
      line(75+j*50,55+i*50,75+j*50,95+i*50);
     }


  }
}
if(head2!=NULL)
{
 for(i=0,t=head2;i<n;i++,t=t->down)
 {
  for(j=0,t1=t;j<m;j++,t1=t1->right)
  {
   setlinestyle(0,0,1);
  // printf("%d",t1->data);
    if(t1->data==0)
     {
      setcolor(5);        //green
      setfillstyle(SOLID_FILL,2);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
     }
    if(t1->data==1)
     {
      setcolor(5);        //red
      setfillstyle(SOLID_FILL,4);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
     }
    if(t1->data==2)
     {
      setcolor(5);        //blue
      setfillstyle(SOLID_FILL,1);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
     }
    if(t1->data==3)
     {
      setcolor(5);        //purple
      setfillstyle(SOLID_FILL,5);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
     }
    if(t1->data==4)
     {
      setcolor(5);        //yellow
      setfillstyle(SOLID_FILL,14);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
     }
    if(t1->data==10)
     {
      setcolor(5);        //green striped
      setfillstyle(SOLID_FILL,2);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
      setlinestyle(1,1,2);
      line(55+50*m+j*50,75+i*50,95+50*m+j*50,75+i*50);
      line(75+50*m+j*50,55+i*50,75+50*m+j*50,95+i*50);
     }
    if(t1->data==11)
     {
      setcolor(5);        //red stripped
      setfillstyle(SOLID_FILL,4);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
      line(55+50*m+j*50,75+i*50,95+50*m+j*50,75+i*50);
      line(75+50*m+j*50,55+i*50,75+50*m+j*50,95+i*50);
     }
    if(t1->data==12)
     {
      setcolor(5);        //blue stripped
      setfillstyle(SOLID_FILL,1);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
      line(55+50*m+j*50,75+i*50,95+50*m+j*50,75+i*50);
      line(75+50*m+j*50,55+i*50,75+50*m+j*50,95+i*50);
     }
    if(t1->data==13)
     {
      setcolor(5);        //purple stripped
      setfillstyle(SOLID_FILL,5);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
      line(55+50*m+j*50,75+i*50,95+50*m+j*50,75+i*50);
      line(75+50*m+j*50,55+i*50,75+50*m+j*50,95+i*50);
     }
    if(t1->data==14)
     {
      setcolor(5);        //yellow stripped
      setfillstyle(SOLID_FILL,14);
      circle(75+50*m+j*50,75+i*50,15);
      floodfill(75+50*m+j*50,75+i*50,5);
      line(55+50*m+j*50,75+i*50,95+50*m+j*50,75+i*50);
      line(75+50*m+j*50,55+i*50,75+50*m+j*50,95+i*50);
     }


  }
}
}

setfillstyle(SOLID_FILL,15);
setcolor(15);

setfillstyle(SOLID_FILL,15);
setcolor(15);
for(i=0,e=head1;i<n;i++,e=e->down)
{
 for(j=0,e1=e;j<m;j++,e1=e1->right)
   {
    //rectangle(100+j*50,100+i*50,150+j*50,150+i*50);
    if(e1->data>0)
    floodfill(55+j*50,55+i*50,5);
   }
}
if(head3!=NULL)
{
for(i=0,e=head3;i<n;i++,e=e->down)
{
 for(j=0,e1=e;j<m;j++,e1=e1->right)
   {
    //rectangle(100+j*50,100+i*50,150+j*50,150+i*50);
    if(e1->data>0)
    floodfill(55+m*50+j*50,55+i*50,5);
   }
}
setcolor(7);
setlinestyle(1,1,2);
line(50+m*50,0,50+m*50,800);
setlinestyle(0,0,1);
}
}

  int ran()
  {
     int i;


   i=random(5);
   return(i);
  }
node* create()
{
int i,j;
node *head=NULL;
for(i=0;i<n;i++)
{
 temp=(node*)malloc(sizeof(node));
 temp->right=temp->left=temp->down=temp->up=NULL;
 temp->data=ran();
 if(i==0)
  head=temp;
 else
 {
  uend->down=temp;
  temp->up=uend;
 }
 e=temp;
  for(j=0;j<m;j++)
  {
   t=(node*)malloc(sizeof(node));
   t->right=t->left=t->down=t->up=NULL;
   t->data=ran();
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
return(head);
}
void movem()
{
int i,j;
mo=0;
for(i=0,t=head;t!=NULL;i++,t=t->down)
{

 for(j=0,t1=t;j<m;j++,t1=t1->right)
 {
  if(t1->data==8)
   {

    e=t1;
    mo=1;
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
for(i=0,t=head;i<n;i++,t=t->down)
{
for(j=0,t1=t;j<m;j++,t1=t1->right)
{
 if(t1->data==8)
 t1->data=ran();
}
}
}
void check()
{
	int i,j,a=0;
	for(i=0,t=head,u=head1;i<n;i++,t=t->down,u=u->down)
	{
		//if(a==1)
		//break;
		for(j=0,t1=t,e1=u;j<m;j++,t1=t1->right,e1=e1->right)
		{
			if(j<=m-3)
			{

				if(j<=m-4)
				{
					if((t1->data%10==t1->right->data%10)&&(t1->data%10==t1->right->right->data%10)&&(t1->data%10==t1->right->right->right->data%10)&&(t1->data!=8))
					{
						a=1;
						if((t1->data/10==1||t1->right->data/10==1)||(t1->right->right->data/10==1)||(t1->right->right->right->data/10==1))
						{
							for(e=t,e1=u;e!=NULL;e=e->right,e1=e1->right)
							{
								e->data=8;
								e1->data=e1->data-1;
							}
						}
						else
						{
						t1->data=10+t1->data;
						t1->right->data=t1->right->right->data=t1->right->right->right->data=8;
						e1->data--;
						e1->right->data--;
						e1->right->right->data--;
						e1->right->right->right->data--;
						}
						break;
					}

					if((t1->data%10==t1->right->data%10)&&(t1->data%10==t1->right->right->data%10)&&(t1->data!=8))
					{
						a=1;

						if((t1->data/10==1)||(t1->right->data/10==1)||(t1->right->right->data/10==1))
						{
							for(e=t,e1=u;e!=NULL;e=e->right,e1=e1->right)
							{
								e->data=8;
								e1->data=e1->data-1;
							}
						}
						t1->data=t1->right->data=t1->right->right->data=8;
						e1->data--;
						e1->right->data--;
						e1->right->right->data--;

						break;
					}
				}
				else
				{
					if((t1->data%10==t1->right->data%10)&&(t1->data%10==t1->right->right->data%10)&&(t1->data!=8))
					{
						a=1;

						if((t1->data/10==1)||(t1->right->data/10==1)||(t1->right->right->data/10==1))
						{
							for(e=t,e1=u;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=t1->right->data=t1->right->right->data=8;
						e1->data--;
						e1->right->data--;
						e1->right->right->data--;
						break;
					}
				}
		    }
		    if(i<=n-3)
		    {

				if(i<=n-4)
				{
					if((t1->data%10==t1->down->data%10)&&(t1->data%10==t1->down->down->data%10)&&(t1->data%10==t1->down->down->down->data%10)&&(t1->data!=8))
					{
						a=1;
						if(t1->data/10==1)
						{
							for(e=t,e1=u;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->data/10==1)
						{
							for(e=t->down,e1=u->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->data/10==1)
						{
							for(e=t->down->down,e1=u->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->down->data/10==1)
						{
							for(e=t->down->down->down,e1=u->down->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=10+t1->data;
						t1->down->data=t1->down->down->data=t1->down->down->down->data=8;
						e1->data--;
						e1->down->data--;
						e1->down->down->data--;
						e1->down->down->down->data--;
						break;
					}
					if((t1->data%10==t1->down->data%10)&&(t1->data%10==t1->down->down->data%10)&&(t1->data!=8))
					{
						a=1;
						if(t1->data/10==1)
						{
							for(e=t,e1=u;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->data/10==1)
						{
							for(e=t->down,e1=u->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->data/10==1)
						{
							for(e=t->down->down,e1=u->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=t1->down->data=t1->down->down->data=8;
						e1->data--;
						e1->down->data--;
						e1->down->down->data--;
					}

				}
				else
				{
					if((t1->data%10==t1->down->data%10)&&(t1->data%10==t1->down->down->data%10)&&(t1->data!=8))
					{
						a=1;
						if(t1->data/10==1)
						{
							for(e=t,e1=u;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->data/10==1)
						{
							for(e=t->down,e1=u->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->data/10==1)
						{
							for(e=t->down->down,e1=u->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=t1->down->data=t1->down->down->data=8;
						e1->data--;
						e1->down->data--;
						e1->down->down->data--;
					}
				}
			}
		}
	}
	if(a==1)
	{
	display();
	delay(500);
	check();
	}
    if(head2!=NULL)
    {
	for(i=0,uend=head,t=head2,u=head3,uend1=head1;i<n;i++,t=t->down,u=u->down,uend=uend->down,uend1=uend1->down)
	{
		//if(a==1)
		//break;
		for(j=0,t1=t,e1=u;j<m;j++,t1=t1->right,e1=e1->right)
		{
			if(j<=m-3)
			{

				if(j<=m-4)
				{
					if((t1->data%10==t1->right->data%10)&&(t1->data%10==t1->right->right->data%10)&&(t1->data%10==t1->right->right->right->data%10)&&(t1->data!=8))
					{
						a=1;
						if((t1->data/10==1||t1->right->data/10==1)||(t1->right->right->data/10==1)||(t1->right->right->right->data/10==1))
						{
							for(e=uend,e1=uend1;e!=NULL;e=e->right,e1=e1->right)
							{
								e->data=8;
								e1->data=e1->data-1;
							}
						}
						else
						{
						t1->data=10+t1->data;
						t1->right->data=t1->right->right->data=t1->right->right->right->data=8;
						e1->data--;
						e1->right->data--;
						e1->right->right->data--;
						e1->right->right->right->data--;
						}
						break;
					}

					if((t1->data%10==t1->right->data%10)&&(t1->data%10==t1->right->right->data%10)&&(t1->data!=8))
					{
						a=1;

						if((t1->data/10==1)||(t1->right->data/10==1)||(t1->right->right->data/10==1))
						{
							for(e=uend,e1=uend1;e!=NULL;e=e->right,e1=e1->right)
							{
								e->data=8;
								e1->data=e1->data-1;
							}
						}
						t1->data=t1->right->data=t1->right->right->data=8;
						e1->data--;
						e1->right->data--;
						e1->right->right->data--;

						break;
					}
				}
				else
				{
					if((t1->data%10==t1->right->data%10)&&(t1->data%10==t1->right->right->data%10)&&(t1->data!=8))
					{
						a=1;

						if((t1->data/10==1)||(t1->right->data/10==1)||(t1->right->right->data/10==1))
						{
							for(e=uend,e1=uend1;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=t1->right->data=t1->right->right->data=8;
						e1->data--;
						e1->right->data--;
						e1->right->right->data--;
						break;
					}
				}
		    }
		    if(i<=n-3)
		    {

				if(i<=n-4)
				{
					if((t1->data%10==t1->down->data%10)&&(t1->data%10==t1->down->down->data%10)&&(t1->data%10==t1->down->down->down->data%10)&&(t1->data!=8))
					{
						a=1;
						if(t1->data/10==1)
						{
							for(e=uend,e1=uend1;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->data/10==1)
						{
							for(e=t->down,e1=u->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->data/10==1)
						{
							for(e=t->down->down,e1=u->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->down->data/10==1)
						{
							for(e=t->down->down->down,e1=u->down->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=10+t1->data;
						t1->down->data=t1->down->down->data=t1->down->down->down->data=8;
						e1->data--;
						e1->down->data--;
						e1->down->down->data--;
						e1->down->down->down->data--;
						break;
					}
					if((t1->data%10==t1->down->data%10)&&(t1->data%10==t1->down->down->data%10)&&(t1->data!=8))
					{
						a=1;
						if(t1->data/10==1)
						{
							for(e=uend,e1=uend1;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->data/10==1)
						{
							for(e=uend->down,e1=uend1->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->data/10==1)
						{
							for(e=uend->down->down,e1=uend1->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=t1->down->data=t1->down->down->data=8;
						e1->data--;
						e1->down->data--;
						e1->down->down->data--;
					}

				}
				else
				{
					if((t1->data%10==t1->down->data%10)&&(t1->data%10==t1->down->down->data%10)&&(t1->data!=8))
					{
						a=1;
						if(t1->data/10==1)
						{
							for(e=uend,e1=uend1;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->data/10==1)
						{
							for(e=uend->down,e1=uend1->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						if(t1->down->down->data/10==1)
						{
							for(e=uend->down->down,e1=uend1->down->down;e!=NULL;e=e->right,e1=e1->right)
							{
								e1->data=e1->data-1;
								e->data=8;
							}
						}
						t1->data=t1->down->data=t1->down->down->data=8;
						e1->data--;
						e1->down->data--;
						e1->down->down->data--;
					}
				}
			}
		}
	}
	if(a==1)
	{
	  display();
	  delay(500);
	  check();
	}

}

}
void level1()
{
int i,j;
n=8;
m=10;
head=create();
head1=create();
for(i=0,t=head1;i<n;i++,t=t->down)
{
 for(j=0,t1=t;j<m;j++,t1=t1->right)
   t1->data=1;
}
}
void level2()
{
int i,j;
n=8;
m=4;
head=create();
head1=create();
head2=create();
head3=create();
for(i=0,t=head;t->down!=NULL;i++)
t=t->down;
t1=head2;
for(i=0;i<m;i++)
{
t->down=t1;
t1->up=t;
t=t->right;
t1=t1->right;
}
for(i=0,t=head1;i<n;i++,t=t->down)
{
 for(j=0,t1=t;j<m;j++,t1=t1->right)
   t1->data=1;
}
for(i=0,t=head3;i<n;i++,t=t->down)
{
 for(j=0,t1=t;j<m;j++,t1=t1->right)
   t1->data=1;
}
for(i=0,t=head,e=head1;i<m;i++,t=t->right)
e=e->right;
for(i=0,t1=head2,e1=head3;i<n;i++)
{
t->right=t1;
e->right=e1;
t=t->down;
e=e->down;
t1=t1->down;
e1=e1->down;
}
}


      int callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);
	      return 1;
       }
       void mouseposi()
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      bt=out.x.bx;
	      xp=out.x.cx;
	      yp=out.x.dx;
	}
       void mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);

       }
int checkb()
{
int i,j;
for(i=0,t=head1;i<n;i++,t=t->down)
{
 for(j=0,t1=t;j<m;j++,t1=t1->right)
 {
   if(t1->data!=0)
   return(0);
 }
}
if(head3!=NULL)
{
for(i=0,t=head3;i<n;i++,t=t->down)
{
 for(j=0,t1=t;j<m;j++,t1=t1->right)
 {
   if(t1->data!=0)
   return(0);
 }
}
}
return(1);
}
void getcd()
{
ay=(xp-50)/50;
ax=(yp-50)/50;
bx=(yp1-50)/50;
by=(xp1-50)/50;
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

void main()
{

int i,j,gd=DETECT,gm=0,mov=10;
char ch;
randomize();

initgraph(&gd,&gm,"");
callmouse();
setlinestyle(1,1,3);
setcolor(5);
line(250,100,250,350);
line(100,175,400,25);
line(400,25,50,425);
line(250,200,500,450);
line(50,425,350,350);
settextstyle(4,0,4);
outtextxy(175,420,"PRESENTS");
getch();
cleardevice();
settextstyle(7,0,8);
outtextxy(250,100,"CANDY");
outtextxy(250,200,"CRUSH");
getch();
cleardevice();
outtextxy(200,200,"LEVEL 1");
getch();
setcolor(15);
setlinestyle(0,0,1);
 settextstyle(1,0,1);
level1();
check();
movem();
while(mo!=0)
{
check();
movem();
}

display();
mov=20;
gm=checkb();
while(mov!=0&&gm==0)
{
z=0;
while(z==0)
{
z=0;
bt=0;
outtextxy(50,5,"Enter Your Move");
sprintf(s,"Moves=> %d",mov);
outtextxy(100,25,s);
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
//sprintf(s,"%d, %d, %d",bt1,xp1,yp1);
//outtextxy(5,25,s);
getcd();
z=checkcd();
if(z==0)
outtextxy(5,15,"Wrong Input...Try Again");
}
sprintf(s,"%d  %d",ax,bx);
outtextxy(0,1,s);
if(ay<m)
{
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
}
else
{
for(i=0,t=head2;i<ax;i++)
 t=t->down;
for(j=0;j<ay-m;j++)
 t=t->right;
for(i=0,e=head2;i<bx;i++)
 e=e->down;
for(j=0;j<by-m;j++)
 e=e->right;
i=e->data;
e->data=t->data;
t->data=i;
}


display();
check();
movem();
while(mo!=0)
{
check();
movem();
}
display();
ch=getch();
if(ch=='n')
break;
mov--;
gm=checkb();
}
cleardevice();
if(ch=='n')
{
outtextxy(25,25,"Thanks  For  Playing");
exit(0);
}
if(mov==0&&gm==0)
outtextxy(5,25,"GAME  OVER!!!!!");
else
{
outtextxy(5,25,"YOU  WON");
outtextxy(5,40,"Do You Want to Play Next Level y/n");
ch=getch();
if(ch=='n')
{
outtextxy(5,60,"Thanks For Playing....");
getch();
exit(0);
}
else
{
cleardevice();
settextstyle(7,0,8);
outtextxy(200,200,"LEVEL 2");
getch();
setcolor(15);
setlinestyle(0,0,1);
 settextstyle(1,0,1);

level2();
check();
movem();
while(mo!=0)
{
check();
movem();
}

display();
mov=20;
gm=checkb();
while(mov!=0&&gm==0)
{
z=0;
while(z==0)
{
z=0;
bt=0;
outtextxy(50,5,"Enter Your Move");
sprintf(s,"Moves=> %d",mov);
outtextxy(100,25,s);
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
//sprintf(s,"%d, %d, %d",bt1,xp1,yp1);
//outtextxy(5,25,s);
getcd();
z=checkcd();
if(z==0)
outtextxy(5,15,"Wrong Input...Try Again");
}
sprintf(s,"%d  %d",ax,bx);
outtextxy(0,1,s);
if(ay<m)
{
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
}
else
{
for(i=0,t=head2;i<ax;i++)
 t=t->down;
for(j=0;j<ay-m;j++)
 t=t->right;
for(i=0,e=head2;i<bx;i++)
 e=e->down;
for(j=0;j<by-m;j++)
 e=e->right;
i=e->data;
e->data=t->data;
t->data=i;
}


display();
check();
movem();
while(mo!=0)
{
check();
movem();
}
display();
ch=getch();
if(ch=='n')
break;
mov--;
gm=checkb();
}
cleardevice();
if(ch=='n')
{
outtextxy(25,25,"Thanks  For  Playing");
exit(0);
}
if(mov==0&&gm==0)
outtextxy(5,25,"GAME  OVER!!!!!");
else
outtextxy(5,25,"YOU  WON");
}
}
getch();
closegraph();
}