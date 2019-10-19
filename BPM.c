#include<stdio.h>
#include<math.h>
double myFun(double x);
int main()
{
	double xw,a,b,fa,fb,fxw,D,y ;
	int k,o,z;
	float x[100],fx[100];
	k = 0;
	printf("Enter x[0]:");
	scanf("%lf",&xw);
	printf("Enter D:");
	scanf("%lf",&D);
	
	a = xw + D;
	b = xw - D;

	fxw = myFun(xw);
	printf("\nf(x0) = %.2lf",fxw);
	fa = myFun(a);
	printf("\nf(x0 + D) = %.2lf",fa);
	fb= myFun(b);
	printf("\nf(x0 - D) = %.2lf",fb);
	printf("\nx[%d] = %.2lf",k,xw);
	x[0] = xw;
	fx[k] = fxw;
	o = k+1;
	
	if (fb <= fxw && fxw <= fa)
	{
		
		D = -D;
		goto jump1;
		
	}
	else if (fb >= fxw && fxw >= fa)
	{
		goto jump1;
	}
		
	else
	{
		goto end;
	}
		
		jump1:
		x[o] = (x[k] + (pow(2,k) * D));
		printf("\n\nx[%d] = %.3f",o,x[o]);
		fx[o] = myFun(x[o]);
		printf("\nfx[%d] = %.3f",o,fx[o]);
		
	if (fx[o] < fxw)
	{
		
	
		if (fx[o] < fx[k])
		{
			k = k + 1;
			o = o + 1;
			
			goto jump1;
		}
		else
		{
		printf("\nBounded range: (x(%d),x(%d))",k-1,k+1);
		printf("\nk = %d",k);
		}
	}
	else
	{
		goto end;
	}
	
	end:
	return 0;
}
	double myFun(double x)         // function definition   
{
    double y;
    y = ((x*x)+(54/x));
    return y;                  // return statement
}