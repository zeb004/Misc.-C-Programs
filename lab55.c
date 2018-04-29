//Zachary Beardmore
//02/12/16
//Program to read payroll info from file and calculate gross,FICA, and net pay
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<monetary.h>

float NewLine(float pagecount,float linecount,float pgross,float pnet,float pytd,float tgross,float tnet,float tytd,float gross,float net,float FICA,float pFICA,float tFICA);
float CalcGross(float payrate,double hours,float gross);
float CalcFICA(float gross,float FICA,float ytd);


int main() {
FILE *inFile;        
	char fileInName[20];    

	FILE *outFile;
	char fileOutName[20];

	printf("Enter the name of the input file: ");
	scanf("%s", fileInName);

	inFile = fopen( fileInName, "r" );
	if( inFile == NULL ) {
		printf("File does not exist");
		exit( 1 );
	}

	printf("Enter the name of the output file: ");
	scanf("%s", fileOutName);
	char response;
	if((outFile = fopen(fileOutName, "r" )) != NULL )
	{
		printf("\nA file by the name %s exists.\n", fileOutName);
		printf("Do you wish to overwrite (Y or N): ");
		scanf("%*c %c", &response);
	}

		if( (response == 'n') || (response == 'N') )
		{ 	fclose(outFile);  
			printf("\nProgram aborted");
			exit(1);
		}

	outFile = fopen(fileOutName, "w" );     
	if( outFile == NULL){
		printf("Error, terminating!");
  	  	exit( 1 );
	}
	fprintf(outFile, "\t\t\t\t\tACME Sports Inc.\n\t\t\t\t\tWe are the best, you use the best!");
	float pagecount=0;
	float linecount=0;
	float ytd=0;
	float payrate;
	double hours;
	float gross;
	char given[25];
	char surname[25];
	float  empnum=0;
	char department[10];
	float FICA=0;
	//float net=gross-FICA;
	float numrec=0;
	float pgross,pnet,pytd,tgross,tnet,tytd,pFICA,tFICA=0;
	

	while((fscanf(inFile, "%f%s%s%s%f%f%lf",&empnum,given,surname,department,&ytd,&payrate,&hours))!=EOF){
	gross=CalcGross(payrate,hours,gross);
	
	printf("%f\n",gross);
    FICA=CalcFICA(gross,FICA,ytd);
	printf("%f\n",FICA);
	float net=gross-FICA;
	numrec++;
	if(linecount==0||linecount==5){
	pagecount++;
	
	
	NewLine(pagecount,linecount,pgross,pnet,pytd,tgross,tnet,tytd,gross,net,FICA, pFICA,tFICA);
	fprintf(outFile,"\n\n\t\t\tACME Tools\t\t\tPage%.0f\n\n\n",pagecount);
	fprintf(outFile,"Name\t\tGross\t\tFICA\t\tNet\n");
	fprintf(outFile,"%s\t$%.2f\t$%.2f\t$%.2f\n",given,gross,FICA,net);
	pgross=+gross;
	pFICA=+FICA;
	pnet=+net;
	tgross+=gross;
	tnet+=net;
	tFICA+=FICA;
	linecount++;
}
	
	
	fprintf(outFile, "Page totals:$%.2f\t$%.2f\t$%.2f",pgross,pFICA,pnet);	
	linecount=0;
	
}
	fprintf(outFile,"\t\t\tReport Summary\n\n\t\t\t\tRecords Processed:%.2f\nTotal Gross:\t$%.2f\n\tTotal FICA:\t$%.2f\n\tTotal Net:\t$%.2f", numrec,tgross,tFICA,tnet);
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}



