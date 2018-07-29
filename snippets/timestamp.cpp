#include <ctime>

std::string getTime()
{
    time_t rawtime;
    time(&rawtime);
    char str[64];
    strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S", localtime(&rawtime));
    return str;
}
