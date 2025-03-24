#ifndef MOVIES
#define MOVIES

#include <vector>
#include <string>
#include "Movie.hpp"
class movies{
    private:
        vector<movie> all_movies;
    public:
        vector<movie> give_movies(); 
        bool add_movie(string Name, string rating, int watched);
        bool increment_watched(string n);
        bool display();
};
#endif