#include "handler.h"
//Todo 2
HandlerModule::~HandlerModule()
{
    delete this->languageFilter;
    delete this->toneFilter;
}

void HandlerModule::print() const
{
    std::cout << "Module name = " << m_name << ", this is a Handler, can handle topic = " << topic << std::endl;
}

//Todo 3
void HandlerModule::trainData(const string &question, const string &answer)
{
    data.insert(question, answer);
}

string HandlerModule::answer(const string &question) const
{
 
}

// HandlerMap function implement
HandlerMap::HandlerMap(){
    
}
HandlerMap::~HandlerMap(){
    
}
void HandlerMap::insert(string key, HandlerModule *value){

}
HandlerModule* HandlerMap::find(const string &key) const{

}
string HandlerMap:: getNames(int index) const{

}
void HandlerMap::clear(){}