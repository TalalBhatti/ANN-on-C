
#include<stdio.h>
#include<conio.h>
void main()
{
float input[4][2]=
	{{0,0},
	{0,1},
	{1,0},
	{1,1}}; //inputs of AND gate
float output[4]={{0},
	{0},
	{0},     //desired output
	{1}};
float b=-0.2; //bias
float weight[2],weight_delta=0,weight_update=0;//weights for error correction
float n=0.01; //learning rate
float sum=0;//sum before hard limiter
float error[4],t=0;
float cost=1; //cost of the func
int i=0,j=0,op,k;
clrscr();

for(i=0;i<4;i++) //increment in row
	{
	cost=1;

	while(cost>0)
	{
	sum=0;
		for(j=0;j<2;j++)//increment in colomn
		{
		sum = ((input [i][j]*weight[j])+b);
		if(sum>=0)
		{op=1;}
		else
		{op=0;}
		error[i]=output[i]-op;
		cost=(error[i]*error[i]);
		t+=cost;
		} //j
	//printf("\nbf output is %d",op);
	//printf("\nbf error is %f",cost);
	//printf("\nbf cost is %f \n",t/4 );
	//cost agae

		if(t!=0)
		{
		for(j=0;j<2;j++)
			{weight_delta=n*error[i]*input[3][j];
			//printf("%f",weight_delta
			weight[j]+=weight_delta;
			printf("\n new weights= %f cost=%f",weight[j],cost);
			}// j new
		}
	}// k
       printf("\n AF %d",op);
       } //i

system("pause");
}