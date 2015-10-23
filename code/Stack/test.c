#include "stack.h"

int main ( )
{
  int a;
  stack_t MyStack;
  stack_construct ( &MyStack );
  stack_dump ( MyStack );
  stack_push ( &MyStack, 8 );
  stack_push ( &MyStack, 109 );
  stack_push ( &MyStack, -9 );
  stack_dump ( MyStack );
  printf ( "Popped number : %d\n", stack_pop ( &MyStack ) );
  stack_dump ( MyStack );
  a = stack_pop ( &MyStack );
  for ( int i = MyStack.top; i < SIZE+1;i++ )
  {
    stack_push ( &MyStack, 5 );
  }
  stack_dump ( MyStack );
  stack_destruct ( &MyStack );
  a = 0;
  printf ( "%d\n", a );
  stack_dump ( MyStack );
  return 0;
}
