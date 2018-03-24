template<typename T>
bool fpScanf(FILE *fp, const char *format, T *value) {
    return fscanf(fp, format, value) != 1;
}
