#ifndef SNIPPET_GENERATOR_H
#define SNIPPET_GENERATOR_H

#include <string>

using namespace std;

struct Snippet
{
    string code;
};

class ISnippetGenerator
{
public:
    virtual ~ISnippetGenerator() = default;
    virtual Snippet Generate() = 0;
};

class SimpleSnippetGenerator : public ISnippetGenerator
{
public:
    Snippet Generate() override;
};

#endif