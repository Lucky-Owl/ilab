#include "stack.h"

void stack_construct ( stack_t * s )
{
  if ( stack_OK ( s ) == 0 )
  {
    s -> top = 0;
  }
}

void stack_destruct ( stack_t * s )
{
  if ( stack_OK ( s ) == 0 )
  { 
    s -> top = 0xDEADBEAF;
  }
}

int stack_OK ( stack_t * s )
{
  if ( ( s == NULL ) || ( s -> top == 0xDEADBEAF ) )
  {
    printf ( "Not OK \n" );
    return -1;
  }
    else
    {
      /*printf ( "OK \n" ); */ 
      return 0;
    }
}

void stack_dump ( stack_t s )
{
  if ( s.top == 0 )
  {
    printf ( "Empty stack \n" );
  }
    else
    {
      if ( s.top == 0xDEADBEAF )
      {
        printf ( "Stack does not exist \n" );
      }
        else
        {
          printf ( "Top : %d\n", s.top );
          for ( int i = 0; i < s.top; i ++ )
          {
            printf ( "%d\n", s.elements [ i ] );
          }
        }
      }
}

void stack_push ( stack_t * s, int x )
{
  if ( stack_OK ( s ) == 0 )
  { 
    if ( s -> top < ( SIZE ) )
    {
      s -> elements [ s -> top ] = x;
      s -> top ++;
    }
      else
      {
        printf ( "Stack overflow \n");
      }
  }
}

int stack_pop ( stack_t * s )
{
  if ( stack_OK ( s ) == 0 )
  {
    s -> top --;
    return s -> elements [ s -> top ];
  }
    else
    {
      return -1;
    }   
}

