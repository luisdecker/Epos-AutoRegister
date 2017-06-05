/* 
 * File:   IoTManager.h
 * Author: decker
 *
 * Created on June 3, 2017, 6:59 PM
 */

/*
 * This is a IoT metadata manager.
 * It is responsible of the creation of a IoThing descriptor that will be used 
 * to the registration of a IoThing in a IoT network. 
 * */
#ifndef IOTMANAGER_H
#define IOTMANAGER_H

#include "system/config.h"
#include "utility/list.h"


__BEGIN_SYS
        namespace IoT {
    typedef Simple_List<IoT_Element> IoTList;
    typedef List_Elements::Singly_Linked<IoT_Element> ListElement;

    enum data_type
    {
        INTEGER = 1,
        UNSIGNED_INTEGER = 2,
        SHORT = 3,
        UNSIGNED_SHORT = 4,
        FLOAT = 5,
        UNSIGNED_FLOAT = 6,
        DOUBLE = 7,
        CHAR = 8,
        UNSIGNED_CHAR = 9
    };

    class IoT_Manager
    {
    private:
        //List of avaible IoT Elements (functions and sensoring)
        IoTList _elements;
    public:

        IoT_Manager () { }

        void addElement (IoT_Element & newElement);
        void removeElement (IoT_Element & removalElement);


    };
};
__END_SYS
#endif /* IOTMANAGER_H */

//==============================================================================
/*
 * This is a IOT element.
 * It has a description, that gonna be sent to the sink in the registration process.
 * It has a Unit, that is the sender or accepted parameter type (int, double, bool...)
 * 
 */

#ifndef IOTELEMENT_H
#define IOTELEMENT_H

__BEGIN_SYS
        namespace IoT {

    class IoT_Element
    {
    public:

        IoT_Element (data_type data_t, char * description) :
        _data_type (data_t), _description (description) { }

    protected:
        data_type _data_type; //Datatype of the element
        char * _description; //Element description (to be sent to IoT server)
    };
}
__END_SYS
#endif//IOTELEMENT_H
//==============================================================================

/*
 * This is a Actuator IoT element. 
 * A Actuator is a function of the IoT object.
 * It has a Parameter Range, that is the range of accepted parameters ([1,10], [true,false], [0.5,1.5] ...)
 * It has a actuation method, a void method with a single parameter (Multiple parameters = Multiple A.E.)
 */
#ifndef ACTUATORELEMENT_H
#define ACTUATORELEMENT_H

__BEGIN_SYS
        namespace IoT {

    template<class type>
    class IoT_Actuator_Element : private IoT_Element
    {
        friend class IoT_Manager;
    public:

        IoT_Actuator_Element (data_type data_t, char* description, void (*actuate)(type), type range_minimum, type range_maximum) :
        IoT_Element (data_t, description), _range_maximum (range_minimum), _range_maximum (range_maximum) {
            this->_actuate = actuate;
        }

    private:
        void _actuate (type); //The actuate function

        type _range_minimum;
        type _range_maximum;





    };
};
__END_SYS
#endif /* ACTUATORELEMENT_H */
//==============================================================================
