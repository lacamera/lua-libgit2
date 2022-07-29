package = "lua-libgit2"
version = "0.1.0"
dependencies = {"lua == 5.3"}
description = {
   summary = "",
   homepage = "https://github.com/lacamera/lua-libgit2",
   license = "BSD-2-Clause",
}
source = {
	url = "https://github.com/lacamera/lua-libgit2"
}
build = {
  type = "builtin",
  modules = {
    lua-libgit2 = {
      libraries = { "git2", "lua5.3" },
      sources = {
		"src/lua_common.c",
        "src/lua_libgit2.c",
        "src/lua_blame.c",
        "src/lua_blame_help.c",
        "src/lua_blob.c",
        "src/lua_branch.c",
        "src/lua_branch_help.c",
        "src/lua_checkout.c",
        "src/lua_clone.c",
        "src/lua_commit.c",
        "src/lua_config.c",
        "src/lua_config_help.c",
        "src/lua_cred.c",
        "src/lua_cred_help.c",
        "src/lua_ignore.c",
        "src/lua_diff.c",
        "src/lua_diff_help.c",
        "src/lua_describe.c",
        "src/lua_graph.c",
        "src/lua_index.c",
        "src/lua_index_help.c",
        "src/lua_oid.c",
        "src/lua_note.c",
        "src/lua_odb.c",
        "src/lua_reference.c",
        "src/lua_reflog.c",
        "src/lua_repository.c",
        "src/lua_revwalk.c",
        "src/lua_revparse.c",
        "src/lua_revparse_help.c",
        "src/lua_revert.c",
        "src/lua_reset.c",
        "src/lua_signature.c",
        "src/lua_signature_help.c",
        "src/lua_status.c",
        "src/lua_status_help.c",
        "src/lua_tree.c",
        "src/lua_tag.c",
        "src/lua_object.c",
        "src/lua_buf.c",
        "src/lua_buf_help.c",
        "src/lua_annotated.c",
        "src/wrapper.c" 
      }
    }
  }
}
