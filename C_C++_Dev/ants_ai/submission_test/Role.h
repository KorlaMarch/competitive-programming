#ifndef ROLE_H_
#define ROLE_H_

#include "State.h"

struct Role{
    State& state;
    Role(State _state) : state(_state) {}
    virtual void move(Location loc) = 0;
    private:
        int id;
};

#endif
