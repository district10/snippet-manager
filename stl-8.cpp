/// rvc ,reverse_copy
std::reverse_copy(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c));
/// oit ,copy
std::copy(std::begin(%\m C%), std::end(%\m C%), std::ostream_iterator&lt;%\c&gt;{ %\istd::cout, "%\c" });
/// sth ,sort_heap
std::sort_heap(std::begin(%\m C%), std::end(%\m C%));
/// phh ,push_heap
std::push_heap(std::begin(%\m C%), std::end(%\m C%));
/// ffo ,find_first_of
auto pos = std::find_first_of(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), std::end(%\c));
if (pos != std::end(%\m C%)) {
  %\c
}
/// gnr ,generate
std::generate(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c });
/// ipr ,is_permutation
if (std::is_permutation(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c))) { %\c }
/// ipt ,is_partitioned
if (std::is_partitioned(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c })) { %\c }
/// mkh ,make_heap
std::make_heap(std::begin(%\m C%), std::end(%\m C%));
/// fil ,fill
std::fill(std::begin(%\m C%), std::end(%\m C%), %\c);
/// fin ,find_if_not
auto pos = std::find_if_not(std::begin(%\m C%), std::end(%\m C%),[](%\c) { %\c });
if (pos != std::end(%\m C%)) {
  %\c
}
