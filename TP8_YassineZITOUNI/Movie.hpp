#ifndef MOVIE
#define MOVIE

#include <string>
using namespace std;
class movie{
    private:
        string name;
        string rating;
        int watched;
    public:
        string get_name();
        string get_rating();
        int get_watched();
        void display_info();
        void set_name(string Name);
        void set_rating(string Rat);
        void increment_count();
        movie(string name, string rating, int watched);
};
#endif