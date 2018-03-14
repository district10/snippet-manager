 std::string s("hello");
// std::transform( s.begin(), s.end(), s.begin(), ::toupper );
std::transform( s.begin(), s.end(), s.begin(),
                [](unsigned char c) { return std::toupper(c); } );

// 就是在一个 struct 里实现 operator()
struct ToUpper {
    unsigned char operator()( unsigned char c ) {
        return 'a' <= c && c <= 'z' ?  c-'a'+'A' : c;
    }
};
// ToUpper tu; tu(); // tu() --> ToUpper::operator();
std::transform(s.begin(), s.end(), s.begin(), ToUpper());   // 然后传入一个实例
