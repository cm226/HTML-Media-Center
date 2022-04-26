#pragma once

#include <chrono>

template <typename T>
class ExpiringModel {

    public:
        ExpiringModel(T default_value, int expire_hours) : 
         m_default_value(default_value),
         m_value(default_value),
         m_expire_hours(expire_hours) {
        }
        virtual ~ExpiringModel() {};

        const T& get() {
            auto now = std::chrono::system_clock::now();
            if(std::chrono::duration_cast<std::chrono::hours>(now - m_set_at) >
                 std::chrono::hours(this->m_expire_hours)) {
                this->m_value = this->m_default_value;
            }

            return this->m_value;
        }

        void set(const T &val){
            this->m_value = val; 
            this->m_set_at = std::chrono::system_clock::now();
        }

        bool isExpired() {
            auto now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::hours>(now - m_set_at) >
                 std::chrono::hours(this->m_expire_hours);
        }

        int hoursUntilExpire() {
            return (m_expire_hours - std::chrono::duration_cast<std::chrono::hours>(
                std::chrono::system_clock::now() - m_set_at).count());
        }

    private:
        T m_value;
        T m_default_value;

        std::chrono::time_point<std::chrono::system_clock> m_set_at;
        int m_expire_hours;
};