#pragma once
#include "MadeScore.h"
#include <vector>
#include <fstream>

namespace ML
{
	class MadeList
	{
	private:
		//Initial List that imports in ALL data from JSON
		std::vector<MS::MadeScore> initImport;
		//Final List that is displayed to User, dynamically created
		std::vector<MS::MadeScore> displayList;

	public:
		void InitFirstList();
		std::vector<MS::MadeScore> GetInitImport() { return initImport; };
		void SetInitImport(std::vector<MS::MadeScore> newInitImport) { initImport = newInitImport; };
		
	};
}

