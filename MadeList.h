#pragma once
#include "MadeScore.h"
#include <fstream>

namespace ML
{
	class MadeList
	{
	private:
		//Initial List that imports in ALL data from JSON
		//INIT is the initial unsorted list that could have MULTIPLE entries of the same title
		//SORT is the sorted list (per user's filters/preferences) and has no duplicates AND AGGREGATE SCORES
		std::vector<MS::MadeScore> GameList_INIT, GameList_SORT;

	public:
		MadeList();
		
		void ImportList();
		void ExportList();
		void GradeList();
		void SortList(bool desc);
		void TransferLists();
		void CrunchList();

		//Test Functions
		void AddToList(MS::MadeScore game);

		//Display Functions
		void DisplayList();
	};
}

