#pragma once 

#include "TaskList.h"

#include <memory>
#include <queue>
#include <chrono>
#include <functional>


class ScheduledTask {

    public:
        virtual void Run() = 0;

        bool operator< (const ScheduledTask& other
        ){
             return  m_tp < other.m_tp;
        }

        std::chrono::time_point<std::chrono::system_clock> Time(){
            return m_tp;
        }

    protected: 
        std::chrono::time_point<std::chrono::system_clock> m_tp;

};

// calls a callback at a speified time
class CallbackTask : public ScheduledTask {

    public:

        CallbackTask(
            std::function<void()> cmd,
            std::chrono::time_point<std::chrono::system_clock> tp
        ){
            m_cmd = cmd;
            m_tp = tp;
        }

        void Run(){
            m_cmd();
        }

    private:
        std::function<void()> m_cmd;
};

class Scheduler{

public:
    Scheduler();
    virtual ~Scheduler();

    void Start();
    void ScheduleTask(std::shared_ptr<ScheduledTask> task);

private:
    bool nextTaskReady();

private:

    std::priority_queue<std::shared_ptr<ScheduledTask>> m_next_tasks;
    bool m_process_tasks;

    // shutdown 
    std::condition_variable m_cv;
    std::mutex m_cv_mutext;
    bool m_shuting_down;

};