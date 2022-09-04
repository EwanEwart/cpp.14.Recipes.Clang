#include <iostream>
#include <cstdlib> // system

#include <boost/format.hpp>

using std::cout ;
using std::cerr ;
using std::endl ;
using std::string ;

using boost::format ;
// using boost::basic_format ;

struct PLAY
{
  string cmd   = "ffplay" ;
  string smpte = "-f lavfi -i smptebars" ;
  string red   = "-f lavfi -i color=c=red" ;
  string green = "-f lavfi -i color=c=green" ;
  string blue  = "-f lavfi -i color=c=blue" ;
  string colour = "-f lavfi -i color=c=" ;
} play ;


int branch_sys ( string const & cmd )
{
  int ret = system ( cmd.c_str() ) ;

  return ret ;
}

int main ( int ac, char const * av [])
{

  format cmd_smpte  { "%1% %2%" } ; cmd_smpte  % play.cmd % play.smpte  ;
  format cmd_red    { "%1% %2%" } ; cmd_red    % play.cmd % play.red    ;
  format cmd_green  { "%1% %2%" } ; cmd_green  % play.cmd % play.green  ;
  format cmd_blue   { "%1% %2%" } ; cmd_blue   % play.cmd % play.blue   ;

  format cmd { "%1% -f %2% -i %3% -pix_fmt %4% -f %5% %6%" } ;

  cmd
    % /* 1 */ "ffmpeg"               /* cmd            */
    % /* 2 */ "lavfi"                /* filter         */
    % /* 3 */ "rgbtestsrc"           /* input          */
    % /* 4 */ "yuv420p"              /* pixfmt         */
    % /* 5 */ "sdl"                  /* panel         */
    % /* 6 */ "\"lavfi rgbtestsrc\"" /* panel caption */
  ;

  int rc, no = 0 ;

  do
  {
    if ( ac == 2 )
    {

      format cmd_colour { "%1% %2%%3%" } ;

      cmd_colour % play.cmd % play.colour % av[1] ;

      cout << cmd_colour.str() << endl ;
      rc = branch_sys ( cmd_colour.str () ) ;
      if ( rc ) break ;
      for ( int k = 1 ;    k < ac ;   ++k )
        cout << k << " ... " <<  av [ k ] << endl ;
      cout << endl ;
    }
    else
    {

      // 1. ls
      no = 1 ;
      rc = branch_sys ( "ls -lt") ;
      if ( rc ) break ;

      // 2.
      no = 2 ;
      rc = branch_sys ( cmd_blue.str () ) ;
      if ( rc ) break ;

      // 3.
      no = 3 ;
      // r = branch_sys ( "ffmpeg -f lavfi -i rgbtestsrc -pix_fmt yuv420p -f sdl \"lavfi rgbtestsrc\"" ) ;
      rc = branch_sys ( cmd.str () ) ;
      if ( rc ) break ;

    }

  } while ( false ) ;
  cerr << no << ". main  return ... " << rc << endl ;

  return rc ;
}
