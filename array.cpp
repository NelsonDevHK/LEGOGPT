#include "array.h"

DataMap::DataMap()
{
    arraySize = 0;
    keys = nullptr;
    values = nullptr;
}

DataMap::~DataMap()
{
    clear();
}

void DataMap::insert(const string &key, const string &value)
{
    // Check if the key already exists
    for (int i = 0; i < arraySize; i++) {
        if (keys[i] == key) {
            values[i] = value;
            return;
        }
    }
    
    // Key doesn't exist, so create a new entry
    string *newKeys = new string[arraySize + 1];
    string *newValues = new string[arraySize + 1];
    
    for (int i = 0; i < arraySize; i++) {
        newKeys[i] = keys[i];
        newValues[i] = values[i];
    }
    
    newKeys[arraySize] = key;
    newValues[arraySize] = value;
    
    delete[] keys;
    delete[] values;
    
    keys = newKeys;
    values = newValues;
    arraySize++;
}

string DataMap::find(const string &key) const
{
    for (int i = 0; i < arraySize; i++) {
        if (keys[i] == key) {
            return values[i];
        }
    }
    
    return "";
}

void DataMap::clear()
{
    delete[] keys;
    delete[] values;
    arraySize = 0;
    keys = nullptr;
    values = nullptr;
}
