void ply_header(stringstream &os, int size)
{
    os << "ply" << endl;
    os << "format ascii 1.0" << endl;
    os << "element vertex " << size << endl;
    os << "property float x" << endl;
    os << "property float y" << endl;
    os << "property float z" << endl;
    os << "property uint8 red" << endl;
    os << "property uint8 green" << endl;
    os << "property uint8 blue" << endl;
    os << "end_header" << endl;
}

void writeStr(std::string path, const std::string &str)
{
    ofstream file;
    file.open(path);
    file << str;
    file.close();
}

void writePly(std::string path, const std::string &lines, int size)
{
    stringstream header;
    ply_header(header, size);
    ofstream plyFile;
    plyFile.open(path);
    plyFile << header.str();
    plyFile << lines;
    plyFile.close();
}

void writePly(std::string path, const std::vector<std::string> &lines)
{
    stringstream ss_buf;
    for (auto &line : lines) {
        ss_buf << line << endl;
    }
    writePly(path, ss_buf.str(), lines.size());
}
