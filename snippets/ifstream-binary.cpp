#include <fstream>

std::ifstream file( filename.c_str(), ifstream::in );
// 或者：std::ifstream file; file.open( filename.c_str(), ifstream::in );

if ( !file ) { exit(-1); }
// 或者：if ( !file.is_open() ) { exit(-1); }
