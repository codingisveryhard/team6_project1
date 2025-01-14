#pragma once
#include <vector>
#include <string>
#include <algorithm>

class IObserver {
public:
	virtual ~IObserver() = default;
	virtual void Update(int HP) = 0;
};

