
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

        void SetFequency(
            std::chrono::duration duration,
            std::chrono::system_clock::timepoint start_time 
        );
        void SetCallback(std::function<void ()> callback);

        void ScheduleNextInstance(
            std::chrono::duration when
        );

        void Enable();
        void Disable();


    private:

        std::function<void ()> m_callback;

        bool m_enabled;
        std::chrono::duration m_duration;
        std::chrono::system_clock::timepoint m_start_time;

        std::shared_ptr<Scheduler> m_scheduler;


};