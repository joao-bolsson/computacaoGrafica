/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */

#include "Component.h"

Component::Component() {
    // do nothing
}

Component::~Component() {
    // do nothing
}

void Component::draw() {
    for (auto c = components->begin(); c != components->end(); c++) {
        (*c)->draw();
    }
}

void Component::addComponent(Component &component) {
    // TODO: verificar se o elemento já existe na lista ou se o componente é this
    components->push_back(&component);
}

void Component::removeComponent(Component &component) {
    components->remove(&component);
}

