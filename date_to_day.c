#include <stdio.h>
#include <stdlib.h>

int month(int x,int y)
{
        
    if((x==0 && y==2) || (x==0 && y==3) || (x==1 && y==1)) return 3;
    
    if ((x==0 && y==4) || (x==0 && y==7)) return 6;
    
    if ((x==0 && y==1) || (x==1 && y==0)) return 0;
    
    if ((x==0 && y==9) || (x==1 && y==2)) return 5;
    
    if(x==0 && y==5) return 1;    
    
    if(x==0 && y==8) return 2;    
    
    if(x==0 && y==6) return 4;
    
}

int year(int z)
{
    int r=0;
    r=z%400;
    
    if (r>=0 && r<=99) return 6;
    
    if (r>=100 && r<=199) return 4;

    if (r>=200 && r<=299) return 2;

    if (r>=300 && r<=399) return 0;
     
}

int addition(int p,int q,int r,int s,int t)
{
    int ans=0;
    ans=(p+q+r+s+t);    
    ans=ans%7;
    return ans;
}

int leapyear(int a)
{
   if (a%4==0 && a%400==0 && a%100==0 ) return 1;
   
   else if (a%4==0 && a%100!=0) return 1;
   
   else return 0;

}

void days(int d)
{
    
    if (d==-1) printf("DAY=Saturday");
    if (d==0) printf("DAY=Sunday");
    if (d==1) printf("DAY=Monday");
    if (d==2) printf("DAY=Tuesday");
    if (d==3) printf("DAY=Wednesday");
    if (d==4) printf("DAY=Thursday");
    if (d==5) printf("DAY=Friday");
    if (d==6) printf("DAY=Saturday");

}

int main()
{
    int s[15],count=0,add_y,add_yl,add_d,len,m,y,temp=0,d;
    printf("enter date in this formate:dd-mm-yyyy(for example:25-01-2001)\n");
    for( int i=0 ; i < 10 ; i++)
    {
       scanf("%1d",&s[i]);
       count++;
    }
    
    if (count==10)
    {
      add_y=s[6]*1000+s[7]*100+s[8]*10+s[9];
      add_yl=s[8]*10+s[9];
      add_d=s[0]*10+s[1];
      len=add_yl/4;   
      m=month(s[3],s[4]);
      y=year(add_y);    
      d=addition(add_d,add_yl,len,m,y);      
      if (leapyear(add_y))
       {
          temp=1;
       }
      
      if ((temp==1 && s[3]==0 && s[4]==1) || (temp==1 && s[3]==0 && s[4]==2) )
       {
          d=d-1;
       }
      
      days(d);
             
   }
   else
   {
       printf("enter date in valid formate");
   }
   
    return 0;
}