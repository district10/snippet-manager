/// acm ,accumulate
auto sum = std::accumulate(std::begin(%\m C%), std::end(%\m C%), 0);
/// ucp ,unique_copy
std::unique_copy(std::begin(%\m C%), std::end(%\m C%), std::ostream_iterator&lt;string&gt;(std::cout, "\n"));
/// ita ,iota
std::iota(std::begin(%\m C%), std::end(%\m C%), %\c);
/// iss ,is_sorted
if (std::is_sorted(std::begin(%\m C%), std::end(%\m C%))) { %\c }
/// rpc ,replace_copy
std::replace_copy(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%), %\c, %\c);
/// isu ,is_sorted_until
auto pos = std::is_sorted_until(std::begin(%\m C%), std::end(%\m C%));
if (pos != std::end(%\m C%)) { %\c }
/// rmv ,remove
auto pos = std::remove(std::begin(%\m C%), std::end(%\m C%), %\c); if (pos != std::end(%\m C%)) { %\c }
/// nth ,nth_element
std::nth_element(std::begin(%\m C%), std::end(%\m C%), std::end(%\m C%));
/// rpi ,replace_if
std::replace_if(std::begin(%\m C%), std::end(%\m C%), [](%\c) { %\c }, %\c);
/// rpl ,replace
std::replace(std::begin(%\m C%), std::end(%\m C%), %\c, %\c);
/// erm ,erase
%\m C%.erase(std::remove(std::begin(%\m C%), std::end(%\m C%), %\c), std::end(%\m C%));
/// tfm ,transform
std::transform(std::begin(%\m C%), std::end(%\m C%), std::begin(%\m C%), [](%\c) { %\c% });
