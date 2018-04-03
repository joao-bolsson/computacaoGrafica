/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */

#ifndef CANVASJ_WINDOW_H
#define CANVASJ_WINDOW_H

#include "Component.h"
#include <string>

class Window : public Component {
private:
    unsigned short width, height;
    string title;

public:

    /**
     * Default construct.
     * @param width Window width.
     * @param height Window height.
     * @param title Window title.
     */
    Window(unsigned short width, unsigned short height, string title);

    /**
     * Show this window on screen.
     */
    void show();

};

#endif //CANVASJ_WINDOW_H
