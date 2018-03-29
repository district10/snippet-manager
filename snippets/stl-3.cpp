/// fln ,fill_n
std::fill_n(std::begin(%\m C%), %\c, %\c);
/// alo ,all_of
if (std::all_of(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c })) { %\c }
/// prp ,prev_permutation
if (std::prev_permutation(std::begin(%\m C%), std::end(%\m C%))) { %\c }
/// ltr ,string_trim_left
%\m C%.erase(0, %\m C%.find_first_not_of(" \t\n\r"));
/// upr ,string_upper
std::transform(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%), [](char c) { return std::toupper(c); });
/// psc ,partial_sort_copy
std::partial_sort_copy(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), std::end(%\c));
/// ppt ,partition_point
auto pos = std::partition_point(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c });
if (pos != std::end(%\m C%)) {
  %\c
}
/// cnt ,count
auto n = std::count(std::begin(%\m C%), std::end(%\m C%), %\c);
/// uqe ,unique
auto pos = std::unique(std::begin(%\m C%), std::end(%\m C%));
/// sti ,cin
std::cin &gt;&gt;
/// cpy ,copy
std::copy(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c));
/// sto ,cout
std::cout &lt;&lt;
/// cpb ,copy_backward
std::copy_backward(std::begin(%\m C%), std::end(%\m C%), std::end(%\m C%));
