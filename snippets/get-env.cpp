std::string getEnv(const char *key)
{
    // read environment variable
    static map<string, string> cache;
    if (cache.count(key)) {
        return cache[key];
    }
    const char *val = std::getenv(key);
    cache[key] = val ? val : "";
    return cache[key];
}
