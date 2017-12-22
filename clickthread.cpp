#include "clickthread.h"

ClickThread::ClickThread(QObject *parent, int delay, buttons button) : QThread(parent) {
    this->delay = delay;
    this->button = button;
}

ClickThread::ClickThread(QObject *parent) : ClickThread(parent, DEFAULT_CLICK_DELAY, DEFAULT_CLICK_BUTTON) {

}



int ClickThread::getDelay() const {
    return this->delay;
}

void ClickThread::run() {
    click_loop();
}
