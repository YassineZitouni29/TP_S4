#include <iostream>
#include <string>
#include <unordered_set>
#include "Movies.hpp"
#include "Movie.hpp"
using namespace std;
vector<movie> movies::give_movies(){
    return movies::all_movies;
}
bool movies::add_movie(string Name, string Rat, int watched){
    for (movie& movie : all_movies){
        if (movie.get_name()==Name){
            return false;
        }
    }
    all_movies.push_back(movie(Name, Rat, watched));
    return true;
}
bool movies::increment_watched(std::string n){
    for (movie& movie: all_movies){
        if (movie.get_name() == n){
            movie.increment_count();
            return true;
        }
    }
    return false;
}
bool movies::display(){
    for (movie& movie : all_movies){
        movie.display_info();
    }
    cout<<"Rien a afficher"<<endl;
    return false;
}