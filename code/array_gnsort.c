//{===================================================================
//! @file array_gnsort.c
//! @date 2015-09-30 22:22
//! @author Korostyleva Anastasiya <koros-anastasiya@yandex.ru>
//! @version 1.00
//!
//! Allows to create and sort an array of integer.
//!
//! @par Program reads one number - length of array.
//! Returns chaotic array, and then sorted one.
//!
//}===================================================================

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

typedef int myType;

typedef struct array_t
{
  int length;
  myType *array;
} array_t;

void array_construct ( array_t *arr, int l )
{ 
  assert ( l > 0 );
  arr -> length = l;
  arr -> array = ( myType* ) calloc ( l, sizeof ( myType ) );
}

void array_destruct ( array_t *arr )
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  arr -> length = 0xDEADBEAF;
  free ( arr -> array );
}

myType array_getElement ( array_t *arr, int n )
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( ( arr-> length) != 0xDEADBEAF );
  assert ( ( n>=0 )&&( n < ( arr-> length) ) ); 
  return ( arr -> array [n] );
}

int array_getLength ( array_t *arr )
{
  assert ( arr != NULL );
  return ( arr -> length );
}

void array_setElement ( array_t *arr, int n, myType val)
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( ( arr-> length) != 0xDEADBEAF );
  assert ( ( n>=0 )&&( n < ( arr-> length) ) ); 
  arr -> array [n] = val;
}

void array_randomValues ( array_t *arr )
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( (array_getLength ( arr ) ) != 0xDEADBEAF );
  int i = 0,
      val = 0;
  srand ( time ( NULL ) );
  for ( i = 0; i < ( array_getLength ( arr ) ); i++ )
  {
    val = rand () % 200 - 100;
    array_setElement ( arr, i, val );
  }
}

int array_dump ( array_t *arr )
{
  if ( ( arr == NULL )||( (arr -> array) == NULL ) )
  {
    printf ("Array_t object is not created yet.\n");
    return -1;
  }
  else
  {
    if ( ( array_getLength ( arr ) ) == 0xDEADBEAF )
    {
      printf ("Array_t object was destructed.\n");
      return -2;
    }
    else
    {
      printf ( "Number of elements: %d \n", ( array_getLength ( arr ) ) );
      int i = 0;
      for ( i = 0; i < ( array_getLength ( arr ) ); i++ )
      {
        printf( "%d ", ( array_getElement ( arr, i ) ) );
      }
      printf ( "\n" );
    }
  }
  return 0;
}

void array_gnomeSort ( array_t *arr )
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( ( array_getLength ( arr ) ) != 0xDEADBEAF );
  int i = 1;
  myType tmp = 0; 
  while ( i < ( array_getLength ( arr ) ) ) 
  {
    if ( i==0 ) 
    {
      i = 1;
    }
    if ( ( array_getElement ( arr, ( i-1 ) ) ) <= ( array_getElement ( arr, i ) ) )
    {
      i++;
    } 
    else 
    {
      tmp = array_getElement ( arr, i ) ;
      array_setElement ( arr, i, array_getElement ( arr, ( i-1 ) ) );
      array_setElement ( arr, ( i-1 ), tmp );
      i--;
    }
  }
}

int main()
{ 
  int l = 0;
  printf ( "Input array length:\n" );
  scanf ( "%d", &l ); 
  array_t arr;
  array_dump ( &arr );
  array_construct ( &arr, l );
  array_dump ( &arr );
  array_randomValues ( &arr );
  array_dump ( &arr );
  array_gnomeSort ( &arr );
  array_dump ( &arr );
  array_destruct ( &arr );
  array_dump ( &arr ); 
  return 0;
}
