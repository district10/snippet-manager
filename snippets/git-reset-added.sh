git reset HEAD *                # unstage files
git clean -fd                   # remove untracked
git clean -fdx                  # remove untracked, including ignored files in pwd
git clean -fdx :/               # remove untracked, including ignored files in whole repo

git checkout HEAD -- file.txt   # reset one file
git checkout @    -- file.txt   # same as above

git submodule update --init     # reset hard HEAD submodules
