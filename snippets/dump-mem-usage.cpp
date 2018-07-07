void dump_mem_usage()
{
    FILE* f = fopen("/proc/self/statm","rt");
    if (!f) return;
    char str[300];
    size_t n = fread(str, 1, 200, f);
    str[n] = 0;
    printf("MEM: %s\n", str);
    fclose(f);
}
