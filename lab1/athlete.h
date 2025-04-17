#ifndef ATHLETE_H_
#define ATHLETE_H_

#include <string>


/// @brief Athlete Class
class Athlete {
public:
    std::string name;
    int age;
    int height;
    int weight;
    std::string sport;

public:
    /// @brief Default constructor
    Athlete() {}
    /**
     * Constructor
     * 
     * @param n name
     * @param a age
     * @param h height
     * @param w weight
     * @param s sport
     */
    Athlete(const std::string& n, int a, int h, int w, const std::string& s):
        name(n), age(a), height(h), weight(w), sport(s) {}
    /// @brief Destructor
    ~Athlete() {}

    /// @brief overloading equal
    bool operator==(const Athlete& other) {
        return sport == other.sport &&
               name  == other.name  &&
               age   == other.age;
    }

    /// @brief overloading less
    bool operator<(const Athlete& other) {
        if ( sport != other.sport )
            return sport < other.sport;
        if ( name != other.name )
            return name < other.name;
        return age < other.age;
    }

    /// @brief overloading not equal
    bool operator!=(const Athlete& other) { return !(*this == other);              }
    /// @brief overloading less or equal
    bool operator<=(const Athlete& other) { return *this == other || *this < other; }
    /// @brief overloading greater
    bool operator> (const Athlete& other) { return !(*this <= other);              }
    /// @brief overloading greater or equal
    bool operator>=(const Athlete& other) { return *this > other || *this == other; }
};

#endif