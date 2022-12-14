cmake_minimum_required (VERSION 3.0)
project (lua-libgit2 C)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${lua-libgit2_SOURCE_DIR}")
MESSAGE("${CMAKE_MODULE_PATH}")
find_package(Lua 5.3 EXACT REQUIRED)
find_package(libgit2 REQUIRED)
include_directories (
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LUA_INCLUDE_DIR}
    ${LIBGIT2_INCLUDE_DIR}
    ${CMAKE_INSTALL_PREFIX}
)

set(src_dest "src/")
set (SOURCES
  ${src_dest}/lua_common.c
  ${src_dest}/lua_libgit2.c
  ${src_dest}/lua_blame.c
  ${src_dest}/lua_blame_help.c
  ${src_dest}/lua_blob.c
  ${src_dest}/lua_branch.c
  ${src_dest}/lua_branch_help.c
  ${src_dest}/lua_checkout.c
  ${src_dest}/lua_clone.c
  ${src_dest}/lua_commit.c
  ${src_dest}/lua_config_help.c
  ${src_dest}/lua_config.c
  ${src_dest}/lua_cred.c
  ${src_dest}/lua_cred_help.c
  ${src_dest}/lua_ignore.c
  ${src_dest}/lua_diff.c
  ${src_dest}/lua_diff_help.c
  ${src_dest}/lua_describe.c
  ${src_dest}/lua_cred_help.c
  ${src_dest}/lua_graph.c
  ${src_dest}/lua_index.c
  ${src_dest}/lua_index_help.c
  ${src_dest}/lua_oid.c
  ${src_dest}/lua_note.c
  ${src_dest}/lua_odb.c
  ${src_dest}/lua_reference.c
  ${src_dest}/lua_reflog.c
  ${src_dest}/lua_repository.c
  ${src_dest}/lua_revwalk.c
  ${src_dest}/lua_revparse.c
  ${src_dest}/lua_revparse_help.c
  ${src_dest}/lua_revert.c
  ${src_dest}/lua_reset.c
  ${src_dest}/lua_signature.c
  ${src_dest}/lua_signature_help.c
  ${src_dest}/lua_status.c
  ${src_dest}/lua_status_help.c
  ${src_dest}/lua_tree.c
  ${src_dest}/lua_tag.c
  ${src_dest}/lua_object.c
  ${src_dest}/lua_buf.c
  ${src_dest}/lua_buf_help.c
  ${src_dest}/lua_annotated.c
  ${src_dest}/wrapper.c 
)

set(lib_dest "lib/lua/5.3")
OPTION(BUILD_SHARED_LIBS ON)
add_library (${PROJECT_NAME} SHARED ${SOURCES} ${LUA_LIBRARIES})
target_link_libraries (${PROJECT_NAME} lua5.3 git2)
set_target_properties (${PROJECT_NAME} PROPERTIES PREFIX "")
install(TARGETS ${PROJECT_NAME} DESTINATION "${lib_dest}")
