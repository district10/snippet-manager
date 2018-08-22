istreambuf_iterator<char> EOF;
string str(istreambuf_iterator<char>(fin), EOF);
string err;
Json json = Json::parse(str, err);
