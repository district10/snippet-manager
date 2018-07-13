// map erase element
#include <map>
#include <iostream>
int main()
{
    std::map<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};
    // erase all odd numbers from c
    for(auto it = c.begin(); it != c.end(); )
        if(it->first % 2 == 1) {
            it = c.erase(it);
            // mit = c.erase(mit);
        }
        else
            ++it;
    for(auto& p : c)
        std::cout << p.second << ' ';
}
