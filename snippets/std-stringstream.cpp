std::string input = "41 3.14 false hello world";
std::istringstream stream(input);
int n;
double f;
bool b;

stream >> n >> f >> std::boolalpha >> b;
std::cout << "n = " << n << '\n'
          << "f = " << f << '\n'
          << "b = " << std::boolalpha << b << '\n';

// extract the rest using the streambuf overload
stream >> std::cout.rdbuf();

std::ostringstream out("1 2");
out << 3;
std::cout << "after writing the int '3' to output stream \"1 2\""
          << ", str() = \"" << out.str() << "\"\n";

string s("Somewhere down the road");
istringstream iss(s);
string sub;
do {
    iss >> sub;
} while (iss);
