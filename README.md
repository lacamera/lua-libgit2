# lua-libgit2
Lua bindings to libgit2 written using [LuaC-API](https://www.lua.org/pil/24.html)

### From source
```
mkdir build
cd build
cmake ..
# OpenBSD: LIBRARY_PATH=/usr/local/lib make
make 
doas make install
```

### Using luarocks
```
doas luarocks make
```
