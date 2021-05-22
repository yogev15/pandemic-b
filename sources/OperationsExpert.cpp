#include "OperationsExpert.hpp"

using namespace pandemic;
    
    void OperationsExpert::build(){
         if(!this->board.exists_station(this->current_city)){
             this->board.build_station(this->current_city);
         }
    }
