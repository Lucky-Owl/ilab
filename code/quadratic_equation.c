#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linear ( double b, double c, double *x ) 
{  
  if ( b==0 )
  {
    if ( c==0 ) return -3;
    else return -4; 
  }
  else
  {
    *x = -c/b;
    return -1;
  }
  return -2;
}

int quadratic ( double a, double b, double c, double *x, double *x2 ) 
{ 
  if (a==0) return ( linear ( b, c, x ) );
  else
  {
    double dis = b*b-4*a*c;
    if ( dis<0 ) 
    {
      return 0;
    }
    else
      if ( dis==0 )
      {
        *x = -b / ( 2*a ); 
        return 1;
      }
      else
        if ( dis>0 )
        {
          *x = ( -b - sqrt ( dis ) ) / ( 2*a );
          *x2 = ( -b + sqrt ( dis ) ) / ( 2*a );
          return 2;
        }
        return -2;
  }
}

int main ( )
{
  double a = 0,
         b = 0,
         c = 0,
         x = 0,
         x2 = 0;
  int res = 0,
      sw = 3;
  printf ( "Input 3 coefficients: \n" );  
  res = scanf( "%lg %lg %lg", &a, &b, &c );
  if ( res==3 )
  { 
    sw = quadratic ( a, b, c, &x, &x2 );
  } 
    else
    {
      sw = 3;
    }
  switch ( sw ) 
  {
    case -4: printf ( "Linear equation, no roots.\n" );
             break;
    case -3: printf ( "Infinity of linear roots.\n" ); 
             break;
    case -2: printf( "Program suddenly died. Error.\n" );
             break;
    case -1: printf ( "Linear equation. One root: x = %.3f\n", x );
             break;
    case 0: printf ( "Discriminant is negative. No real roots.\n" );
            break;
    case 1: printf ( "Double root: x = %.3f\n", x );
            break;
    case 2: printf ( "Roots: x1 = %.3f, x2 = %.3f\n", x, x2 );
            break;
    case 3: printf ( "Wrong input.\n" );
            break;
    default: printf( "=(\n" );
  }
  return 0;
}

