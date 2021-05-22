#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <iostream>
#include <stdbool.h>
#include <map>
#include <unordered_set>

namespace pandemic{
    class Board{

        public:
            std::map<City,int> deases_level; 
            std::map<City,Color> cities_color; 
            std::map<City,std::unordered_set<City>> neighbors; 
            std::unordered_set<City> cities_stations; 
            std::unordered_set<Color> discovered_cures; 

        public:

            Board();

            int& operator[](City city);
            friend std::ostream& operator<<(std::ostream& os ,const Board& board);
            bool is_clean();
            void remove_cures();
            void remove_stations();
            //Color which_color(City city);
            bool exists_cure(Color color);
            bool exists_station(City city);
            void build_station(City city);
            bool is_neighbors(City city1 , City city2);
            Color get_color(City city);
            void new_cure_discovered(Color color); 

    };
}