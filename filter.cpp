#include "filter.h"

FilterModule::~FilterModule(){
  this->preData.~DataMap();
  this->postData.~DataMap();
}
void FilterModule::print() const{
    std::cout << "Module name = " << m_name << ", this is a filter, filter type = " << getFilterType(type) << std::endl;
}

void FilterModule::trainPreData(const string &source, const string &target) {
  preData.insert(source, target);
}

void FilterModule::trainPostData(const string &source, const string &target) {
  postData.insert(source, target);
}

string FilterModule::translatePreData(string question) const {
  return preData.find(question);
}

string FilterModule::translatePostData(string answer) const {
  return postData.find(answer);
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
