
#include "MotionSensor.h"

#include "../Database/Database.h"

class Sensors {

public:
    Sensors();

    void Start(DatabaseTables::Database* db, IHTTPUrlRouter* router);
    MotionSensor* GetSensorByName(std::string name);
    void GetAllSensors(std::vector<std::shared_ptr<MotionSensor>>& sensors);

private:
    void LoadSensorsFromDB(DatabaseTables::Database* db, IHTTPUrlRouter* router);

private:
    std::map<std::string, std::shared_ptr<MotionSensor>> m_sensors;

};