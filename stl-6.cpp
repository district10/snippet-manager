/// ptc ,partition_copy
std::partition_copy(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), std::end(%\c));
/// pst ,partial_sort
std::partial_sort(std::begin(%\m C%), std::end(%\m C%), std::end(%\m C%));
/// fnd ,find
auto pos = std::find(std::begin(%\m C%), std::end(%\m C%), %\c);
if (pos != std::end(%\m C%)) {
    %\c
}
/// fre ,for_each
std::for_each(std::begin(%\m C%), std::end(%\m C%), [](%\c) {
  %\c
});
/// mne ,min_element
auto pos = std::min_element(std::begin(%\m C%), std::end(%\m C%));
/// fne ,find_end
auto pos = std::find_std::end(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), std::end(%\c));
if (pos != std::end(%\m C%)) {
    %\c
}
