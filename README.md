```
 __                     __ __ __           __ __   ______ 
|  |.--.--.---.-.______|  |__|  |--.-----.|__|  |_|__    |
|  ||  |  |  _  |______|  |  |  _  |  _  ||  |   _|    __|
|__||_____|___._|      |__|__|_____|___  ||__|____|______|
                                   |_____|                                   
lua-5.3 bindings to libgit2
```
### Documentation
Consult `apropros lua-libgit2` and inspect the source code if necessary.  
```
hierarchy:
 - src/                  lua_*.{c,h} and wrapper.c
 - Findlibgit2.cmake     cmake: libgit2 "find" script (cmake needs this)
 - CMakeLists.txt        cmake co-routines
 - lua-libgit2.rockspec  (needs reformatting) (luarocks pkgconf)
 - LICENSE               BSD-2-Clause license
 - README.md             markdown formatted README
```
Originally inspired by `luagit2`, this version only supports `Lua==5.3` but ships
in `Lua C`. I don't plan to support versions other than `Lua==5.3` anytime soon; I will hover be updating
`libgit2` support and feature-completion. Feel free to contribute.
Maintainer: `Francesco La Camera <fm@lacamera.org>`
### Installation
Luarocks
```
(root) luarocks make
```
From source
```
mkdir build
cd build
cmake ..
#### OpenBSD: LIBRARY_PATH=/usr/local/lib make
make 
(root) make install
```
