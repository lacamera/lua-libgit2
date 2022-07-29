#ifndef _lua_graph_h
#define _lua_graph_h

#include "lua_common.h"

int lua_git_graph_ahead_behind(lua_State *L);
int lua_git_graph_descendant_of(lua_State *L);

#endif
