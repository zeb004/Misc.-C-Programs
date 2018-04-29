#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<monetary.h>
#define ytdthresh 110100
#define FICARATE .071


CalcFICA(float gross,float FICA,float ytd){

if(ytd>=ytdthresh) {
return FICA==0;
return gross;
}
else if(ytd+gross<=ytdthresh) {
return FICA=((ytdthresh-ytd)*FICARATE);
return gross,ytd;
}
else
return FICA=(FICARATE*gross);
return gross,ytd;
}

