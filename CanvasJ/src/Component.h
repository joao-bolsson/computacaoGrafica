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
    // TODO: essa lista precisa ser um ponteiro?
    list<Component *> components;
public:
    /**
     * Default component construct.
     */
    Component();

    /**
     * Component destructor.
     */
    ~Component();

    /**
     * Render the component on screen.
     */
    virtual void draw();

    /**
     * Add a component in this component.
     * @param component Component to add.
     */
    void addComponent(Component &component);

    /**
     * Remove a component of this component.
     * @param component Component to remove.
     */
    void removeComponent(Component &component);
};


#endif //CANVASJ_COMPONENT_H
