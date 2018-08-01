# update git commit email
# user.email
git filter-branch --commit-filter '
      if [ "$GIT_AUTHOR_EMAIL" = "wrong_email@wrong_host.local" ];
      then
              GIT_AUTHOR_NAME="Your Name Here (In Lights)";
              GIT_AUTHOR_EMAIL="correct_email@correct_host.com";
              git commit-tree "$@";
      else
              git commit-tree "$@";
      fi' HEAD
