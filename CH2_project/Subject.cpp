#include "Subject.h"


void Subject::Attach(const shared_ptr<IObserver>& observer) {
    observers.push_back(observer);
}

void Subject::Detach(const shared_ptr<IObserver>& observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::NotifyHP(int HP, int change, bool isHeal) {
    for (const auto& observer : observers) {
        observer->updateHP(HP, change, isHeal);
    }
}
