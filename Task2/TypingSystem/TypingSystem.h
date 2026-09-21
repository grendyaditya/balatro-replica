#ifndef TYPING_SYSTEM_H
#define TYPING_SYSTEM_H

#include "../SnippetGenerator/SnippetGenerator.h"

using namespace std;

class ITypingSystem
{
public:
    virtual ~ITypingSystem() = default;
    virtual bool ProcessTyping() = 0;
};

class AutomaticTypingSystem : public ITypingSystem
{
public:
    bool ProcessTyping() override;
};

#endif