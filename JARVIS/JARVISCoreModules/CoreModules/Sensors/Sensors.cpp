#include "Sensors.h"

#include "../Database/Querys/NoBullshitQuery.h"

extern const char sensor_name_col[] = "sensor_name";

Sensors::Sensors(){
}

void Sensors::Start(
    DatabaseTables::Database* db,
    IHTTPUrlRouter* router){
        LoadSensorsFromDB(db, router);
}

MotionSensor* Sensors::GetSensorByName(
    std::string name ){

        if(m_sensors.find(name) != m_sensors.end()){
            return m_sensors[name].get();
        }

        return nullptr;
}

void Sensors::GetAllSensors(
    std::vector<std::shared_ptr<MotionSensor>>& sensors
){
    sensors.clear();

    for(auto& sensor: m_sensors){
        sensors.push_back(sensor.second);
    }
}

void Sensors::LoadSensorsFromDB(
    DatabaseTables::Database* db,
    IHTTPUrlRouter* router
){

    DatabaseTables::NoBullshitQuery query("\
        SELECT Sensors.sensor_name \
        FROM Sensors");
        
    ResultWrapper result_wrapper;
    db->runQuery(
        &query, 
        result_wrapper);

    auto results = Results<
        Column<std::string, sensor_name_col>
    >(result_wrapper);  

    for(auto& sensor : results){
        m_sensors[sensor->Value()] 
            = std::make_shared<MotionSensor>(sensor->Value(), router);
    }    


}