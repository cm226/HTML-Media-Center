
#include <functional>
#include <memory>
#include <chrono>
#include <vector>

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


        // days is a list of days (represented as number of days since sunday) that the schedule is enabled for
        void Enable(
            std::vector<int> days
        );
        void Disable();

    private:

        bool EnabledForDay(
            std::chrono::system_clock::time_point when
        );

    private:

        std::function<void ()> m_callback;

        bool m_enabled;
        std::chrono::minutes m_duration;
        std::chrono::system_clock::time_point m_start_time;

        std::vector<int> m_enabled_days;

        std::shared_ptr<Scheduler> m_scheduler;


};