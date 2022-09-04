
#include "../../demangle.h"

#include <exception>

using std::type_info ;
using std::bad_exception ;

struct Empty { } ;

template <typename T, int N>
struct Bar { } ;


// test - bed  no. 2
//
int main ()
{

  // type-id
  Bar < Empty, 17 > u ;
  type_info const  & ti = typeid ( u ) ;

  string demangled {} ;

  // 1. clang : fine.
  //    Doesn't work for gcc !!! Why ???
  //
  int s = cxx::demangle2 ( demangled, ti .name () ) ;

  cout
    << ti.name ()
    << "  --->  " << demangled
    << " : status " << s
    << endl ;

  // 2. fine for both
  cout
    << ti.name ()
    << "  --->  " << cxx::demangle ( ti .name () )
    << endl ;

  return 0 ;
}



// test - bed  no. 2
//
// int main ()
// {
//   char*  __output_buffer ;
//   size_t __length     ;
//   int    __status   = 0 ;

//   // exception classes not in <stdexcept>,
//   // thrown by the implementation instead of the user
//   bad_exception  e ;

//   // char* __output_buffer =
//   __output_buffer = (char*) malloc (256) ;
//   abi::__cxa_demangle   // char*
//   (
//       e.what ()        // char const * __mangled_name
//     ,  __output_buffer // char *       __output_buffer
//     , &__length        // size_t*       __length
//     , &__status        // int*         __status
//   ) ;

//   cout
//     << e.what ()
//     << "\t: " << __output_buffer
//     << "\t: " << __length
//     << "\t: " << __status
//     << endl ;

//   demangled_status (__status) ;

//   if ( __output_buffer != NULL )
//   {
//     free ( __output_buffer ) ;
//     cout << "Freed C-allocated memory." << endl ;
//   }

//   // typeid
//   Bar < Empty, 17 > u ;
//   type_info const  & ti = typeid ( u ) ;

//   // char* realname2 =
//   __output_buffer = (char*) malloc ( 256 ) ;
//   abi::__cxa_demangle
//   (
//       ti.name () // char const * __mangled_name
//     , __output_buffer          // char *       __output_buffer
//     , &__length          // size_t*      __length
//     , &__status    // int*         __status
//   ) ;

//   cout
//     << ti.name ()
//     << "\t: " << __output_buffer
//     << "\t: " << __length
//     << "\t: " << __status
//     << endl ;

//   demangled_status (__status) ;

//   if ( __output_buffer != NULL )
//   {
//     free ( __output_buffer ) ;
//     cout << "Freed C-allocated memory." << endl ;
//   }

//   cout << endl ;

//   return 0 ;
// }
