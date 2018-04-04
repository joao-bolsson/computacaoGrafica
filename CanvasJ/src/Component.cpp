/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */

#include "Component.h"

void Component::draw() {
    for (auto c : components) {
        c->draw();
    }
}

void Component::addComponent(Component &component) {
    // TODO: verificar se o elemento já existe na lista ou se o componente é this
    components.push_back(&component);
}
