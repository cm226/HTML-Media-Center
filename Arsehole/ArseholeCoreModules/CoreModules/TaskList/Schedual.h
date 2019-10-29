
#include <functional>
#include <memory>
#include <chrono>

class Scheduler;

class Schedual{

    public:
        Schedual(
            std::shared_ptr<Scheduler> scheduler
        );
        virtual ~Schedual();

        void Initialise(
            std::chrono::minutes duration,
            std::chrono::system_clock::time_point start_time,
            std::function<void ()> callback 
        );

        void ScheduleNextInstance(
            std::chrono::system_clock::time_point when
        );

        void Enable();
        void Disable();


    private:

        std::function<void ()> m_callback;

        bool m_enabled;
        std::chrono::minutes m_duration;
        std::chrono::system_clock::time_point m_start_time;

        std::shared_ptr<Scheduler> m_scheduler;


};