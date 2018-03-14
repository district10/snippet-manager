struct S {
    int x, y;
    S(int x = 0, int y = 0) : x(x), y(y) { }
};

struct Comp {
    int r, m;
    Comp(int r = 0, int m = 3) : r(r), m(m) {}
    bool operator()( const S &s) {
        return s.x%m == r;
    }
};

vector<S> s(20, S());
for( int i = 0; i < s.size(); ++i ) {
    s[i].x = s[i].y = i;
}
s.erase( remove_if( s.begin(), s.end(), Comp() ), s.end() );
s.erase( remove_if( s.begin(), s.end(), Comp(1) ), s.end() );
s.erase( remove_if( s.begin(), s.end(), Comp(0, 2) ), s.end() );
