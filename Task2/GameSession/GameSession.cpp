#include "GameSession.h"

#include <iostream>
#include <utility>

using namespace std;

GameSession::GameSession(
    unique_ptr<ISnippetGenerator> snippetGenerator,
    unique_ptr<ITypingSystem> typingSystem,
    unique_ptr<IDamageRule> damageRule
)
    : snippetGenerator_(move(snippetGenerator)),
      typingSystem_(move(typingSystem)),
      damageRule_(move(damageRule)),
      playerHP_(100),
      enemyHP_(100),
      playerWins_(0),
      enemyWins_(0),
      round_(1)
{
}

void GameSession::StartMatch()
{
    cout << "=== TYPE 'N SMASH ===\n";
    cout << "Best of 3\n\n";

    while (playerWins_ < 2 && enemyWins_ < 2)
    {
        StartRound();

        if (playerWins_ >= 2 || enemyWins_ >= 2)
        {
            break;
        }

        round_++;
    }

    cout << "\n=== MATCH RESULT ===\n";

    if (playerWins_ > enemyWins_)
    {
        cout << "Player Wins "
             << playerWins_
             << " - "
             << enemyWins_
             << "\n";
    }
    else
    {
        cout << "Enemy Wins "
             << enemyWins_
             << " - "
             << playerWins_
             << "\n";
    }
}

void GameSession::StartRound()
{
    playerHP_ = 100;
    enemyHP_ = 100;

    cout << "--- ROUND "
         << round_
         << " ---\n";

    while (playerHP_ > 0 && enemyHP_ > 0)
    {
        // 1. Generate Snippet
        Snippet snippet =
            snippetGenerator_->Generate();

        cout << "\n[SNIPPET] "
             << snippet.code
             << "\n";

        // 2. Simulate Typing
        cout << "[PLAYER] Typing...\n";

        bool correct =
            typingSystem_->ProcessTyping();

        // 3. Check Result
        if (correct)
        {
            cout << "[RESULT] Correct!\n";
        }
        else
        {
            cout << "[RESULT] Wrong!\n";
        }

        // 4. Calculate Damage
        int damage =
            damageRule_->CalculateDamage(correct);

        cout << "[DAMAGE] "
             << damage
             << "\n";

        // 5. Update HP
        enemyHP_ -= damage;

        if (enemyHP_ < 0)
        {
            enemyHP_ = 0;
        }

        cout << "[ENEMY HP] "
             << enemyHP_
             << "\n";

        // Bot attacks when typing fails
        if (!correct)
        {
            playerHP_ -= 5;

            if (playerHP_ < 0)
            {
                playerHP_ = 0;
            }

            cout << "[BOT] Attack! 5 damage\n";
            cout << "[PLAYER HP] "
                 << playerHP_
                 << "\n";
        }
    }

    // 6. Check Round Result
    if (enemyHP_ <= 0)
    {
        playerWins_++;

        cout << "\n[ROUND RESULT] Player Wins!\n";
    }
    else
    {
        enemyWins_++;

        cout << "\n[ROUND RESULT] Enemy Wins!\n";
    }

    cout << "Round Score: "
         << playerWins_
         << " - "
         << enemyWins_
         << "\n";
}