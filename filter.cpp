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
FilterModule* FilterArray::get(int index) const{
    
}