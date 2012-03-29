#include "rust_sched_launcher.h"
#include "rust_scheduler.h"

const size_t SCHED_STACK_SIZE = 1024*100;

rust_sched_launcher::rust_sched_launcher(rust_scheduler *sched,
                                         rust_srv *srv, int id)
    : rust_thread(SCHED_STACK_SIZE),
      kernel(sched->kernel),
      thread(sched, srv, id) {
}

void
rust_sched_launcher::run() {
    thread.start_main_loop();
}
