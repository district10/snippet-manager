// dropbox/json11
for (auto &obj : obj["key"].array_items()) {
    obj["key"].int_value();
    // int_value()
    // number_value()
    // string_value()
    // bool_value()
}

for (auto &pair : obj["key"].object_items()) {
    string &key = pair.first;
    json11::Json &obj = pair.second;
}
