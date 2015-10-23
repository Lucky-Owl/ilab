#ifndef H_STACK
#define H_STACK

#define SIZE 5
/*----Headers----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*---------------------------------------------------------------------------*/

/*----Types------------------------------------------------------------------*/
typedef struct stack
{
  int top;
  int elements [ SIZE ] ;
} stack_t; 
/*---------------------------------------------------------------------------*/

/*----Methods----------------------------------------------------------------*/
void stack_construct ( stack_t * s );
void stack_destruct ( stack_t * s );
int stack_OK ( stack_t * s );
void stack_dump ( stack_t s );
void stack_push ( stack_t * s, int x );
int stack_pop ( stack_t * s );
/*---------------------------------------------------------------------------*/

#endif
