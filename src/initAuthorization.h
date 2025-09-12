/*
   initAuthorization library V1.0.1
   Created by Milad Nikpendar
*/
#ifndef INIT_AUTHORIZATION_H
#define INIT_AUTHORIZATION_H

#include <Arduino.h>
#include <Preferences.h>
#include <string>

class Authorization
{
public:
    bool check(const std::string &chip_ID); // Check using std::string
    bool check(const char *chip_ID);        // Check using const char*
    bool check(const String &chip_ID);      // Check using String

private:
    Preferences Parameter; // Preferences object for storing chip ID

    void begin() { Parameter.begin("System", false); } // Open Preferences in read-write mode
    void end() { Parameter.end(); }                    // Close Preferences

    bool checkInternal(const String &chip_ID); // Internal check function
};
#endif // INIT_AUTHORIZATION_H
