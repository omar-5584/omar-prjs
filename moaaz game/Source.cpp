#include"source.h"
#include"game.h"
void WhoWins(cmpchoice user, cmpchoice computer)
{
	if (user == cmpchoice::rock)
	{
		if (computer == rock)
		{
			user_points.ties++;

			UserStatus(userStatus::tie);
		}
		else if (computer == paper)
		{
			user_points.loses++;
		}
		else if (computer == scissor)
		{
			user_points.wins++;
		}
	}


	else if (user == cmpchoice::paper)
	{
		if (computer == paper)
		{
			user_points.ties++;
		}
		else if (computer == scissor)
		{
			user_points.loses++;
		}
		else if (computer == rock)
		{
			user_points.wins++;
		}
	}

	
	else if (user == cmpchoice::scissor)
	{
		if (computer == scissor)
		{
			user_points.ties++;
		}
		else if (computer == rock)
		{
			user_points.loses++;
		}
		else if (computer == paper)
		{
			user_points.wins++;
		}
	}
}
