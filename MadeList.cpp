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
		for (auto& entry : GameList_INIT)
		{
			printf("%d : ENTRY ADDED\n", i);
			i++;
		}
	}

	//More for Reviewers/Editors
	void MadeList::ExportList()
	{

	}

	std::vector<MS::MadeScore> MadeList::SortList(std::vector<MS::MadeScore> unsorted)
	{
		std::vector<MS::MadeScore> sorted;
		for (auto& games : unsorted)
		{
			if (games.Get_GameGrade() >= 100)
				printf("whoopee!\n");
		}
		return sorted;
	}
	void MadeList::AddToList(MS::MadeScore game)
	{

		GameList_INIT.push_back(game);
	}
	void MadeList::DisplayList()
	{
		for (auto& entry : GameList_INIT)
		{
			printf("TITLE : %s\n\nREVIEW STATS:\n", entry.Get_GameTitle().c_str());
			entry.Print_Menu();
		}
	}
}
