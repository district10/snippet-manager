std::map<int, Complicated> m;
int anInt = 4;
double aDouble = 5.0;
std::string aString = "C++";

// cross your finger so that the optimizer is really good
m.insert(std::make_pair(4, Complicated(anInt, aDouble, aString)));

// should be easier for the optimizer
m.emplace(4, anInt, aDouble, aString);
