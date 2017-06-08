
#ifndef OBJECTS_H
#define OBJECTS_H

#include <utility/list.h>
using namespace EPOS;
namespace IOT {
    //==============================================================================
    typedef Simple_List<Parameter*> Parameter_List;
    typedef List_Elements::Singly_Linked<Parameter*> Parameter_List_Element;

    typedef Simple_List<Service*> Service_List;
    typedef List_Elements::Singly_Linked<Service*> Service_List_Element;

    const char * EMPTY_STRING = "";

    class Service//DONE
    {
    public:
        Service (const char *name);

        /** Getters */
        const char* getName ();
        const Parameter_List* getParameters ();

        /** Setters */
        void setName (const char* name);
        void addParameter (Parameter* parameter);

        /** Dumper 
         * This method is responsible to output the message that represents this 
         * service. 
         **/
        const char* toString ();
    protected:
        const char *name;
        Parameter_List *parameters;
    };
    //==============================================================================

    class Smart_Object//DONE
    {
    public:
        Smart_Object (const char *name);

        /** Getters */
        const char* getName ();
        const Service_List* getServices ();

        /** Setters */
        void setName (const char *name);
        void addService (Service *service);

        /** Dumper **/
        const char* toString ();
    protected:
        const char* name;
        Service_List *services;
    };
    //==============================================================================

    class ParameterType//DONE
    {
    public:
        virtual const char* getType () = 0;
        virtual const char* getMinValue () = 0;
        virtual const char* getMaxValue () = 0;
        virtual const char* getOptions () = 0;
    };
    //==============================================================================

    class ParameterGet : public ParameterType//DONE
    {
    public:
        const char* getType ();
        const char* getMinValue ();
        const char* getMaxValue ();
        const char* getOptions ();
    };
    //==============================================================================

    class Parameter //DONE
    {
    public:
        Parameter (const char* name, const char* registerId, ParameterType *type);
        /** Getters */
        const char* getName ();
        const char* getRegisterId ();
        const char* getType ();
        const char* getMinValue ();
        const char* getMaxValue ();
        const char* getOptions ();

        /** Setters */
        void setName (const char *name);
        void setRegisterId (int registerId);
        void setType (ParameterType *type);

        /** Dumper **/
        const char* toString ();
    protected:
        const char* name;
        const char* registerId;
        ParameterType *type;
    };
    //==============================================================================

    class ParameterBoolean : public ParameterType//DONE
    {
    public:
        const char* getType ();
        const char* getMinValue ();
        const char* getMaxValue ();
        const char* getOptions ();
    };
    //==============================================================================

    class ParameterDouble : public ParameterType//DONE
    {
    public:
        ParameterDouble (const char* min, const char* max);
        const char* getType ();
        const char* getMinValue ();
        const char* getMaxValue ();
        const char* getOptions ();
    protected:
        const char *min;
        const char *max;
    };
    //==============================================================================
    typedef Simple_List<const char*> Char_List;
    typedef List_Elements::Singly_Linked<char*> Char_List_Element;

    
    class ParameterCombo : public ParameterType//DONE
    {
    public:
        ParameterCombo (const char **options, int numOptions);
        ParameterCombo (Char_List *options);
        ParameterCombo ();
        const char* getType ();
        const char* getMinValue ();
        const char* getMaxValue ();
        const char* getOptions ();
        void addOption (const char *option);
    protected:
        Char_List *options;
    };
};
#endif /* OBJECTS_H */

