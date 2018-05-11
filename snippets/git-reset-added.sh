git reset HEAD *                # unstage files
git clean -fd                   # remove untracked
git clean -fdx                  # remove untracked, including ignored files in pwd
git clean -fdx :/               # remove untracked, including ignored files in whole repo
