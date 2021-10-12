// YOUR NAME: Thanh Long Le
//
// CS 4318, spring 2021
// Agent Challenge 1: Rock, paper, scissors
//
// Rename this file and the function below.  For example, if your agent name
// is Jones, rename this rpsAgentSmith.cpp file to rpsAgentJones.cpp and the
// rpsAgentSmith function below to rpsAgentJones.  Complete your agent
// function and turn it in on Blackboard.  Feel free to create other
// agents--each in a separate .cpp file--for yours to compete against, but
// turn in only one.  Test your agent(s) with
//
//    nice bash rpsBuild.bash
//
// and then
//
//    nice ./rpsRunSim
//
// Each submitted agent will play each other in contests of some number of
// rounds each (at least 100) to determine the standings, which will be
// posted soon after the agents are due.

#include "rps.h"

// Rename and complete this agent function.
handsign rpsAgentJackie(const vector<handsign> focal, const vector<handsign> opponent)
{
   // Your function must end up returning rock, paper or scissors.
   // Number of choices made by you so far: focal.size()
   //    (You may assume that focal.size() and opponent.size() are equal.)
   // Last choice made by you: focal.back() (or focal.at(focal.size() - 1))
   // Second-to-last choice made by you: focal.at(focal.size() - 2)
   // Third-to-last choice made by you: focal.at(focal.size() - 3)
   //    etc.
   // Last choice made by your opponent: opponent.back() (or opponent.at(focal.size() - 1))
   // Second-to-last choice made by your opponent: opponent.at(focal.size() - 2)
   //    etc.

	// Replace this return statement with your agent code.
	int oSize = opponent.size();
	int rNumb;
	
	// for the first 2 rounds
	// or for every 5 rounds
	// play it statistically randomly (source: Prof. LeGrand)
	// => increase defense, decrease pattern
	if (oSize <= 1 || (oSize + 1) % 5 == 0)
	{
		rNumb = randomInt(100);
		if (rNumb < 33)
		   return rock;
	   
		if (rNumb < 84)
			return paper;
		
		return scissors;
	}
	
	// read the last 2 round of the opponent to predict
	// if they are the same => in the next round, others
	// will most likely play counter to the previous
	// I will just play more likely to play the same as their last rounds
	if (opponent.at(oSize - 1) == opponent.at(oSize - 2))
	{
		rNumb = randomInt(100);	// calculate random for 100% of probability
		
		// if they are rock
		// => rock = 70%, paper = 20% = scissors = 10%
		if (opponent.back() == rock)	
		{
			if (rNumb < 70)
				return rock;
			
			if (rNumb < 90)
				return paper;
			
			return scissors;
		}
		
		// if they are paper
		// => rock = 10%, paper = 60%, scissors = 30%
		if (opponent.back() == paper)
		{
			if (rNumb < 10)
				return rock;
			
			if (rNumb < 70)
				return paper;
			
			return scissors;
		}
		
		// if they are scissors
		// => rock = 30%, paper = 20%, scissors = 50%
		if (opponent.back() == scissors)	// if they are scissors
		{
			if (rNumb < 30)
				return rock;
			
			if (rNumb < 50)
				return paper;
			
			return scissors;
		}
	}
	
	// when the 2 last 2 rounds are different
	// more likely to be other one in the next round
	
	rNumb = randomInt(100);	// calculate random for 100% of probability
	
	// if they are rock and paper
	if ((opponent.at(oSize - 1) == rock && opponent.at(oSize - 2) == paper) || (opponent.at(oSize - 1) == paper && opponent.at(oSize - 2) == rock))
	{
		// the probability of scissor will be higher => counter by more rock
		// rock = 70%, paper = scissor = 15%
		if (rNumb < 70)
			return rock;
		
		if (rNumb < 85)
			return paper;
	
		return scissors;
	}
	
	// if they are rock and scissors
	else if ((opponent.at(oSize - 1) == rock && opponent.at(oSize - 2) == scissors) || (opponent.at(oSize - 1) == scissors && opponent.at(oSize - 2) == rock))
	{
		// the probability of paper will be higher => counter by more scissors
		// rock = 30%, paper = 10%, scissors = 60%
		if (rNumb < 30)
			return rock;
		
		if (rNumb < 40)
			return paper;
		
		return scissors;
	}
	
	// if they are paper and scissors
	// the probability of rock will be higher => counter by more paper
	// rock = 25%, paper = 50%, scissors = 25%
	if (rNumb < 25)
		return rock;
		
	if (rNumb < 75)
		return paper;
	
	return scissors;	
}

/*

 - First, carefully comment your code above to clarify how it works.
 - Here, describe your approach and analyze it.  How exactly did you develop
   and test it?  What are its strengths and weaknesses?  Why do you expect
   it to do well against the other submitted agents?
 - Also make a note here if you talked about the assignment with anyone or
   gave or received any kind of help.

*/
