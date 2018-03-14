if (any_of(v.begin(), v.end(), bind2nd(equal_to<string>(), item))) {
   do_this();
} else {
   do_that();
}
