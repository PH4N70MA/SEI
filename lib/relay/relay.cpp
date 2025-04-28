#include "relay.h"

Relay::Relay(uint8_t id, const char* name, uint8_t pin, RelayState state)
{
    __id = id;
    __name = name;
    __pin = pin;
    __state = state;

    pinMode(__pin, OUTPUT);
    digitalWrite(__pin, __state);
}

void Relay::set(RelayState state)
{
    __state = state;
    digitalWrite(__pin, __state);
}

//Functia returneaza 1 daca a schimbat starea si 0 data a ramas aceasi stare
bool Relay::control(RelayControl command)
{
    //Enable Control
    if(command == ENABLE && !__state)
    {
        set(ENABLED);
        return SET;
    }
    else if(command == ENABLE && __state)
    {
        return NOTSET;
    }
    //Disble Control
    if(command == DISABLE && __state)
    {
        set(DISABLED);
        return SET;
    }
    else if(command == DISABLE && !__state)
    {
        return NOTSET;
    }
    //Toggle Control
    if(command == TOGGLE)
    {
        set((__state == ENABLED) ? DISABLED : ENABLED);
        return SET;
    }
    return NOTSET;
}

RelayState Relay::getState()
{
    return __state;
}

const char *Relay::getName()
{
    return __name;
}

uint8_t Relay::getPin()
{
    return __pin;
}