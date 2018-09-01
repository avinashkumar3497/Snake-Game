//###############################HEADER FILES#####################################################################################
#include<graphics.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>
#include<stdio.h>

int dir;
int kl;
int cont;
int scr;
int score=48,score1=48;
int speed=400;
int tune=20;
int pointx[7800];
int pointy[7800];
int size=5;
int n=0;
int x;
int y;
int xm;
int ym;

//###############################STRUCTURE#####################################################################################
struct game
{
void circl();
void north();
void south();
void west();
void east();
};
//###############################FUNCTION PROTOTYPES#####################################################################################
void help();
void about();
void pause();
void blanker();
void gameover();
void mouse();
void menu();
void newgame();
void mouse1();
void highscore();
void hsc(int);
void init();
void save();
void continu();
//###############################MAIN FUNCTION#####################################################################################
int main(void)
{
clrscr();
randomize();
int gdriver=DETECT;
int gmode,errorno;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
errorno=graphresult();
if(errorno!=0)
{
cout<<"\nCannot Initialize to Graphics Mode";
getch();
exit(1);
}
fstream con("conti.txt",ios::in|ios::out);
if(!con)
con<<0;
con.close();
menu();
}
//###############################FUNCTION DEFINITIONS#####################################################################################
void help()
{
cleardevice();
setcolor(5);
setbkcolor(3);
settextjustify(CENTER_TEXT,TOP_TEXT);
outtextxy(320,10,"HELP");
setcolor(4);
settextjustify(CENTER_TEXT,CENTER_TEXT);
outtextxy(320,100,"UP : i");
outtextxy(320,380,"DOWN : m");
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(10,240,"LEFT : j");
settextjustify(RIGHT_TEXT,CENTER_TEXT);
outtextxy(630,240,"RIGHT : k");
settextjustify(LEFT_TEXT,TOP_TEXT);
outtextxy(400,440,"Pause/resume : q");
setcolor(1);
outtextxy(10,410,"CAUTION : You cannot use continue option more than");
outtextxy(10,440,"once in a single game");
setcolor(5);
setfillstyle(1,5);
for(int ij=150;ij<=490;ij+=10)
{
circle(ij,240,5)  ;
floodfill(ij,240,5);
}
for(ij=150;ij<=330;ij+=10)
{
circle(320,ij,5)  ;
floodfill(320,ij,5);
}
putpixel(317,148,15);
putpixel(317,332,15);
putpixel(323,148,15);
putpixel(323,332,15);
putpixel(148,237,15);
putpixel(148,243,15);
putpixel(492,237,15);
putpixel(492,243,15);
getch();
menu();
}
void about()
{
cleardevice();
setcolor(6);
setbkcolor(3);
outtextxy(100,100,"This game is made by ");
setcolor(4);
outtextxy(380,100,"Avinash Kumar");
setcolor(6);
outtextxy(150,180,"of XII class of DAV Public School");
outtextxy(170,260,",Jasola Vihar who learnt C++ graphics");
outtextxy(170,340,"from the book 'Practical World of C++'");
settextjustify(CENTER_TEXT,TOP_TEXT);
setcolor(8);
outtextxy(320,10,"ABOUT");
getch();
menu();
}
void pause()
{
char res;
for(int df=0;df<1000;df++)
{
res=getch();
if(res=='q')
break;
}
}
void continu()
{
ifstream inte("inte.dat",ios::binary);
inte>>score>>score1>>speed>>tune>>size>>n>>x>>y>>xm>>ym>>dir;
score1--;
ifstream poinx("poinx.dat",ios::binary);
ifstream poiny("poiny.dat",ios::binary);
poinx.seekg(0,ios::beg);
poiny.seekg(0,ios::beg);
for(int k=0;k<n;k++)
{
poinx>>pointx[k];
poiny>>pointy[k];
}
poinx.close();
poiny.close();
inte.close();
newgame();
}
void save()
{
ofstream inte("inte.dat",ios::binary);
inte<<score<<"\n"<<score1<<"\n"<<speed<<"\n"<<tune<<"\n"<<size<<"\n"<<n<<"\n"<<x<<"\n"<<y<<"\n"<<xm<<"\n"<<ym<<"\n"<<dir;
inte.close();
ofstream poinX("poinx.dat",ios::binary|ios::app);
ofstream poinY("poiny.dat",ios::binary|ios::app);
poinX<<pointx[n]<<"\n";
poinY<<pointy[n]<<"\n";
poinX.close();
poinY.close();
}
void init()
{
scr=0;
score=48;score1=48;speed=400;tune=20;size=5;n=0;x=320;y=240;
}
void hsc(int rk)
{
cleardevice();
setbkcolor(3);
outtextxy(10,10,"Congratulations you have rank") ;
if(rk==1)
outtextxy(10,50,"one ");
else
if(rk==2)
outtextxy(10,50,"two ");
else
outtextxy(10,50,"three ");
outtextxy(70,50,"in high score.");
cout<<"\n\n\n\n\n\n\nEnter name : ";
char name[51];
cin>>name;
ifstream hname("hname.txt"),hscore("hscore.txt");
char hna1[51],hna2[51],hna3[51];
char hsco1[5],hsco2[5],hsco3[5];
hname.getline(hna1,51);
hname.getline(hna2,51);
hname.getline(hna3,51);
hscore.getline(hsco1,5);
hscore.getline(hsco2,5);
hscore.getline(hsco3,5);
hname.close();
hscore.close();
ofstream hhscore("hscore.txt"),hhname("hname.txt");
if(rk==1)
{
hhname<<name<<"\n"<<hna1<<"\n"<<hna2;
hhscore<<scr<<"\n"<<hsco1<<"\n"<<hsco2;
}
else
if(rk==2)
{
hhname<<hna1<<"\n"<<name<<"\n"<<hna2;
hhscore<<hsco1<<"\n"<<scr<<"\n"<<hsco2;
}
else
{
hhname<<hna1<<"\n"<<hna2<<"\n"<<name;
hhscore<<hsco1<<"\n"<<hsco2<<"\n"<<scr;
}
}
void highscore()
{
cleardevice();
setbkcolor(3);
settextjustify(CENTER_TEXT,TOP_TEXT);
setcolor(5);
outtextxy(320,10,"HIGH SCORE");
settextjustify(LEFT_TEXT,TOP_TEXT);
setcolor(1);
char hn1[41],hn2[41],hn3[41];
char hsc1[5],hsc2[5],hsc3[5];
ifstream hname("hname.txt"),hscore("hscore.txt");
hname.getline(hn1,41);
hname.getline(hn2,41);
hname.getline(hn3,41);
outtextxy(10,120,"1.");
outtextxy(40,120,hn1);
outtextxy(10,220,"2.");
outtextxy(40,220,hn2);
outtextxy(10,320,"3.");
outtextxy(40,320,hn3);
hscore.getline(hsc1,5);
hscore.getline(hsc2,5);
hscore.getline(hsc3,5);
outtextxy(550,120,hsc1);
outtextxy(550,220,hsc2);
outtextxy(550,320,hsc3);
hname.close();
hscore.close();
getch();
menu();
}
void mouse()
{
int a=getcolor();
setcolor(RED);
setfillstyle(1,RED);
floodfill(200,3,15);
setcolor(14);
char ch1[3]={'0','0','\0'};
ch1[0]=score;
ch1[1]=score1;
outtextxy(100,1,ch1);
setcolor(a);
xm=random(600)+25;
ym=random(440)+25;
if(score1==57)
{
score1=48;
score++;
}
else
score1++;
mouse1();
}
void mouse1()
{
setcolor(6);
ellipse(xm-11,ym-4,-30,220,5,3);
line(xm-14,ym-2,xm-8,ym-2);
setfillstyle(1,6);
floodfill(xm-11,ym-4,6);
putpixel(xm-16,ym-1,6);
putpixel(xm-17,ym,6);
putpixel(xm-14,ym-1,6);
putpixel(xm-13,ym,6);
putpixel(xm-8,ym-1,6);
putpixel(xm-9,ym,6);
putpixel(xm-6,ym-1,6);
putpixel(xm-5,ym,6);
putpixel(xm-6,ym-3,6);
putpixel(xm-5,ym-3,6);
putpixel(xm-4,ym-4,6);
putpixel(xm-3,ym-4,6);
putpixel(xm-2,ym-4,6);
putpixel(xm-1,ym-3,6);
putpixel(xm,ym-3,6);
putpixel(xm-13,ym-6,6);
putpixel(xm-13,ym-7,6);
putpixel(xm-13,ym-8,6);
putpixel(xm-14,ym-9,6);
putpixel(xm-14,ym-8,6);
putpixel(xm-14,ym-7,6);
putpixel(xm-14,ym-6,6);
putpixel(xm-13,ym-7,6);
putpixel(xm-13,ym-6,6);
putpixel(xm-17,ym-3,6);
putpixel(xm-14,ym-6,15);
}
void gameover()
{
ofstream con("conti.txt");
con<<"0";
con.close();
int hs[3];
ifstream h("hscore.txt");
for(int ab=0;ab<3;ab++)
{
h>>hs[ab];
}
h.close();
scr=(score1-48)+(10*(score-48))-1;
setcolor(RED);
outtextxy(50,80,"GAME");
outtextxy(240,220,"OVER");
getch();
nosound();
if(scr>=hs[0])
hsc(1);
else
if(scr>=hs[1])
hsc(2);
else
if(scr>=hs[2])
hsc(3);
menu();
}
void blank(int,int);
void blanker()
{
if(((x-xm)<6)&&((xm-x)<23)&&((y-ym)<5)&&((ym-y)<15))
{
setcolor(15);
rectangle((xm-17),(ym-9),xm,ym);
setfillstyle(1,15);
floodfill(xm-7,ym-5,15);
mouse();
size++;
speed=speed-10;
tune=tune+10;
}
if((x>630)||(x<10)||(y<10)||(y>470))
gameover();
if(n>=(size+2))
{
for(int m=0;m<size;m++)
{
if(((x-pointx[n-(m+2)])<3)&&((x-pointx[n-(m+2)])>-3)&&((y-pointy[n-(m+2)])<3)&&((y-pointy[n-(m+2)])>-3))
{
gameover();
}
}
}
pointx[n]=x;
pointy[n]=y;
save();
if(n>=(size+1))
{
blank(pointx[n-size],pointy[n-size]);
circle((((((pointx[n-size]+pointx[(n-(size-1))])/2)+pointx[n-size])/2)+pointx[n-size])/2,(((((pointy[(n-(size-1))]+pointy[n-size])/2)+pointy[n-size])/2)+pointy[n-size])/2,3);
setfillstyle(1,5);
floodfill((((pointx[n-size]+pointx[(n-(size-1))])/2)+pointx[n-size])/2,(((pointy[(n-(size-1))]+pointy[n-size])/2)+pointy[n-size])/2,5);
blank(pointx[(n-(size+1))],pointy[(n-(size+1))]);
}
n++;
}
void blank(int x,int y)
{
setcolor(15);
rectangle(x-5,y-5,x+5,y+5);
setfillstyle(1,15);
floodfill(x,y,15);
setcolor(5);
}

void menu()
{
init();
cleardevice();
int n1,h1,i1;
setbkcolor(14);
setcolor(5);
setfillstyle(7,15);
floodfill(100,100,5);
for(h1=5;h1<=475;h1=h1+470)
{
for(n1=5;n1<640;n1=n1+10)
{
circle(n1,h1,5);
setfillstyle(1,5);
floodfill(n1,h1,5);
}
}
for(n1=15;n1<=465;n1=n1+10)
{
circle(5,n1,5);
setfillstyle(1,5);
floodfill(5,n1,5);
}
for(n1=15;n1<=165;n1=n1+10)
{
circle(635,n1,5);
setfillstyle(1,5);
floodfill(635,n1,5);
}
putpixel(638,167,15);
putpixel(632,167,15);
for(n1=185;n1<475;n1=n1+10)
{
circle(635,n1,5);
setfillstyle(1,5);
floodfill(635,n1,5);
}
circle(635,176,3);
setfillstyle(1,5);
floodfill(635,177,5);
xm=120;
ym=95;
mouse1();
xm=560;
ym=95;
mouse1();
xm=120;
ym=375;
mouse1();
xm=560;
ym=375;
mouse1();
settextstyle(7,0,6);
//to initialize or check the existance of file
ifstream check("hname.txt");
if(!check)
{
check.close();
fstream hname("hname.txt",ios::in|ios::out),hscore("hscore.txt",ios::in|ios::out);
hscore<<"0\n0\n0";
hname<<"A\nB\nC";
hname.close();
hscore.close();
}
check.close();
//:::::::
setcolor(2);
ifstream con("conti.txt");
con>>cont;
if(cont>1)
cont=0;
if(cont==0)
{
outtextxy(130,100,"1. NEW GAME");
outtextxy(130,140,"2. HIGH SCORE");
outtextxy(130,180,"3. HELP");
outtextxy(130,220,"4. ABOUT");
outtextxy(130,260,"5. EXIT");
setcolor(5);
outtextxy(210,300,"ENTER CHOICE(1/2/3/4/5)");
int b;
for(i1=0;i1<1000;i1++)
{
b=getch();
switch(b)
{
case '1':
newgame();
break;
case '2':highscore();
break;
case '3':help();
break;
case '4':about();
break;
case '5':exit(0);
break;
}}}
else
if(cont==1)
{
outtextxy(130,100,"1. NEW GAME");
outtextxy(130,140,"2. CONTINUE");
outtextxy(130,180,"3. HIGH SCORE");
outtextxy(130,220,"4. HELP");
outtextxy(130,260,"5. ABOUT");
outtextxy(130,300,"6. EXIT");
setcolor(5);
outtextxy(210,340,"ENTER CHOICE(1/2/3/4/5/6)");
int f;
for(i1=0;i1<1000;i1++)
{
f=getch();
switch(f)
{
case '1':
newgame();
break;
case '2':
continu();
break;
case '3':highscore();
break;
case '4':help();
break;
case '5':about();
break;
case '6':exit(0);
break;
}
}
}
}
void newgame()
{
remove("poinx.dat");
remove("poiny.dat");
cleardevice();
setcolor(RED);
rectangle(4,8,636,476);
setfillstyle(1,RED);
floodfill(1,1,RED);
game c;
setbkcolor(15);
mouse();
if(cont)
{
for(kl=n;kl>n-size;kl--)
{
setcolor(5);
circle(pointx[kl],pointy[kl],5);
setfillstyle(1,5);
floodfill(pointx[kl],pointy[kl],5);
}
setcolor(5);
circle(x,y,5);
circle(pointx[n-size],pointy[n-size],3);
setfillstyle(1,5);
floodfill(x,y,5);
floodfill(pointx[n-size],pointy[n-size],5);
if(dir==1)
{
putpixel(x-3,y-2,15);
putpixel(x+3,y-2,15);
}
else
if(dir==2)
{
putpixel(x-3,y+2,15);
putpixel(x+3,y+2,15);
}
else
if(dir==3)
{
putpixel(x-2,y-3,15);
putpixel(x-2,y+3,15);
}
else
if(dir==4)
{
putpixel(x+2,y-3,15);
putpixel(x+2,y+3,15);
}
pointx[n]=x;
pointy[n]=y;
n++;
 }
ofstream con("conti.txt");
cont++;
con<<cont;
con.close();
char ch;
for(int i=0;i<1000;i++)
{
ch=getch();
if((cont==2)&&((ch=='i')||(ch=='j')||(ch=='k')||(ch=='m')))
{
putpixel(x+2,y-3,5);
putpixel(x+2,y+3,5);
putpixel(x-2,y-3,5);
putpixel(x-2,y+3,5);
putpixel(x-3,y+2,5);
putpixel(x+3,y+2,5);
putpixel(x-3,y-2,5);
putpixel(x+3,y-2,5);
}
setcolor(14);
outtextxy(30,1,"Score =");
switch(ch)
{
	case 'i': c.north();
	break;
	case 'm': c.south();
	break;
	case 'j': c.west();
	break;
	case 'k': c.east();
	break;
	}
}
}
void game::circl()
{
setcolor(5);
circle(x,y,5);
setfillstyle(1,5);
floodfill(x,y,5);
}
void game::north()
{
dir=1;
for(int i=0;;i++)
{
sound(tune);
y=y-10;
blanker();
circl();
putpixel(x-3,y-2,15);
putpixel(x+3,y-2,15);
delay(speed);
putpixel(x-3,y-2,5);
putpixel(x+3,y-2,5);
if(kbhit())
{
char ch=getch();
switch(ch)
{
case 'i': north();
break;
case 'm': break;
case 'j': west();
break;
case 'k': east();
break;
case 'q': pause();
break;
}
}
}
}
void game::south()
{
dir=2;
for(int i=0;;i++)
{
sound(tune);
y=y+10;
blanker();
circl();
putpixel(x-3,y+2,15);
putpixel(x+3,y+2,15);
delay(speed);
putpixel(x-3,y+2,5);
putpixel(x+3,y+2,5);
if(kbhit())
{
char ch=getch();
switch(ch)
{
case 'i': break;
case 'm': south();
break;
case 'j': west();
break;
case 'k': east();
break;
case 'q': pause();
break;
}
}
}
}
void game::west()
{
dir=3;
for(int i=0;;i++)
{
sound(tune);
x=x-10;
blanker();
circl();
putpixel(x-2,y-3,15);
putpixel(x-2,y+3,15);
delay(speed);
putpixel(x-2,y-3,5);
putpixel(x-2,y+3,5);
if(kbhit())
{
char ch=getch();
switch(ch)
{
case 'i': north();
break;
case 'm': south();
break;
case 'j': west();
break;
case 'k': break;
case 'q': pause();
break;
}
}
}
}
void game::east()
{
dir=4;
for(int i=0;;i++)
{
sound(tune);
x=x+10;
blanker();
circl();
putpixel(x+2,y-3,15);
putpixel(x+2,y+3,15);
delay(speed);
putpixel(x+2,y-3,5);
putpixel(x+2,y+3,5);
if(kbhit())
{
char ch=getch();
switch(ch)
{
case 'i': north();
break;
case 'm': south();
break;
case 'j': break;
case 'k': east();
break;
case 'q': pause();
break;
}
}
}
}
