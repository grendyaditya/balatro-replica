#include <memory>

#include "GameSession/GameSession.h"
#include "SnippetGenerator/SnippetGenerator.h"
#include "TypingSystem/TypingSystem.h"
#include "DamageRule/DamageRule.h"

using namespace std;

int main()
{
    unique_ptr<ISnippetGenerator> snippetGenerator =
        make_unique<SimpleSnippetGenerator>();

    unique_ptr<ITypingSystem> typingSystem =
        make_unique<AutomaticTypingSystem>();

    unique_ptr<IDamageRule> damageRule =
        make_unique<SimpleDamageRule>();

    GameSession game(
        move(snippetGenerator),
        move(typingSystem),
        move(damageRule)
    );

    game.StartMatch();

    return 0;
}