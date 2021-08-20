#pragma once 

#include "TaskList.h"

#include <memory>
#include <queue>
#include <chrono>
#include <functional>
#include <mutex>


class ScheduledTask {

    public:
        ScheduledTask(std::string name) {
            m_name = name;
        }

        virtual void Run() = 0;

        bool operator< (const ScheduledTask& other
        ){
             return  m_tp < other.m_tp;
        }

        bool operator> (const ScheduledTask& other
        ){
             return  m_tp > other.m_tp;
        }

        bool ChangeTime(std::chrono::time_point<std::chrono::system_clock> new_tp){
            std::lock_guard<std::mutex> guard(m_tp_mutex);

            if(m_elapsed){
                return false;
            }
            
            m_tp = new_tp;

            return true;
        }



        bool IsElapsed(){
            std::lock_guard<std::mutex> guard(m_tp_mutex);
            if(m_tp < std::chrono::system_clock::now()){
                m_elapsed = true;
               return true;
            }
            return false;;
        }

        std::chrono::time_point<std::chrono::system_clock> GetTime(){
            return m_tp;
        }

    protected: 
        std::chrono::time_point<std::chrono::system_clock> m_tp;
        std::mutex m_tp_mutex;
        bool m_elapsed = false;
        std::string m_name;
};

// calls a callback at a speified time
class CallbackTask : public ScheduledTask {

    public:

        CallbackTask(
            std::function<void()> cmd,
            std::chrono::time_point<std::chrono::system_clock> tp,
            std::string name = "callback task"
        ) 
            :
            ScheduledTask(name) 
        {
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

    typedef std::shared_ptr<ScheduledTask> task_item_t;

    std::function<bool (const task_item_t&, 
                   const task_item_t&)> compare_f = 
                   [](
                   const task_item_t& item1, 
                   const task_item_t& item2){
                       return *item1 > *item2;
                   };

    std::priority_queue<
        task_item_t, 
        std::vector<task_item_t>, 
        decltype(compare_f)
    > m_next_tasks;
    bool m_process_tasks;

    // shutdown 
    std::condition_variable m_cv;
    std::mutex m_cv_mutext;
    bool m_shuting_down;

};