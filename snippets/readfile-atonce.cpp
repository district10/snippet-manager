// read whole file
std::stringstream buffer;
buffer << std::ifstream(json_path).rdbuf();
std::string err;
json11::Json obj = json11::Json::parse(buffer.str(), err);
