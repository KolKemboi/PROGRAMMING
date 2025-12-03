#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <mpv/client.h>

static void die(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

static void run_cmd(mpv_handle *mpv, std::initializer_list<const char *> args) {
  const char *cmd[16] = {};
  int i = 0;
  for (auto a : args)
    cmd[i++] = a;
  cmd[i] = nullptr;
  if (mpv_command(mpv, cmd) < 0) {
    die("mpv command failed");
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    die("Usage ./kolplayer <file>");
  }

  mpv_handle *mpv = mpv_create();
  if (!mpv) {
    die("Failed to connect to mpv");
  }
  mpv_set_option_string(mpv, "vo", "null");

  if (mpv_initialize(mpv) < 0) {
    die("failed to initialize mpv");
  }

  run_cmd(mpv, {"loadfile", argv[1]});

	run_cmd(mpv, {"set", "pause", "yes"});
	
	run_cmd(mpv, {"set", "pause", "no"});
	
	// run_cmd(mpv, {"seek", "10"});

	// run_cmd(mpv, {"seek", "-5"});
	
	run_cmd(mpv, {"set", "mute", "yes"});

	run_cmd(mpv, {"set", "mute", "no"});


  while (1) {
    mpv_event *ev = mpv_wait_event(mpv, 1.0);
    if (ev->event_id == MPV_EVENT_END_FILE)
      break;
    if (ev->event_id == MPV_EVENT_SHUTDOWN)
      break;
  }

  mpv_terminate_destroy(mpv);
  return 0;
}
