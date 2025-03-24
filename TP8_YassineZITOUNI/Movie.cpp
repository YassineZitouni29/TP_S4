#include <iostream>
#include "Movie.hpp"
#include <string>
using namespace std;
movie::movie(string name, string rating, int watched): name(name), rating(rating), watched(watched){}

string movie::get_name(){
    return name;
}
string movie::get_rating(){
    return rating;
}
int movie::get_watched(){
    return watched;
}
void movie::display_info(){
    movie* curr = this;
    cout<<this->get_name()<<" "<<this->get_rating()<<" "<<this->get_watched();
}
void movie::set_name(string Name){
    name = Name;
}
void movie::set_rating(string Rat){
    rating = Rat;
}
void movie::increment_count(){
    watched++;
}