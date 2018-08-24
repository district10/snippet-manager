// Serialize.
void dump(std::string &out) const;
std::string dump() const {
    std::string out;
    dump(out);
    return out;
}
