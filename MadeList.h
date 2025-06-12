#pragma once
#include "MadeScore.h"
#include <fstream>
//#include <unordered_map>

namespace ML
{
	class MadeList
	{
	private:
		//Initial List that imports in ALL data from JSON
		std::unordered_map<std::string, MS::MadeScore> ScoreList;

	public:
		MadeList();
		
		void ImportList();
		void ExportList();
		
		std::unordered_map<std::string, MS::MadeScore> SortList(std::unordered_map<std::string, MS::MadeScore> unsorted);

		//Test Functions
		void AddToList(std::string title, MS::MadeScore score);

		//Display Functions
		void DisplayList();
	};
}

