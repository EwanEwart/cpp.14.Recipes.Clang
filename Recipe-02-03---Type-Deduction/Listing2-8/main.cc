#include <iostream>
using std::cout ;
using std::endl ;

// #include <string>
using std::string ;

#include <memory> // shared_ptr
using std::make_shared ;
using std::shared_ptr ;
using std::static_pointer_cast ;

#include <typeinfo> // typeid

#include <boost/core/demangle.hpp>

using boost::core::demangle ;
class Greet
{
public:
  virtual int twice(int const & i) = 0 ; // make the class polymorphic

} ;

class Greetings : public Greet
{
protected:
  char const* _whom ;
public:
  Greetings ( char const * whom) : _whom(whom) { cout << _whom << ": Class Greetings was created." << endl ; }
  virtual ~Greetings() { cout << _whom << ": Class Greetings was discarded." << endl ; } // polymorphic class
  int twice(int const & i) { return 2*i ; }
} ;

class SpecialGreetings : public Greetings
{
public:
  SpecialGreetings ( char const * whom) : Greetings(whom) { cout << _whom << ": Class SpecialGreetings was created." << endl ; }
  virtual ~SpecialGreetings () { cout << _whom << ": Class SpecialGreetings was discarded." << endl ; } // polymorphic class
  char const * name () { return Greetings::_whom ; }
} ;

// typedef shared_ptr<Greetings> Ptr ; // the same as below
using Ptr = shared_ptr<Greetings> ;    // the same as above

int main ()
{
  cout << "__cplusplus ... " << __cplusplus << endl ;

  auto variable = 1 ;
  cout << "Type of variable: " << demangle ( typeid ( variable ) .name () ) << endl ;

  {
    auto spg = make_shared<Greetings>("Ewan") ;
    auto spsg = make_shared<SpecialGreetings>("Rachel") ;
    shared_ptr<Greetings> spg2 ( spsg ) ;


    cout << "Type of spg: " << demangle ( typeid ( spg ) .name () ) << endl ;
//    cout << "Type of *spg: " << demangle ( typeid ( *spg ) .name () ) << endl ;
    cout << "Type of Ptr: " << demangle ( typeid ( Ptr ) .name () ) << endl ;
    cout << "Type of spsg: " << demangle ( typeid ( spsg ) .name () ) << endl ;
    cout << "Type of spg2: " << demangle ( typeid ( spg2 ) .name () ) << endl ;
    if ( typeid(*spg) == typeid(*spsg) ) // warning
      cout << "spg == spsp" << endl ;
    else
      cout << "spg != spsp" << endl ;


    cout << "Who is spsg ? ... " << spsg -> name () << endl ;
    cout << "Who is spg2 ? ... " << dynamic_cast<SpecialGreetings*>(spg2.get())  -> name () << endl ; // (direct cast, does not construct a temporary shared_ptr)

    cout << "Who is spg2 static_cast ? ... " << static_cast<SpecialGreetings*>(spg2 .get()) -> name () << endl ; // (direct cast, does not construct a temporary shared_ptr)
    cout << "Who is spg2 static_pointer_cast? ... " << static_pointer_cast<SpecialGreetings>(spg2) -> name () << endl ; // (constructs a temporary shared_ptr, then calls operator->)
    cout << "Who is spg  static_pointer_cast? ... " << static_pointer_cast<SpecialGreetings>(spg) -> name () << endl ; // (constructs a temporary shared_ptr, then calls operator->)
    // cout << "Who is spg2 ? ... " << static_cast<Greetings*>(spg2 .get()) -> name () << endl ; // (direct cast, does not construct a temporary shared_ptr)


    // if(typeid(*spg2)==typeid(Greetings)) // warning
    //   cout << "spg2 == Greetings" << endl ;
    // else
    //   cout << "spg2 != Greetings" << endl ;


    // if(typeid(*spg2)==typeid(SpecialGreetings)) // warning
    //   cout << "spg2 == SpecialGreetings" << endl ;
    // else
    //   cout << "spg2 != SpecialGreetings" << endl ;
  }

  auto fii { new Greetings("Fiona") } ;           // Type of fii: std::initializer_list<Greetings*>
  auto saa { new SpecialGreetings("Samantha") } ; // Type of sas: std::initializer_list<SpecialGreetings*>

  auto fi = new Greetings("Fiona")   ;
  auto sa = new SpecialGreetings("Samantha") ;

  Greetings* sab = dynamic_cast<Greetings*>(sa) ;
  // SpecialGreetings* fip = dynamic_cast<Greetings*>(fi) ;

  Greet* gbp = sa ;
  if(typeid(*gbp) == typeid(SpecialGreetings))
    cout << "typeid(*gbp) == typeid(SpecialGreetings)" << endl ;
  else
    cout << "typeid(*gbp) != typeid(SpecialGreetings)" << endl ;
  if(typeid(*gbp) == typeid(Greetings))
    cout << "typeid(*gbp) == typeid(Greetings)" << endl ;
  else
    cout << "typeid(*gbp) != typeid(Greetings)" << endl ;
  if(typeid(*gbp) == typeid(Greet))
    cout << "typeid(*gbp) == typeid(Greet)" << endl ;
  else
    cout << "typeid(*gbp) != typeid(Greet)" << endl ;


  cout << "Type of fii: " << demangle ( typeid ( fii ) .name () ) << endl ;
  cout << "Type of sas: " << demangle ( typeid ( saa ) .name () ) << endl ;

  cout << "Type of fi: "  << demangle ( typeid ( fi ) .name () ) << endl ;
  cout << "Type of sa: "  << demangle ( typeid ( sa ) .name () ) << endl ;
  cout << "Type of sab: " << demangle ( typeid ( sab ) .name () ) << endl ;

  cout << "Who is sa ? ... " << sa -> name () << endl ;
  cout << "Who is sab ? ... " << dynamic_cast<SpecialGreetings*>(sab) -> name () << endl ;

  #if 200400L < __cplusplus && __cplusplus < 201200L
    cout << "c++11" << endl ;
    // delete pointers of initialiser lists (CentOS)
    for(auto ptr:fii)
      delete ptr ;
    for(auto ptr:saa)
      delete ptr ;
  #else
    cout << "c++14" << endl ;
    delete fii ; // Ubuntu
    delete saa ;
  #endif


  // delete raw pointers
  delete fi ;
  delete sa ;

  return 0 ;
}
