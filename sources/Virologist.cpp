#include "Virologist.hpp"

namespace pandemic{

     Player& Virologist::treat(City city){
         if(this->board[city] == 0){
            throw std::invalid_argument("A city free of disease!");
        }

        if(!holds_card(city)&& city != this->current_city){
            throw std::invalid_argument("no card");
        }

        //if cure already exists
        if(this->board.exists_cure(this->board.get_color(city))){
            this->board[city] = 0;
        }
        else{ //if cure not exists
            this->board[city] = (this->board[city]-1);
        }
        this->cards.erase(city);
        return *this;
    }
}