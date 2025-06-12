#include "MadeList.h"

namespace ML
{
	MadeList::MadeList()
	{
	}

	//More for End Users
	void MadeList::ImportList()
	{
		//std::ifstream InStream;
		printf("List Imported!\n");
		int i = 1;
		for (auto& entry : ScoreList)
		{
			printf("%d : ENTRY ADDED\n", i);
			i++;
		}
	}

	//More for Reviewers/Editors
	void MadeList::ExportList()
	{

	}

	std::unordered_map<std::string, MS::MadeScore> MadeList::SortList(std::unordered_map<std::string, MS::MadeScore> unsorted)
	{
		std::unordered_map<std::string, MS::MadeScore> sorted;
		for (auto& games : unsorted)
		{
			if (games.second.Get_GameGrade() >= 100)
				printf("whoopee!\n");
		}
		return sorted;
	}
	void MadeList::AddToList(std::string title, MS::MadeScore score)
	{

		ScoreList.insert(std::make_pair(title, score));
	}
	void MadeList::DisplayList()
	{
		for (auto& entry : ScoreList)
		{
			printf("TITLE : %s\n\nREVIEW STATS:\n", entry.first.c_str());
			entry.second.Print_Menu();
		}
	}
}
