du -sh .            # directory summary
du -sh *
du -sh -- * .*      # include dot files

du -sh * | grep 'M' | sort -n
