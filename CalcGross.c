#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<monetary.h>
#define ytdthresh 110100
#define FICARATE .071



CalcGross(float payrate,double hours,float gross){

double overtime=40.000000;
if(hours>overtime){
gross=((overtime*payrate)+((hours-overtime)*(payrate*1.5)));
return gross;
printf("%f\n",gross);
}
else 
gross=(hours*payrate);
printf("%f\n",gross);
return gross;
}





