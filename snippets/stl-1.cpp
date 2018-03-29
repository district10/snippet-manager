/// ihp ,is_heap
if (std::is_heap(std::begin(%\m C%), std::end(%\m C%))) { %\c }
/// mme ,minmax_element
auto minmax = std::minmax_element(std::begin(%\m C%), std::end(%\m C%));
/// ihu ,is_heap_until
auto pos = std::is_heap_until(std::begin(%\m C%), std::end(%\m C%));
if (pos != std::end(%\m C%)) { %\c }
/// acl ,accumulate
auto sum = std::accumulate(std::begin(%\m C%), std::end(%\m C%), 0, [](int total, %\c) { %\c });
/// eql ,equal
if (std::equal(std::begin(%\m C%), std::end(%\m C%), std::begin(%\c))) { %\c }
