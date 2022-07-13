#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Vector
{
public:
	int X;
	int Y;
};

int main()
{
	int Map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 1, 0, 1},
		{1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	queue<Vector> SavePosition;

	Vector PlayerPosition = { 1, 1 };

	int Value = -1;
	Map[PlayerPosition.Y][PlayerPosition.X] = Value;

	SavePosition.push(PlayerPosition);
	while (!SavePosition.empty())
	{
		Vector QueuePosition = SavePosition.front();
		SavePosition.pop();

		//Right
		if (Map[QueuePosition.Y][QueuePosition.X + 1] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.X++;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
		//Down
		if (Map[QueuePosition.Y + 1][QueuePosition.X] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.Y++;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
		//Left
		if (Map[QueuePosition.Y][QueuePosition.X - 1] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.X--;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
		//Up
		if (Map[QueuePosition.Y - 1][QueuePosition.X] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.Y--;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
	}

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			printf("%5d", Map[Y][X]);
		}

		cout << endl;
	}

	if (Map[8][8] >= 0)
	{
		cout << "No Escape" << endl;
		return 0;
	}


	stack<Vector> StackPosition;
	PlayerPosition = { 8, 8 };
	int i = Map[8][8];

	StackPosition.push(PlayerPosition);

	while (Map[PlayerPosition.Y][PlayerPosition.X] != -1)
	{
		//Right
		if (Map[PlayerPosition.Y][PlayerPosition.X + 1] == i)
		{
			PlayerPosition.X++;
			StackPosition.push(PlayerPosition);
		}
		//Down
		else if (Map[PlayerPosition.Y + 1][PlayerPosition.X] == i)
		{
			PlayerPosition.Y++;
			StackPosition.push(PlayerPosition);
		}
		//Left
		else if (Map[PlayerPosition.Y][PlayerPosition.X - 1] == i)
		{
			PlayerPosition.X--;
			StackPosition.push(PlayerPosition);
		}
		//Up
		else if (Map[PlayerPosition.Y - 1][PlayerPosition.X] == i)
		{
			PlayerPosition.Y--;
			StackPosition.push(PlayerPosition);
		}

		i++;
	}

	while (!StackPosition.empty())
	{
		cout << StackPosition.top().X << "," << StackPosition.top().Y << endl;
		StackPosition.pop();
	}

	return 0;
}