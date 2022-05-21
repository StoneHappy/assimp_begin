# Stone project template

## Clone

```bash
git clone https://github.com/StoneHappy/assimp_begin.git --recursive

or 

git clone https://github.com/StoneHappy/assimp_begin.git

git submodule init --update
```

## how to build

```bash
vcpkg install qt5:x64-windows qt-advanced-docking-system:x64-windows


cd Stone_Project_Template

mkdir build

cd build 

cmake .. -DCMAKE_TOOLCHAIN_FILE=path to/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=your target triplet

cmake --build ./ --config RelWithDebInfo --target StoneShadercompile -j 10
cmake --build ./ --config RelWithDebInfo --target AssimpBegin -j 10
```
