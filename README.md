需要安装`vcpkg`

编译：

```shell
vcpkg install assimp:x64-windows opencv:x64-windows catch2:x64-windows
vcpkg export assimp:x64-windows opencv:x64-windows catch2:x64-windows --raw --output-dir=. --output=vcpkg
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

所生成的二进制文件在`bin/`下