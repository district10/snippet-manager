template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vs)
{
    os << "[";
    for (const auto &v : vs) {
        os << " " << v << " ";
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::vector<T>> &c)
{
    out << "[";
    for (const auto &x : c) {
        out << "\t" << x << "\n";
    }
    out << "]";
    return out;
}
