//{===================================================================
//! @file array_gnsort.c
//! @date 2015-09-30 22:22
//! @author Korostyleva Anastasiya <koros-anastasiya@yandex.ru>
//! @version 2.00
//!
//! Allows to create and sort an array of integer.
//!
//! @par Program reads one number - length of array.
//! Returns chaotic array, and then sorted one.
//!
//}===================================================================

#include "array.h"

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
