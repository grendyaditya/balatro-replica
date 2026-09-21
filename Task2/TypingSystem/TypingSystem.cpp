#include "TypingSystem.h"

#include <random>

using namespace std;

bool AutomaticTypingSystem::ProcessTyping()
{
    static random_device randomDevice;
    static mt19937 generator(randomDevice());

    uniform_int_distribution<int> distribution(1, 100);

    return distribution(generator) <= 75;
}