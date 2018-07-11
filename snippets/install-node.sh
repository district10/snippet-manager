# install nodejs
wget https://github.com/tj/n/archive/v2.1.0.tar.gz
tar xzf v2.1.0.tar.gz
pushd n-2.1.0
make install
n 8.0.0
popd
rm -fr v2.1.0.tar.gz n-2.1.0
