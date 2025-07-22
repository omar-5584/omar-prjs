#include"source.h"
#include"game.h"
scores user_points;
userStatus WhoWins(cmpchoice user, cmpchoice computer)
{
	if (user == cmpchoice::rock)
	{
		if (computer == rock)
		{
			user_points.ties++;

			return userStatus::tie;
		}
		else if (computer == paper)
		{
			user_points.loses++;
			return userStatus::lose;
		}
		else if (computer == scissor)
		{
			user_points.wins++;
			return userStatus::win;
		}
	}


	else if (user == cmpchoice::paper)
	{
		if (computer == paper)
		{
			user_points.ties++;
			return userStatus::tie;
		}
		else if (computer == scissor)
		{
			user_points.loses++;
			return userStatus::lose;
		}
		else if (computer == rock)
		{
			user_points.wins++;
			return userStatus::win;
		}
	}

	
	else if (user == cmpchoice::scissor)
	{
		if (computer == scissor)
		{
			user_points.ties++;
			return userStatus::tie;
		}
		else if (computer == rock)
		{
			user_points.loses++;
			return userStatus::lose;
		}
		else if (computer == paper)
		{
			user_points.wins++;
			return userStatus::win;
		}
	}
}

cmpchoice randomchoice()
{
    return cmpchoice((rand() % 3) + 1);
}