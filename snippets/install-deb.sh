# http://doi-2014.qiniudn.com/pandoc/pandoc-1.17.0.2-1-amd64.deb
wget https://github.com/jgm/pandoc/releases/download/1.17/pandoc-1.17-1-amd64.deb
sudo dpkg -i pandoc*.deb                    # install deb
sudo dpkg -r pandoc*.deb                    # remove deb
sudo apt-get install -f                     # Install dependencies
dpkg -l | less
