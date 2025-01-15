#pragma once
#include <memory>
#include "Observer.h"

using namespace std;

class Subject {
protected:
    vector<shared_ptr<IObserver>> observers;

public:
    virtual void Attach(const shared_ptr<IObserver>& observer);

    virtual void Detach(const shared_ptr<IObserver>& observer);

    virtual void NotifyHP(int HP, int change, bool isHeal) = 0;

    virtual ~Subject() {}
};

