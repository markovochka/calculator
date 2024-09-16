#include "calc.h"
#include "stdlib.h"
struct Vector
{
	int** chr; //dynamic storage
	int size;
};
const double Euler = 2.71828183;
const double Pi = 3.1415926;  
const double Ln_10 = 2.302585092994046;
//calc 
void overf(struct Vector* x)//extend the size of x-chr, 
{			    //lighter than setting preset value
	int i, old_s;
	old_s = x->size;
	x->size += 8;
	int** temp_chr = malloc(x->size * sizeof(int*)); //extend the array, using malloc
	for(i = 0; i < old_s; i++) //copy previous vallues to temporary storage
	{
		temp_chr[i] = x->chr[i];
	}
	for(i = old_s; i < x->size; i++) //initialize new elements from old size to extended one
	{
		temp_chr[i] = malloc(sizeof(int));
		if(temp_chr[i] != 0)
		{
			*temp_chr[i] = 85; //stand for U-Undefined
		}
	}
	
	free(x->chr); //delete delete old array
	x->chr = temp_chr;
}
void free_V(struct Vector* x) //use in the end of programm, to make sure everything will go smoothly
{
	int i;
	for(i = 0; i < x->size; i++)
	{
		free(x->chr[i]);
	}
	free(x->chr);
}
void char_set(int* c, int* i, struct Vector* x) //put every char input into a separate 
{
						//cell of Vector x.array;
	if (*i < x->size)
	{
		if(*x->chr[*i] == 85)  
		{
			*x->chr[*i] = *c;
		}
	}
	else 
		{
			overf(x); //extend array if needed
			if(*i < x->size) 
			{
				*x->chr[*i] = *c;
			}
		}
	++(*i); //helps in future
}
double char_converter(struct Vector* x, int start, int end) 
{
    int if_dec = 0; // Flag for decimal point
    int i, index;
    double answ = 0.0;
    double n = 1.0;
    index = start;
    
    for (i = end - start; i >= 0 && *x->chr[index] != '\0'; i--) 
    {
        if (*x->chr[index] == 46) // '.' character
        {
            if_dec = 1;
            ++index;
            continue;
        }
        if (if_dec == 0) // Before the decimal point
        {
            answ = answ * 10 + ((int)(*x->chr[index]) - '0');
        }
        else // After the decimal point
        {
            n *= 10;
            answ += ((int)(*x->chr[index]) - '0') / n;
        }
        ++index;
    }
    return answ;
}
//math op
double power(double num, double pwr)
{
	if(pwr == 0) //obligatory check, quite useful in the future
	{
		return 1;
	}
	if(pwr != (int)pwr) //e^(ln(num)*pwr), work for almost any numbers and any float powers, should be optimized soon
	{
		double x, a, n;
		int i;
		x = n_log(num);
		x *= pwr;
		n = 1.0;
		a = 1.0 + x;
		for( i = 2; i < 2000; i++)
		{
			n *= i;
			a += power(x, i)/n;
		}
		return a;
	}
	int i;
	double a;
	a = num;
	for(i = 1; i < (int)pwr; i++)
	{
		a *= num;
	}
	return a;
}
double n_log(double num) //natural log or ln
{
	int i;
	double x_0, answ;
	x_0 = (num-1.0)/(num+1.0);
	answ = x_0;
	for(i = 3; i <= 20011; i += 2) //algorithm to find realy close vallue, using some fancy calculator's formula, may be optimized
	{
		answ += (power(x_0, i)/i);
	}
	return 2.0*answ;
}
double a_log(double num) //log 10 or lg
{
	return n_log(num)/Ln_10;  //am i really need you buddy????
}
double root_n(double num, int root) //i should make it work for decimal root values
{
	int i;
	double x_0, x_1;
	x_0 = 1;
	for(i = 0; i <= 10000; i++)
	{
		x_1 = x_0 - (power(x_0, root) - num)/root/power(x_0, root-1); //use of Newtons method
		x_0 = x_1;
	}
	return x_1;
}
int factorial(int num) //num! = num*num-1*num-2... > 0
{
	if(num == 1)
	{
		return num;
	}
	return num*factorial(num-1);
}
double plus(double x, double y)
{
	return x + y;
}
double minus(double x, double y)
{
	
	return x - y;
}
double sum(double x, double y)
{
	return x * y;
}
double div_(double x, double y)
{
	return x / y;
}
