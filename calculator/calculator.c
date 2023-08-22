#include<pic.h>
#include<math.h>
#define E RC0
#define RS RC1
#define LCD PORTD
#define _XTAL_FREQ 4000000
void command()
{
RS=0;
E=1;

E=0;

}
void data()
{
RS=1;
E=1;

E=0;

}
int i,res,l;
char r1,r2,r3,r4;
int k=0;
int a=0;
int b=0;
char op='+';



void main()
{

ANSEL=0X00;
ANSELH=0X00;
TRISB=0XF0;
TRISC=0X00;
TRISD=0X00;

unsigned int arr1[];
unsigned char arr2[]="CALCULATOR ON";
unsigned int arr3[];
unsigned int arr4[]={0X80,0X81,0X82,0X83,0X84,0X85,0X86,0X87,0X88,0X89,0X8A,0X8B,0X8C,0X8D,0X8E,0X8F};
unsigned int arr5[]={0XC0,0XC1,0XC2,0XC3,0XC4,0XC5,0XC6,0XC7,0XC8,0XC9,0XCA,0XCB,0XCC,0XCD,0XCE,0XCF};
LCD=0X38;
command();
__delay_ms(1);

LCD=0X01;
command();
__delay_ms(1);

LCD=0X0C;
command();
__delay_ms(1);

for(i=0;i<13;i++)
{
LCD=arr4[i];
command();

LCD=arr2[i];
data();
}
__delay_ms(200);
LCD=0X01;
command();
__delay_ms(1);


while(1)
{

int j=0;
while(j<16)
{
RB0=1;
RB1=RB2=RB3=0;
 if(RB4==1)
{
LCD=arr4[j];
command();

LCD=arr1[j]='7';
data();
arr3[k]='7';
j++;
k++;
while(RB4==1);

}

if(RB5==1)
{
 
 LCD=arr4[j];
command();

LCD=arr1[j]='8';
data();
arr3[k]='8';
j++;
k++;
while(RB5==1);

}
if(RB6==1)
{
 
    
 
    LCD=arr4[j];
command();

LCD=arr1[j]='9';
data();
arr3[k]='9';
j++;
k++;
while(RB6==1);

}
if(RB7==1)
{
 
  
    
   LCD=arr4[j];
command();

LCD=op='/';
data();
l=0;
for(i=j-1;i>=0;i--)
{
a+=(arr1[i]-48)*pow(10,l);
l++;
arr3[i]='\0';
}

j++;
k=0;
while(RB7==1);

}

RB0=0;
RB1=1;
RB2=RB3=0;
if(RB4==1)
{
LCD=arr4[j];
command();

LCD=arr1[j]='4';
data();
arr3[k]='4';
j++;
k++;
while(RB4==1);

}

if(RB5==1)
{
 
 LCD=arr4[j];
command();

LCD=arr1[j]='5';
data();
arr3[k]='5';
j++;
k++;
while(RB5==1);

}
if(RB6==1)
{
 
    
 
    LCD=arr4[j];
command();

LCD=arr1[j]='6';
data();
arr3[k]='6';
j++;
k++;
while(RB6==1);

}
if(RB7==1)
{
 
  
    
   LCD=arr4[j];
command();

LCD=op='*';
data();
l=0;
for(i=j-1;i>=0;i--)
{

a+=(arr1[i]-48)*pow(10,l);
l++;
arr3[i]='\0';
}

j++;
k=0;
while(RB7==1);

}


RB0=0;
RB1=0;
RB2=1;
RB3=0;
if(RB4==1)
{
LCD=arr4[j];
command();

LCD=arr1[j]='1';
data();
arr3[k]='1';
j++;
k++;
while(RB4==1);

}

if(RB5==1)
{
 
 LCD=arr4[j];
command();

LCD=arr1[j]='2';
data();
arr3[k]='2';
j++;
k++;
while(RB5==1);

}
if(RB6==1)
{
 
    
 
    LCD=arr4[j];
command();

LCD=arr1[j]='3';
data();
arr3[k]='3';

j++;
k++;
while(RB6==1);

}
if(RB7==1)
{
 
  
    
   LCD=arr4[j];
command();

LCD=op='-';
data();
l=0;
for(i=j-1;i>=0;i--)
{
a+=(arr1[i]-48)*pow(10,l);
l++;
arr3[i]='\0';
}

j++;
k=0;
while(RB7==1);

}


RB0=0;
RB1=0;
RB2=0;
RB3=1;
if(RB4==1)
{
for(i=j-1;i>=0;i--)
{
arr1[i]='\0';
}
for(i=k-1;i>=0;i--)
{
arr3[i]='\0';
}
j=0;
k=0;
a=0;
b=0;
LCD=0X01;
command();
__delay_ms(1);
while(RB4==1);

}

if(RB5==1)
{
 
 LCD=arr4[j];
command();

LCD=arr1[j]='0';
data();
arr3[k]='0';

j++;
k++;
while(RB5==1);

}
if(RB6==1)
{
 l=0;
    for(i=k-1;i>=0;i--)
{
b+=(arr3[i]-48)*pow(10,l);
l++;
}

 switch(op)
{
case '+':
res=a+b;
break;
case '-':
res=a-b;
break;
case '*':
res=a*b;
break;
case '/':
res=a/b;
break;
}

r1=(res%10)+48;
res=res/10;
r2=(res%10)+48;
res=res/10;
r3=(res%10)+48;
res=res/10;
r4=(res%10)+48;

LCD=0XC0;
command();
LCD=r4;
data();

LCD=0XC1;
command();
LCD=r3;
data();

LCD=0XC2;
command();
LCD=r2;
data();

LCD=0XC3;
command();
LCD=r1;
data();

j++;
while(RB6==1);

}
if(RB7==1)
{
 
  
    
   LCD=arr4[j];
command();

LCD=op='+';
data();

l=0;
for(i=j-1;i>=0;i--)
{
a=a+((arr1[i]-48)*pow(10,l));
l++;
arr3[i]='\0';
}

j++;
k=0;
while(RB7==1);

}
}



}
}

