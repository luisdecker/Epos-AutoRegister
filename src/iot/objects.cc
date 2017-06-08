#include <iot/objects.h>
using namespace EPOS;
using namespace IOT;

//==============================================================================

Service::Service(const char* name) {
    this->name = name;
}

const char* Service::getName() {
    return this->name;
}

void Service::setName(const char* name) {
    this->name = name;
}

const Parameter_List* Service::getParameters() {
    return this->parameters;
}

void Service::addParameter(Parameter* parameter) {
    Parameter_List_Element new_element(parameter);
    this->parameters->insert(new_element);
}

const char* Service::toString() {
    //TODO
}
//==============================================================================

Smart_Object::Smart_Object(const char* name) {
    this->name = name;
}

const char* Smart_Object::getName() {
    return this->name;
}

void Smart_Object::setName(const char* name) {
    this->name = name;
}

const Service_List* Smart_Object::getServices() {
    return this->services;
}

void Smart_Object::addService(Service* service) {
    Service_List_Element new_service(service);
    this->services->insert(new_service);
}

const char* Smart_Object::toString() {
    //TODO
}

//==============================================================================

const char * ParameterGet::getType() {
    return "get";
}

const char * ParameterGet::getMaxValue() {
    return EMPTY_STRING;
}

const char * ParameterGet::getMinValue() {
    return EMPTY_STRING;
}

const char * ParameterGet::getOptions() {
    return EMPTY_STRING;
}
//==============================================================================

Parameter::Parameter(const char* name, const char* registerId, ParameterType* type) {
    this->name = name;
    this->registerId = registerId;
    this->type = type;
}

const char* Parameter::getName() {
    return this->name;
}

const char* Parameter::getRegisterId() {
    return this->registerId;
}

const char* Parameter::getType() {
    return this->type->getType();
}

const char* Parameter::getMinValue() {
    return this->type->getMinValue();
}

const char* Parameter::getMaxValue() {
    return this->type->getMaxValue();
}

const char* Parameter::getOptions() {
    return this->type->getOptions();
}

void Parameter::setName(const char* name) {
    this->name = name;
}

void Parameter::setRegisterId(int registerId) {
    this->registerId = registerId;
}

void Parameter::setType(ParameterType* type) {
    this->type = type;
}

const char* Parameter::toString() {
    //TODO
}

//==============================================================================

const char* ParameterBoolean::getType() {
    return "boolean";
}

const char* ParameterBoolean::getMaxValue() {
    return EMPTY_STRING;
}

const char* ParameterBoolean::getMinValue() {
    return EMPTY_STRING;
}

const char* ParameterBoolean::getOptions() {
    return EMPTY_STRING;
}

//==============================================================================

ParameterDouble::ParameterDouble(const char* min, const char* max) {
    this->min = min;
    this->max = max;
}

const char* ParameterDouble::getType() {
    return "double";
}

const char* ParameterDouble::getMinValue() {
    return min;
}

const char* ParameterDouble::getMaxValue() {
    return max;
}

const char* ParameterDouble::getOptions() {
    return EMPTY_STRING;
}
//==============================================================================

ParameterCombo::ParameterCombo(const char** options, int numOptions) {
    this->options = new Char_List();
    for (int i = 0; i < numOptions; i++) {
        Char_List_Element new_element(options[i]);
        this->options->insert(new_element);
    }
}

ParameterCombo::ParameterCombo(Char_List* options) {
    this->options = options;
}

ParameterCombo::ParameterCombo() {
    this->options = new Char_List();
}

const char* ParameterCombo::getType() {
    return "combo";
}

const char* ParameterCombo::getMinValue() {
    return EMPTY_STRING;
}

const char* ParameterCombo::getMaxValue() {
    return EMPTY_STRING;
}

const char* ParameterCombo::getOptions() {
    //TODO
}

void ParameterCombo::addOption(const char* option) {
    Char_List_Element new_option(option);
    this->options->insert(new_option);
}










