#include "Scheduler.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"


Scheduler::Scheduler() : 
m_shuting_down(false) {

    m_process_tasks = false;
}

Scheduler::~Scheduler(){
    std::unique_lock<std::mutex> lk(m_cv_mutext);
    m_shuting_down = true;

    m_cv.notify_all();
}

void Scheduler::Start() { 
    
    auto adder_thread = std::thread([&](){
        
        ErrorLogger::logInfo("Scheduler thread started");
        while (!m_shuting_down)
        {
            while(nextTaskReady()){
                auto task = m_next_tasks.top();
                m_next_tasks.pop();

                task->Run();
            }

            std::unique_lock<std::mutex> lk(m_cv_mutext);
            m_cv.wait_for(lk, std::chrono::minutes(1) , [&]{return m_shuting_down;});
        }
    });
    adder_thread.detach();
}

void Scheduler::ScheduleTask(
    std::shared_ptr<ScheduledTask> task
){

    auto t = std::chrono::system_clock::to_time_t(task->GetTime());
    std::string time = std::ctime(&t);
    ErrorLogger::logInfo("task added to run at : "+time);

    m_next_tasks.push(task);   
}

bool Scheduler::nextTaskReady() {

    if(m_next_tasks.size() == 0){
        return false;
    }

    if(m_next_tasks.top()->IsElapsed()){
        return true;
    }

    return false;
}