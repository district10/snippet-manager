rsync -a ./ --rsh='ssh -p3022' tzx@localhost:/tmp
rsync -avz --delete --exclude 'build' user@host:/path/to/dir/ local/path
#       -r, --recursive: recurse into directories
#       -u, --update: skip files that are newer on the receiver
#       -n, --dry-run: show what would have been transferred
#       --existing: only update files that already exist on receiver
#       --delete: delete files that don’t exist on the sending side
#       -z, --compress: compress file data during the transfer
#       --exclude=PATTERN: exclude files matching PATTERN

# e: protocal
rsync -avzhe ssh root@192.168.0.100:/root/install.log /tmp/

--include 'R*'
--exclude '*'
--max-size='200k'
--dry-run
