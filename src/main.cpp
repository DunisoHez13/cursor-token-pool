// main.cpp — entry point. Wires config and subsystems together.

#include "cursortokenpool/settings.h"
#include "cursortokenpool/pool.h"
#include "cursortokenpool/quota.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    cursortokenpool::Settings settings = cursortokenpool::Settings::load_default();
    cursortokenpool::Pool pool(settings.store_path);
    cursortokenpool::Quota quota(settings.store_path);
    std::fprintf(stderr, "[cursor-token-pool] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
