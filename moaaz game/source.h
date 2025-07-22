#pragma once



#include<cstdlib>
#include<iostream>

enum cmpchoice { rock = 1, paper, scissor };
struct scores
{
	int wins;
	int loses;
	int ties;
};
extern scores user_points;

cmpchoice randomchoice();