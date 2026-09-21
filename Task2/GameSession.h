#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <memory>

#include "SnippetGenerator.h"
#include "TypingSystem.h"
#include "DamageRule.h"

using namespace std;

class GameSession
{
public:
    GameSession(
        unique_ptr<ISnippetGenerator> snippetGenerator,
        unique_ptr<ITypingSystem> typingSystem,
        unique_ptr<IDamageRule> damageRule
    );

    void StartMatch();

private:
    void StartRound();

    unique_ptr<ISnippetGenerator> snippetGenerator_;
    unique_ptr<ITypingSystem> typingSystem_;
    unique_ptr<IDamageRule> damageRule_;

    int playerHP_;
    int enemyHP_;

    int playerWins_;
    int enemyWins_;

    int round_;
};

#endif