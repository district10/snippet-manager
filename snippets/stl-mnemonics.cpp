/// upb ,upper_bound
auto pos = std::upper_bound(std::begin(%\m C%), std::end(%\m C%), %\c);
if (pos != std::end(%\m C%)) { %\c }
/// eqr ,equal_range
auto bounds = std::equal_range(std::begin(%\m C%), std::end(%\m C%), %\c);
/// erl ,equal_range
auto bounds = std::equal_range(std::begin(%\m C%), std::end(%\m C%), %\c,
  [](%\c,%\c) { %\c });
/// stu ,set_union
auto pos = std::set_union(std::begin(%\m C%), std::end(%\m C%),
  std::begin(%\c), std::end(%\c), std::begin(%\c));
/// stn ,set_intersection
auto pos = std::set_intersection(std::begin(%\m C%), std::end(%\m C%),
  std::begin(%\c), std::end(%\c), std::begin(%\c));
/// std ,set_difference
auto pos = std::set_difference(std::begin(%\m C%), std::end(%\m C%),
  std::begin(%\c), std::end(%\c), std::begin(%\c));
/// ssd ,set_symmetric_difference
auto pos = std::set_symmetric_difference(std::begin(%\m C%),
  std::end(%\m C%), std::begin(%\c), std::end(%\c), std::begin(%\c));
/// ipm ,inplace_merge
std::inplace_merge(std::begin(%\m C%), std::end(%\m C%), std::end(%\m C%));
/// mov ,move
std::move(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%));
/// mvb ,move_backward
std::move_backward(std::begin(%\m C%), std::end(%\m C%), std::end(%\m C%));
/// swp ,swap
std::swap(%\m C%, %\c);
