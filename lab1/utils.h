#ifndef UTILS_H_
#define UTILS_H_

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#include "athlete.h"

/**
 * Generates random string
 * @param length length of the string
 * @return generated string
 */
std::string randomString(int length) {
    const std::string chars = "abcdefghijklmnopqrstuvwxyz";

    std::string result;
    for (int i = 0; i < length; ++i)
        result += chars[rand() % chars.size()];
    return result;
}


/**
 * Generates file of athletes data
 * @param filename name of the file to save 
 * @param total number of lines of data
 */
void generateAthletesCSV(const std::string& filename, int total = 101000) {
    const std::string sports[] = {"Football", "Basketball", "Tennis", "Swimming", "Running"};
    int numSport = 5;

    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (int i = 0; i < total; ++i) {
        std::string name = randomString(5 + rand() % 5);
        int age    = 18  + rand() % 23;
        int height = 160 + rand() % 41;
        int weight = 50  + rand() % 51;
        std::string sport = sports[rand() % numSport];

        file << name << "," << age << "," << height << "," << weight << "," << sport << "\n";
    }

    file.close();
}


/**
 * Fill array with Athlete objects
 * @param arr array to fill
 * @param n number of athletes
 * @param filename name of the file to read
 */
void fillAthleteArray(Athlete* arr, int n, const std::string& filename = "athletes.csv") {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    int count = 0;

    while (count < n && std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, ageStr, heightStr, weightStr, sport;

        std::getline(ss, name, ',');
        std::getline(ss, ageStr, ',');
        std::getline(ss, heightStr, ',');
        std::getline(ss, weightStr, ',');
        std::getline(ss, sport);

        int age    = std::stoi(ageStr);
        int height = std::stoi(heightStr);
        int weight = std::stoi(weightStr);

        arr[count++] = Athlete(name, age, height, weight, sport);
    }

    file.close();
}

#endif