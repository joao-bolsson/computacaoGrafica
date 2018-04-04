/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#ifndef CANVASJ_COMPONENT_H
#define CANVASJ_COMPONENT_H

#include <iostream>
#include <list>
#include <algorithm>

#include "gl_canvas2d.h"

using namespace std;

class Component {

private:
    list<Component *> components;
public:

    /**
     * Render the component on screen.
     */
    virtual void draw();

    /**
     * Add a component in this component.
     * @param component Component to add.
     */
    void addComponent(Component &component);
};


#endif //CANVASJ_COMPONENT_H
