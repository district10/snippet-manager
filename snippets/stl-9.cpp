/// lwr ,string_lower
std::transform(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%), [](char c) {
return std::tolower(c); });
/// lxc ,lexigraphical_compare
if (std::lexigraphical_compare(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), std::end(%\c)) { %\c }
/// shf ,random_shuffle
std::random_shuffle(std::begin(%\m C%), std::end(%\m C%));
/// ajf ,adjacent_find
auto pos = std::adjacent_find(std::begin(%\m C%), std::end(%\m C%));
if (pos != std::end(%\m C%)) {
  %\c
}
/// trm ,string_trim_right
%\m C%.erase(%\m C%.find_last_not_of(" \t\n\r") + 1);
/// gnn ,generate_n
std::generate_n(std::begin(%\m C%), %\c, [](%\c) { %\c });
/// nno ,none_of
if (std::none_of(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c })) { %\c }
/// pph ,pop_heap
std::pop_heap(std::begin(%\m C%), std::end(%\m C%));
/// bns ,binary_search
auto pos = std::binary_search(std::begin(%\m C%), std::end(%\m C%), %\c);
if (pos != std::end(%\m C%)) {
  %\c
}
/// inc ,includes
if (std::includes(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), std::end(%\c))) { %\c }
/// lwb ,lower_bound
auto pos = std::lower_bound(std::begin(%\m C%), std::end(%\m C%), %\c);
if (pos != std::end(%\m C%)) { %\c }
