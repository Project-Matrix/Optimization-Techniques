#include<stdio.h>
double myFun(double x);
int main()
{
	double a, b, y, x, xm, x1, x2, fx1, fx2, fxm, L, t=0.01;
	printf("Enter a:");
	scanf("%lf",&a);
	printf("Enter b:");
	scanf("%lf",&b);
	xm = (a + b)/2;
	
	jump:
	L = b-a;
	x1 = a + (L/4);
	x2 = b - (L/4);
	printf("\n\na = %.2lf",a);
	printf("\nb = %.2lf",b);
	printf("\nx1 = %.2lf",x1);
	printf("\nx2 = %.2lf",x2);
	printf("\nxm = %.2lf",xm);
	printf("\nL = %.2lf",L);
	fx1 = myFun(x1);
	printf("\nf(x1) = %.2lf",fx1);
	fx2 = myFun(x2);
	printf("\nf(x2) = %.2lf",fx2);
	fxm = myFun(xm);
	printf("\nf(xm) = %.2lf",fxm);
	if(L > t)
	{
		if (fx1 < fxm)
		{
			a = a;
			b = xm;
			xm = x1;
			goto jump;
		}
		else if (fx2 < fxm)
		{
			b = b;
			a = xm;
			xm = x2;
			goto jump;
		}
		else if (fx1 > fxm && fx2 > fxm)
		{
			a = x1;
			b = x2;
			xm = (a+b)/2;
			goto jump;
		}
		else 
		{
			goto end;
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