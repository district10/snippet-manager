/// ptn ,partition
auto pos = std::partition(std::begin(%\m C%), std::end(%\m C%), [](%\c) {
  %\c
});
if (pos != std::end(%\m C%)) {
  %\c
}
/// srn ,search_n
auto pos = std::search_n(std::begin(%\m C%), std::end(%\m C%),%\c,%\c);
if (pos != std::end(%\m C%)) {
    %\c
}
/// ano ,any_of
if (std::any_of(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c })) { %\c }
/// nxp ,next_permutation
if (std::next_permutation(std::begin(%\m C%), std::end(%\m C%))) { %\c }
/// rvr ,reverse
std::reverse(std::begin(%\m C%), std::end(%\m C%));
/// rmc ,remove_copy
std::remove_copy(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%), %\c);
/// sts ,stable_sort
std::stable_sort(std::begin(%\m C%), std::end(%\m C%));
/// rmf ,remove_copy_if
std::remove_copy_if(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%), [](%\c) { %\c });
/// rci ,replace_copy_if
std::replace_copy_if(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%), [](%\c) { %\c }, %\c);
/// rmi ,remove_if
auto pos = std::remove_if(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c });
if (pos != std::end(%\m C%)) {
  %\c
}
