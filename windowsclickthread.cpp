#include "windowsclickthread.h"

WindowsClickThread::WindowsClickThread(QObject *parent, int delay, buttons button) :
    ClickThread(parent, delay, button)
{

}

WindowsClickThread::WindowsClickThread(QObject *parent) : ClickThread(parent) {

}

WindowsClickThread::click_loop() {
    INPUT input;

    input.type = 0; // Mouse event

    input.mi.dx = 0;
    input.mi.dy = 0;
    input.mi.mouseData = 0;
    input.mi.dwExtraInfo = NULL;
    input.mi.time = 0;

    switch (this->button) {
        case left_click:
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
            break;
        case right_click:
            input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
            break;
        default:
            input.mi.dwFlags = 0;
    }

    while (this->isRunning()) {
        SendInput(1, &input, sizeof(input));

        this->msleep(this->delay);
    }
}
