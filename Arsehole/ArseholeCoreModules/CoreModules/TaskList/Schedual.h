
#include <functional>

class Schedual{

    public:
        Schedual();
        virtual ~Schedual();

        void SetFequency(
            std::chrono::duration duration,
            std::chrono::system_clock::timepoint start_time 
        );
        void SetCallback(std::function<void ()> callback);

        void Enable();
        void Disable();


    private:

        std::function<void ()> m_callback;

        bool m_enabled;
        std::chrono::duration m_duration;
        std::chrono::system_clock::timepoint m_start_time;


};