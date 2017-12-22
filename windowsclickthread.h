#ifndef WINDOWSCLICKTHREAD_H
#define WINDOWSCLICKTHREAD_H

#include <windows.h>

#include "clickthread.h"

class WindowsClickThread : public ClickThread {
public:
    WindowsClickThread(QObject *parent = NULL, int delay, buttons button);
    WindowsClickThread(QObject *parent = NULL);

protected:
    void click_loop() override;
};

#endif // WINDOWSCLICKTHREAD_H
