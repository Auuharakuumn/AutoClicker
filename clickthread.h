#ifndef CLICKTHREAD_H
#define CLICKTHREAD_H

#include <QObject>
#include <QThread>

#define DEFAULT_CLICK_DELAY 10
#define DEFAULT_CLICK_BUTTON left_click

enum buttons {
    left_click,
    right_click
};

class ClickThread : public QThread {
    int delay;
    buttons button;

protected:
    void run() override;
    virtual void click_loop() = 0;

public:
    ClickThread(QObject *parent = NULL, int delay, buttons button);
    ClickThread(QObject *parent = NULL);
    int getDelay() const;
};

#if defined(_WIN32)

#include "windowsclickthread.h"
#define PlatformClickThread WindowsClickThread

#elif defined(__linux__)

#include "linuxclickthread.h"
#define PlatformClickThread LinuxClickThread

#else

#error "Platform not supported"

#endif

#endif // CLICKTHREAD_H
