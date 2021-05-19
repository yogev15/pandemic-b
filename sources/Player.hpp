#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic{

    class Player{
        protected:
        std::string role_;
        City current_city; 
        std::unordered_set<City> cards;  
        Board& board;

        Color random_color();


        bool holds_card(City city);

        public:
      
          Player(Board& b, City city):board(b), current_city(city){
            this->cards = {};
          }

          virtual Player& drive(City city); 
          virtual Player& fly_direct(City city);
          virtual Player& fly_charter(City city);
          virtual Player& fly_shuttle(City city);
          virtual void build();
          virtual Player& discover_cure(Color color);
          virtual Player& treat(City city); 
          std::string role();
          Player& take_card(City city);
          void remove_cards();
        
    };
}