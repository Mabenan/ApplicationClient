#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <Button.h>



class CloseButton : public Button
{
    Q_OBJECT
public:
    CloseButton(QObject * parent = nullptr);

    // Button interface
public:
    void clicked() override;
    const QString name() override;
};

#endif // CLOSEBUTTON_H
