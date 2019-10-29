//mytrianglewav.c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265

double trianglewav(t,p)
double t,p;
{
  //三角波函数，p：0到1占空比
  //trianglewav(t,p)的周期为2pi
  //返回值在-1到+1间
  double y;
  //将t归化于0到2pi区间
  if(t>=0)
    t=(t/(2*PI)-(int)(t/(2*PI)))*2*PI;
  else
    t=2*PI+(t/(2*PI)-(int)(t/(2*PI)))*2*PI;
  //检查占空比参数范围是否合法
  if(p<0 | p>1){printf("fun trianglewav error: p<0 or p>1\n");exit(0);}
  p=p*2*PI;
  //当p为0或2*pi时的近似处理
  p=(p-2*PI==0)?2*PI-1e-10:p;
  p=(p==0)?1e-10:p;
  
  if(t<p)
    {
      y=2*t/p-1;//计算上升沿
    }
  else
    {
      y=-2*t/(2*PI-p)+(2*PI+p)/(2*PI-p);//下降沿
    }
  return y;
}

main(int argc, char *argv[])
{
  double y,t,p=0.5,f=1;
  int i;
  if(argc==3)
  {
	f=atof(argv[1]);
	p=atof(argv[2]);
  }
  for(i=0; i<2*8000; i++)
    {
      t=-1+1.0/8000*i;
      y=trianglewav(2*PI*f*t,p);
      printf("%f\t%f\n",t,y);
    }
}
