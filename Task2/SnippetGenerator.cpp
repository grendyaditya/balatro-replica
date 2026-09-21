#include "SnippetGenerator.h"

#include <vector>
#include <random>

using namespace std;

Snippet SimpleSnippetGenerator::Generate()
{
    static vector<string> snippets =
    {
        "print(\"Hello\")",
        "x = 10",
        "score = 100",
        "name = \"Python\"",
        "print(x)"
    };

    static random_device randomDevice;
    static mt19937 generator(randomDevice());

    uniform_int_distribution<int> distribution(
        0,
        snippets.size() - 1
    );

    return {snippets[distribution(generator)]};
}