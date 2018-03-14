std::map<int,char> example = {{1,'a'},{2,'b'}};

auto search = example.find(2);      // 关键是 map.find(key) != map.end()
if(search != example.end()) {
    std::cout << "Found (" << search->first << ", " << search->second << ')\n';
} else {
    std::cout << "Not found\n";
}
