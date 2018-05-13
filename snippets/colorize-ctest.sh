# colorize word
ctest \
    | sed ''/Failed\ \ /s//`printf "\033[31mFailed\033[0m"`/'' \
    | sed ''/Passed\ \ /s//`printf "\033[32mPassed\033[0m"`/''
