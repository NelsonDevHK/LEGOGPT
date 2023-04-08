#include "filter.h"

FilterModule::~FilterModule(){

}
void FilterModule::print() const{
    std::cout << "Module name = " << m_name << ", this is a filter, filter type = " << getType() << std::endl;
}

void FilterModule::trainPreData(const string &source, const string &target){

}
void FilterModule::trainPostData(const string &source, const string &target){

}
string FilterModule::translatePreData(string question) const{

}
string FilterModule::translatePostData(string question) const{

}

//Class FilterArray function
void FilterArray::insert(FilterModule *input)
{
    FilterModule **newArray = new FilterModule *[arraySize + 1];
    for (int i = 0; i < arraySize; i++)
    {
        newArray[i] = array[i];
    }
    newArray[arraySize] = input;
    delete[] array;
    array = newArray;
    arraySize++;
}

FilterModule *FilterArray::get(int index) const
{
    if (index >= 0 && index < arraySize)
    {
        return array[index];
    }
    return nullptr;
}
