#include <memory>

#include "RunSession.h"
#include "InputGenerator.h"
#include "ScoringRule.h"
#include "RewardRule.h"

using namespace std;

int main()
{
    unique_ptr<IInputGenerator> inputGenerator =
        make_unique<FixedInputGenerator>();

    unique_ptr<IScoringRule> scoringRule =
        make_unique<SimpleScoringRule>();

    unique_ptr<IRewardRule> rewardRule =
        make_unique<SimpleRewardRule>();

    RunSession run(
        move(inputGenerator),
        move(scoringRule),
        move(rewardRule)
    );

    run.StartRun();

    return 0;
}