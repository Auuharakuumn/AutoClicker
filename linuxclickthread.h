#ifndef LINUXCLICKTHREAD_H
#define LINUXCLICKTHREAD_H

#include "clickthread.h"

#error "Linux clicker not implemented yet."

class LinuxClickThread : public ClickThread
{
public:
    LinuxClickThread(QObject *parent = NULL, int delay, buttons button);
    LinuxClickThread(QObject *parent = NULL);

protected:
    void click_loop() override;
};

#endif // LINUXCLICKTHREAD_H
