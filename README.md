# 🔐 initAuthorization

[![Arduino Library Manager](https://img.shields.io/badge/Arduino-Library_Manager-00979D.svg?logo=arduino&logoColor=white)](https://docs.arduino.cc/libraries/initAuthorization/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub release](https://img.shields.io/github/v/release/milad-nikpendar/initAuthorization)](https://github.com/milad-nikpendar/initAuthorization/releases)
[![Author](https://img.shields.io/badge/Author-milad--nikpendar-blueviolet)](https://github.com/milad-nikpendar)

A lightweight ESP32 library for securely storing and verifying a device’s **Chip ID** in NVS, ensuring that only authorized hardware can run your application.

---

## ✨ Features
- **Automatic First-Time Registration** – Stores the current Chip ID if none exists.
- **Secure Verification** – Compares stored ID with the current device’s ID on each boot.
- **Unauthorized Device Lockout** – Stops execution if the device is not recognized.
- **Persistent Storage** – Uses ESP32’s `Preferences` (NVS) to store data across resets.

---

## 🚀 Usage Example

The following example shows how to:
1. Retrieve the ESP32’s **Chip ID**.
2. Use the `Authorization` class to register or verify the device.

```cpp
#include <Arduino.h>
#include <initAuthorization.h>

Authorization auth;

String getChipID()
{
    uint64_t chipid = ESP.getEfuseMac(); // Unique 64-bit ID
    char idStr[17];
    sprintf(idStr, "%04X%08X",
            (uint16_t)(chipid >> 32),
            (uint32_t)chipid);
    return String(idStr);
}

void setup()
{
    Serial.begin(115200);
    delay(1000);

    String chipID = getChipID();
    Serial.print("Device Chip ID: ");
    Serial.println(chipID);

    // Check authorization
    if (auth.check(chipID))
    {
        Serial.println("✅ Device authorized. Running application...");
    }
    // If unauthorized, the library will halt execution
}

void loop()
{
    // Your main code here
}
```

---

## 🛠 API Reference

### `bool check(const String &chip_ID)`
Checks if the given Chip ID matches the stored one.  
If no ID is stored, it will register the provided one.

### `bool check(const char* chip_ID)`
Same as above, but accepts a C-style string.

### `bool check(const std::string &chip_ID)`
Same as above, but accepts a `std::string`.

---

## 🧾 License

This project is licensed under the **MIT License** – see [LICENSE](LICENSE) for details.

## ✍️ Author

**Milad Nikpendar**  
GitHub: [milad-nikpendar/initMemory](https://github.com/milad-nikpendar/initAuthorization)  
Email: milad82nikpendar@gmail.com  
