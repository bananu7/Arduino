#pragma once
#include <Arduino.h>

template<int n>
struct Result {
    bool result;
    int32_t data[n];
};

template<int n>
Result<n> extractArguments(String const& str) {
    int pos = 0;
    Result<n> result;
    result.result = false;

    for (int i = 0; i < n; ++i) {
        pos = str.indexOf(" ", pos);
        if (pos == -1) {
            Serial.println("Syntax error in write_byte");
            return result;
        }
        // pos is pointing to space now
        result.data[i] = str.substring(pos + 1).toInt();
        // move pos to point to first digit
        pos += 1;
    }

    result.result = true;
    return result;
}