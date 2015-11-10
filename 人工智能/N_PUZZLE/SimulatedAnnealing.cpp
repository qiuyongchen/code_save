#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing()
{
}

SimulatedAnnealing::~SimulatedAnnealing()
{
}

SimulatedAnnealing::SimulatedAnnealing(CHESS_STATE chessState)
{
	initState = chessState;
	stateGenerated = 0;
}

// ��ʼģ���˻�
CHESS_STATE SimulatedAnnealing::climbing(double temperator_, double sche)
{
	stateGenerated = 0;
	CHESS_STATE currentState = initState;
	CHESS_STATE newState;

	double temperator = temperator_;
	double d;
	double probability;
	double randProbability;

	while (currentState.evalution != 0 && temperator > 0)
	{
		// ���ѡ��һ����״̬
		newState = currentState.getRandomState();
		stateGenerated++;

		d = currentState.evalution - newState.evalution;
		if (d > 0)
		{
			currentState = newState;
		}
		else
		{
			probability = exp(d / temperator);

			randProbability = random(10000) / 10000.0;
			// ������ʰٷְ٣���ô0��1֮�ڵ������У�
			// �������ֻ�аٷ�֮ʮ����ô0��0.1֮�ڵ�������
			if (randProbability <= probability)
			{
				currentState = newState;
			}
		}

		temperator -= sche; // ���˻�
	}
	return currentState;
}
