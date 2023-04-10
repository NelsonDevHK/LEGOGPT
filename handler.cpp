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

string HandlerModule::answer(const string &question) const {
    // Step 1: Pass question to language filter (if it exists)
    string filteredQuestion = question;
    if (languageFilter != nullptr)
        filteredQuestion = languageFilter->translatePreData(filteredQuestion);

    // Step 2: Pass "translated" question to tone filter (if it exists)
    string tonedQuestion = filteredQuestion;
    if (toneFilter != nullptr) 
        tonedQuestion = toneFilter->translatePostData(filteredQuestion);

    // Step 3: Query the data for the answer
    string answer;
    if (inneranswer(tonedQuestion) == "")
        answer = "Sorry, I don't know";
    else
        answer = inneranswer(tonedQuestion);

    // Step 4: Pass answer to tone filter (if it exists)
    string tonedAnswer = answer;
    if (toneFilter != nullptr)
        tonedAnswer = toneFilter->translatePreData(answer);

    // Step 5: Pass answer to language filter (if it exists)
    string filteredAnswer = tonedAnswer;
    if (languageFilter != nullptr)
        filteredAnswer = languageFilter->translatePostData(tonedAnswer);
    return filteredAnswer;
}


string HandlerModule::inneranswer(const string &question) const{
    return data.find(question);
}
// HandlerMap function implement
HandlerMap::HandlerMap() : arraySize(0), names(nullptr), handlerModules(nullptr){}

HandlerMap::~HandlerMap(){clear();}

void HandlerMap::insert(string key, HandlerModule *value)
{
    int index = -1;
    for (int i = 0; i < arraySize; i++)
    {
        if (names[i] == key)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        handlerModules[index] = value;
    }
    else
    {
        string *newNames = new string[arraySize + 1];
        HandlerModule **newModules = new HandlerModule *[arraySize + 1];
        for (int i = 0; i < arraySize; i++)
        {
            newNames[i] = names[i];
            newModules[i] = handlerModules[i];
        }
        newNames[arraySize] = key;
        newModules[arraySize] = value;
        delete[] names;
        delete[] handlerModules;
        names = newNames;
        handlerModules = newModules;
        arraySize++;
    }
}

HandlerModule *HandlerMap::find(const string &key) const
{
    for (int i = 0; i < arraySize; i++)
    {
        if (names[i] == key)
        { // CHECKED
            return handlerModules[i];
        }
    }
    return nullptr;
}

string HandlerMap::getNames(int index) const
{
    if (index >= 0 && index < arraySize)
    {
        return names[index];
    }
    return "";
}

void HandlerMap::clear()
{
    if (names != nullptr)
    {
        delete[] names;
        names = nullptr;
    }
    if (handlerModules != nullptr)
    {
        for (int i = 0; i < arraySize; i++)
        {
            delete handlerModules[i];
        }
        delete[] handlerModules;
        handlerModules = nullptr;
    }
    arraySize = 0;
}
