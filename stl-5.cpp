/// mrg ,merge
std::merge(std::begin(%\m C%), std::end(%\m C%),
std::begin(%\c), std::end(%\c), std::begin(%\c));
/// srh ,search
auto pos = std::search(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c), std::end(%\c));
if (pos != std::end(%\m C%)) {
    %\c
}
/// fni ,find_if
auto pos = std::find_if(std::begin(%\m C%), std::end(%\m C%), [](%\c) {
  %\c
});
if (pos != std::end(%\m C%)) {
  %\c
}
