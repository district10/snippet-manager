// header file
#include <chrono>

class Clocker
{
  public:
    static Clocker &instance();
    std::map<std::string, std::vector<std::chrono::steady_clock::time_point>> clocks;
    std::chrono::steady_clock::time_point birth;

    class EasyTick
    {
      private:
        EasyTick() {}
        std::string name;
      public:
        EasyTick(std::string name) : name(name) { Clocker::instance().tick(name); }
        ~EasyTick() { Clocker::instance().tick(name); }
    };

    void guard(int n);
    double tick(std::string name);
    double get_delta(std::string name);
    std::map<std::string, double> get_summary();
    std::string detail(std::string name);
};

// cpp
static Clocker _instance;

Clocker &Clocker::instance() { return _instance; }

double Clocker::tick(std::string name)
{
    auto now = std::chrono::steady_clock::now();
    if (clocks.empty()) { birth = now; }
    if (clocks.find(name) == clocks.end()) {
        clocks.insert(make_pair(name, vector<std::chrono::steady_clock::time_point>()));
    }
    auto &ticks = clocks[name];
    ticks.push_back(now);
    auto n = ticks.size();
    if (n % 2 == 0) {
        return chrono::duration_cast<chrono::duration<double>>(ticks[n - 1] - ticks[n - 2]).count();
    }
    return 0.0;
}

double Clocker::get_delta(std::string name)
{
    if (clocks.find(name) == clocks.end()) { return -1.0; }
    auto &ticks = clocks[name];
    auto n = ticks.size();
    if (n < 2) { return 0.0; }
    return chrono::duration_cast<chrono::duration<double>>(ticks[n - 1] - ticks[n - 2]).count();
}

void Clocker::guard(int n)
{
    if (n % 2 != 0) { exit(-1); }
}

map<string, double> Clocker::get_summary()
{
    map<string, double> summary;
    for (auto &pair : clocks) {
        string name = pair.first;
        auto &ticks = pair.second;
        auto n = ticks.size();
        guard(n);
        double sum = 0.0;
        for (size_t i = 0; i + 1 < n; i += 2) {
            double delta = chrono::duration_cast<chrono::duration<double>>(ticks[i + 1] - ticks[i]).count();
            sum += delta;
        }
        summary.insert(make_pair(name, sum));
    }
    return summary;
}

string Clocker::detail(string name)
{
    stringstream ss;
    auto &ticks = clocks[name];
    auto n = ticks.size();
    guard(n);

    // ticks
    ss << "===Detail of '" << name << "'===\n" << "Ticks: ";
    for (size_t i = 0; i < n; i++) {
        double now = chrono::duration_cast<chrono::duration<double>>(ticks[i] - birth).count();
        ss << now << "\t";
    }
    ss << "\n";

    vector<double> diffs;
    diffs.reserve(n - 1);

    // durations
    ss << "Diffs: ";
    for (size_t i = 0; i + 1 < n; i += 2) {
        double delta = chrono::duration_cast<chrono::duration<double>>(ticks[i + 1] - ticks[i]).count();
        diffs.push_back(delta);
        ss << delta << "\t";
    }

    double sum = accumulate(diffs.begin(), diffs.end(), 0.0);
    double mean = sum / diffs.size();
    double stdev = 0.0;
    if (diffs.size() >= 2) {
        double sq_sum = inner_product(diffs.begin(), diffs.end(), diffs.begin(), 0.0);
        stdev = std::sqrt(sq_sum / diffs.size() - mean * mean);
    }
    ss << "\nsum: " << sum;
    ss << "\nmean: " << mean;
    ss << "\nstd dev: " << stdev;
    ss << "\n";
    return ss.str();
}
