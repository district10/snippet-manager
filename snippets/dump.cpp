// Serialize.
void dump(std::string &out) const;
std::string dump() const {
    std::string out;
    dump(out);
    return out;
}

static void dump(double value, string &out) {
    if (std::isfinite(value)) {
        char buf[32];
        snprintf(buf, sizeof buf, "%.17g", value);
        out += buf;
    } else {
        out += "null";
    }
}
