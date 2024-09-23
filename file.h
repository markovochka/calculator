#ifndef CALC_H
#define CALC_H
const double Euler;
const double Pi;  
const double Ln_10;
struct Vector;

void overf(struct Vector* x);
void free_V(struct Vector* x);
double char_converter(struct Vector* x, int start, int end);
void char_set(int* c, int* i, Vector* x);
void straight_line(struct Vector* x);
{
    int size;
    size = x->size-1;
   for(int i = 0; i <= size; i++)
   {
       if(*x->chr[i] == 32)
       {
           for(int j = i; j <= size-1; j++)
           {
               *x->chr[j] = *x->chr[j+1];
               *x->chr[j+1] = 32;
               
           }
           if(*x->chr[size] == 32)
           {
               *x->chr[size] = 85;
           }
       }
   }
//math operators
double power(double num, double pwr);
double n_log(double num);
double a_log(double num);
double root_n(double num, int root);
int factorial(int num);
double plus(double x, double y);
double minus(double x, double y);
double sum(double x, double y);
double div_(double x, double y);

#endif
