/// swr ,swap_ranges
std::swap_ranges(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c));
/// rtc ,rotate_copy
std::rotate_copy(std::begin(%\m C%), std::begin(%\c), std::end(%\m C%), std::begin(%\c));
/// mxe ,max_element
auto pos = std::max_element(std::begin(%\m C%), std::end(%\m C%));
/// rte ,rotate
std::rotate(std::begin(%\m C%), std::begin(%\c), std::end(%\m C%));
/// stv ,vector
std::vector&lt;%\c&gt; %\c
/// cpi ,copy_if
std::copy_if(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), [](%\c) { %\c });
/// cni ,count_if
auto n = std::count_if(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c });
/// cpn ,copy_n
std::copy_n(std::begin(%\m C%), %\c, std::end(%\m C%));
/// srt ,sort
std::sort(std::begin(%\m C%), std::end(%\m C%));
/// spt ,stable_partition
auto pos = std::stable_partition(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c});
if (pos != std::end(%\m C%)) {
  %\c
}
/// msm ,mismatch
auto values = std::mismatch(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%));
if (values.first == std::end(%\m C%)) {
    %\c
} else {
    %\c
}
