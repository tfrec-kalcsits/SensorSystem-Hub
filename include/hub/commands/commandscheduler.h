#pragma once

#include <queue>

#include <hub/commands/command.h>
#include <hub/threadprocess.h>

namespace sensorsystem
{

class CommandScheduler : public ThreadProcess
{
    public:
    CommandScheduler();
    void scheduleCommand(std::unique_ptr<Command> command);
    
    private:
    void threadFunction() override;

    std::thread dispatch_thread;
    std::mutex queue_lock;
    std::priority_queue<Command> queue;
    std::atomic_bool quit_thread = true;
}

}