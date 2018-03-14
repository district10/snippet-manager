struct AreBothSpaces {
  bool operator()(char x, char y) const {
    return x == ' ' && y == ' ';
    // std::isspace(x) && std::isspace(y) && x == y;
  }
};

void removeContinuousSpaces(std::string& str) {
    std::string::iterator last = std::unique(str.begin(), str.end(), AreBothSpaces());
    str.erase(last, str.end());
}
