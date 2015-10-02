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

myType get_elem ( array_t *arr, int n )
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( ( arr-> length) != 0xDEADBEAF );
  assert ( ( n>=0 )&&( n < ( arr-> length) ) ); 
  return ( arr -> array [n] );
}

int get_len( array_t *arr )
{
  assert ( arr != NULL );
  return ( arr -> length );
}

void set_elem ( array_t *arr, int n, myType val)
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( ( arr-> length) != 0xDEADBEAF );
  assert ( ( n>=0 )&&( n < ( arr-> length) ) ); 
  arr -> array [n] = val;
}

void array_randval ( array_t *arr )
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( (get_len ( arr ) ) != 0xDEADBEAF );
  int i = 0,
      val = 0;
  srand ( time ( NULL ) );
  for ( i = 0; i < ( get_len ( arr ) ); i++ )
  {
    val = rand () % 200 - 100;
    set_elem ( arr, i, val );
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
    if ( (get_len ( arr ) ) == 0xDEADBEAF )
    {
      printf ("Array_t object was destructed.\n");
      return -2;
    }
    else
    {
      printf ( "Number of elements: %d \n", ( get_len ( arr ) ) );
      int i = 0;
      for ( i = 0; i < ( get_len ( arr ) ); i++ )
      {
        printf( "%d ", ( get_elem ( arr, i ) ) );
      }
      printf ( "\n" );
      return 1;
    }
  }
  return 0;
}

void gnome_sort ( array_t *arr )
{
  assert ( ( arr != NULL )&&( ( arr -> array ) != NULL ) );
  assert ( (get_len ( arr ) ) != 0xDEADBEAF );
  int i = 1;
  myType tmp = 0; 
  while ( i < ( get_len ( arr ) ) ) 
  {
    if ( i==0 ) 
    {
      i = 1;
    }
    if ( ( get_elem ( arr, ( i-1 ) ) ) <= ( get_elem ( arr, i ) ) )
    {
      i++;
    } 
    else 
    {
      tmp = get_elem ( arr, i ) ;
      set_elem ( arr, i, get_elem ( arr, ( i-1 ) ) );
      set_elem ( arr, ( i-1 ), tmp );
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
  array_randval ( &arr );
  array_dump ( &arr );
  gnome_sort ( &arr );
  array_dump ( &arr );
  array_destruct ( &arr );
  array_dump ( &arr ); 
  return 0;
}
