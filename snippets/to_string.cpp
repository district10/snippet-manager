// Converts a numeric value to std::string.
std::string to_string( int value );                (1) (since C++11)
std::string to_string( long value );               (2) (since C++11)
std::string to_string( long long value );          (3) (since C++11)
std::string to_string( unsigned value );           (4) (since C++11)
std::string to_string( unsigned long value );      (5) (since C++11)
std::string to_string( unsigned long long value ); (6) (since C++11)
std::string to_string( float value );              (7) (since C++11)
std::string to_string( double value );             (8) (since C++11)
std::string to_string( long double value );        (9) (since C++11)
// format: 0.000000

// fallback (before c++11)
#include <sstream>
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
int i = 42;
std::cout << SSTR( "i is: " << i );
std::string s = SSTR( i );
puts( SSTR( i ).c_str() );
