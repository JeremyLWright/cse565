export PATH=/opt/BullseyeCoverage/bin:$PATH
export COVFILE=`pwd`/test.cov
cov01 -1
mkdir build
cd build/
cmake ..
make
./test --quiet

