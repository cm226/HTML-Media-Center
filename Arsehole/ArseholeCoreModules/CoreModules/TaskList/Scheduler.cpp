#include "Scheduler.h"


Scheduler::Scheduler() {

    m_process_tasks = false;
}

void Scheduler::Start() { 
    m_process_tasks = true;
    
    m_task_adder_thread = std::thread([&](){
        
        while (m_process_tasks)
        {
            if(nextTaskReady()){
                auto task = m_next_tasks.top();
                m_next_tasks.pop();

                task->Run();
            }

            std::this_thread::sleep_for(std::chrono::minutes(5));
        }
    });
}

void Scheduler::ScheduleTask(
    std::shared_ptr<ScheduledTask> task
){
    m_next_tasks.push(task);   
}

bool Scheduler::nextTaskReady() {

    if(m_next_tasks.size() == 0){
        return false;
    }

    if(m_next_tasks.top()->Time() > std::chrono::system_clock::now()){
        return true;
    }

    return false;
}