
rm -r ./build
mkdir build

cp ./script/*.py ./build

cd build
cmake .. 
make -j8 