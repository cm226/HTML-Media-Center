#include "BevChan.h"
#include "../../ArseholeCoreModules/CoreModules/Database/Querys/NoBullshitQuery.h"
#include "../../ArseholeCoreModules/CoreModules/Database/Results/ResultTypes.h"

#include <chrono>
#include <ctime>

extern const char ts_name_col[] = "timestamp";
extern const char temp_name_col[] = "temp";
extern const char gravity_name_col[] = "gravity";


BevChanPlugin::BevChanPlugin(
    CoreModules* cm
):
    Plugin(cm)
{
    auto comms = cm->getComms();
    auto router = comms->Router();

    router->RegisterWidgit("plugins/Bev_content");

    auto db = cm->getDatabaseConnection();

    router->MapURLRequest(
        "/plugins/Bev/Receive",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            updateDatabaseWithNewReadings(connection);
        }
    );

    router->MapURLRequest(
        "/plugins/Bev/Check",
        [&](
            std::shared_ptr<IHTTPUrlRouter::IConnection> connection
        ){
            getLatestReadings(connection);
        }
    );

}

BevChanPlugin::~BevChanPlugin(){

}

void BevChanPlugin::updateDatabaseWithNewReadings(
    std::shared_ptr<IHTTPUrlRouter::IConnection> connection
){
    auto params = connection->RequestParams();
    float angle = 0.f;
    try{
        angle = std::stof(params["x_angle"]);
    } catch(...){
        ErrorLogger::logError("Failed to convert x angle to float");
    }
    
    auto temp = params["temp"];

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);
    char buff[70];
    if(!strftime(buff, sizeof buff, "%Y-%m-%d %H:%M:%S", &now_tm)){
        ErrorLogger::logError("Failed to generate timestamp for bev reading");
        return;
    }

    auto gravity =  (-0.00401 * angle)+1.31;

    DatabaseTables::NoBullshitQuery update_readings_q(
            "INSERT INTO reading values ('"+std::string(buff)+"', "+temp+", "+std::to_string(gravity)+")");       

    ResultWrapper result_wrapper;
    this->coreMod->getDatabaseConnection()->runQuery(
        &update_readings_q, 
        result_wrapper);

}

void BevChanPlugin::getLatestReadings(
    std::shared_ptr<IHTTPUrlRouter::IConnection> connection
) {
     DatabaseTables::NoBullshitQuery get_readings_q(
            "SELECT * FROM reading");       

    ResultWrapper result_wrapper;
    this->coreMod->getDatabaseConnection()->runQuery(
        &get_readings_q, 
        result_wrapper);

    auto results = Results<
        ResultRow<
            Column<std::string, ts_name_col>,
            Column<float, temp_name_col>,
            Column<float, gravity_name_col>
        >>(result_wrapper);   

    std::stringstream gravity_ss;
    std::stringstream temp_ss;

    int count = 1;
    for (auto& row : results){
        auto timestamp = std::get<0>(row->Row()).Value();
        auto temp = std::get<1>(row->Row()).Value();
        auto gravity = std::get<2>(row->Row()).Value();
        temp_ss << "[";
        temp_ss << "'t' : '"+timestamp+"',";
        temp_ss << "'y' : '"+std::to_string(temp);
        temp_ss << "]";

        gravity_ss << "[";
        gravity_ss << "'t' : '"+timestamp+"',";
        gravity_ss << "'y' : '"+std::to_string(gravity);
        gravity_ss << "]";


        if(count < results.size()){
            temp_ss<<",";
            gravity_ss << ",";
        }
        count++;
    }

    std::stringstream readings;
    readings << "{ data : { 'temperature' : "
    << temp_ss.str()
    << ", 'gravity' : "
    << gravity_ss.str()
    << ", alcoholPercentage: 'bop'}}";

    connection->Write(readings.str());
}

void BevChanPlugin::handleRequest(
    std::string requestURL
) {


}

const std::string BevChanPlugin::pluginName(){
    return "Shopping";
}
