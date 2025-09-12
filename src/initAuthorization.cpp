#include "initAuthorization.h"

bool Authorization::checkInternal(const String &chip_ID)
{
    begin();    // Open Preferences

    // If no chip ID is stored, save the current one
    if (!Parameter.isKey("chip-ID"))
    {
        Serial.println("✅ System authorization registered.");
        Parameter.putString("chip-ID", chip_ID);
        end();
        return true;
    }

    size_t len = Parameter.getBytesLength("chip-ID");
    if (len <= 0) {
        Serial.println("✅ System authorization registered.");
        Parameter.putString("chip-ID", chip_ID);
        end();
        return true;
    }
    
    // Retrieve and compare the stored chip ID
    String storedID = Parameter.getString("chip-ID", "");
    end();

    // If they match, authorization is successful
    if (storedID == chip_ID)
        return true;

    Serial.println("❌ Unauthorized device detected!");
    return false;
}

// Check authorization using const String&
bool Authorization::check(const String &chip_ID)
{
    return checkInternal(chip_ID);
}
 
// Check authorization using const char*
bool Authorization::check(const char* chip_ID)
{
    return checkInternal(String(chip_ID));
}

// Check authorization using std::string
bool Authorization::check(const std::string &chip_ID)
{
    return checkInternal(String(chip_ID.c_str()));
}
