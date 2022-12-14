#include "lua_clone.h"

typedef struct progress_data {
  git_transfer_progress fetch_progress;
  size_t completed_steps;
  size_t total_steps;
  const char *path;
} progress_data;

static void print_progress(const progress_data *pd) {
  int network_percent = pd->fetch_progress.total_objects > 0
                            ? (100 * pd->fetch_progress.received_objects) /
                                  pd->fetch_progress.total_objects
                            : 0;
  int index_percent = pd->fetch_progress.total_objects > 0
                          ? (100 * pd->fetch_progress.indexed_objects) /
                                pd->fetch_progress.total_objects
                          : 0;

  int checkout_percent =
      pd->total_steps > 0 ? (100 * pd->completed_steps) / pd->total_steps : 0;
  int kbytes = pd->fetch_progress.received_bytes / 1024;

  if (pd->fetch_progress.total_objects &&
      pd->fetch_progress.received_objects == pd->fetch_progress.total_objects) {
    printf("Resolving deltas %d/%d\r", pd->fetch_progress.indexed_deltas,
           pd->fetch_progress.total_deltas);
  } else {
    printf(
        "net %3d%% (%4d kb, %5d/%5d)  /  idx %3d%% (%5d/%5d)  /  chk %3d%% "
        "(%4" PRIuZ "/%4" PRIuZ ") %s\n",
        network_percent, kbytes, pd->fetch_progress.received_objects,
        pd->fetch_progress.total_objects, index_percent,
        pd->fetch_progress.indexed_objects, pd->fetch_progress.total_objects,
        checkout_percent, pd->completed_steps, pd->total_steps, pd->path);
  }
}

static int sideband_progress(const char *str, int len, void *payload) {
  (void)payload;  // unused

  printf("remote: %.*s", len, str);
  fflush(stdout);
  return 0;
}

static int fetch_progress(const git_transfer_progress *stats, void *payload) {
  progress_data *pd = (progress_data *)payload;
  pd->fetch_progress = *stats;
  print_progress(pd);
  return 0;
}
static void checkout_progress(const char *path, size_t cur, size_t tot,
                              void *payload) {
  progress_data *pd = (progress_data *)payload;
  pd->completed_steps = cur;
  pd->total_steps = tot;
  pd->path = path;
  print_progress(pd);
}

int lua_git_clone_public(lua_State *L) {
  if (lua_gettop(L) != 3) {
    return luaL_error(L,
                      "expecting 3 argument(s) : "
                      "url(string),path(string),should_print_progress(int)");
  }

  progress_data pd = {{0}};
  git_repository *cloned_repo = NULL;
  git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
  git_checkout_options checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;
  const char *url = luaL_checkstring(L, 1);
  const char *path = luaL_checkstring(L, 2);
  int should_print_progress = luaL_checkinteger(L, 3);

  if (should_print_progress == 1) {
    // Set up options
    checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
    checkout_opts.progress_cb = checkout_progress;
    checkout_opts.progress_payload = &pd;
    clone_opts.checkout_opts = checkout_opts;
    clone_opts.fetch_opts.callbacks.sideband_progress = sideband_progress;
    clone_opts.fetch_opts.callbacks.transfer_progress = &fetch_progress;
    // clone_opts.fetch_opts.callbacks.credentials = cred_acquire_cb;
    clone_opts.fetch_opts.callbacks.payload = &pd;
  }

  check_error_long(git_clone(&cloned_repo, url, path, &clone_opts),
                   "Failed to clone the given repository", url);

  return 1;
}