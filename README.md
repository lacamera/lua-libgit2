```
 __                     __ __ __           __ __   ______ 
|  |.--.--.---.-.______|  |__|  |--.-----.|__|  |_|__    |
|  ||  |  |  _  |______|  |  |  _  |  _  ||  |   _|    __|
|__||_____|___._|      |__|__|_____|___  ||__|____|______|
                                   |_____|                                   
lua-5.3 bindings to libgit2
```  
Maintained by `Francesco La Camera <fm@lacamera.org>`, entirely [ISC](LICENSE)
### Dependencies
`lua-libgit2` needs `lua==5.3` and `libgit2`.
### Installation
#### Luarocks
```sh
(root) luarocks make
```
#### From source
```sh
# OpenBSD
(root) pkg_add lua-5.3 git
export LIBRARY_PATH=/usr/local/lib
```
```sh
# Debian/Ubuntu
(root) apt install lua5.3 liblua5.3-dev libgit2-dev
```
```sh
mkdir build && cd build
cmake ..
make 
(root) make install
```
### Documentation
Consult `apropros lua-libgit2` and inspect the source code if necessary.  
#### Hierarchy
```
- src/                  lua_*.{c,h} and wrapper.c
- Findlibgit2.cmake     cmake: libgit2 "find" script (cmake needs this)
- CMakeLists.txt        cmake co-routines
- lua-libgit2.rockspec  (wip) (luarocks pkgconf)
- README.md             markdown formatted README
```
Originally inspired by `luagit2`.
