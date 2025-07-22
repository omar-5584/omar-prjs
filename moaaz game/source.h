#pragma once

enum cmpchoice { rock = 1, paper, scissor };

enum userStatus { win = 1, tie , lose };

struct scores
{
	int wins;
	int loses;
	int ties;
};
extern scores user_points;

cmpchoice randomchoice();



userStatus WhoWins (cmpchoice user, cmpchoice computer);
