#include <chrono>
#include <hub/data/measurement.h>

tm getTimestamp()
{
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return *localtime(&now);
}