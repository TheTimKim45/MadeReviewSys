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

	void MadeList::GradeList()
	{
		//Everytime USER sets preference, call this func
		for (auto& g : GameList_SORT)
		{
			g.Set_DIV_Grade(g.Get_M(), g.CalcDivCat(0));
			g.Set_DIV_Grade(g.Get_A(), g.CalcDivCat(1));
			g.Set_DIV_Grade(g.Get_D(), g.CalcDivCat(2));
			g.Set_DIV_Grade(g.Get_E(), g.CalcDivCat(3));
			g.CalculateFinalGrade();
		}
		SortList(0);
	}

	void MadeList::SortList(bool desc)
	{
		if (GameList_SORT.size() <= 1)
			return;
		int gc_ind = 0;
		int gradeCrit = 0;
		if (!desc)
		{
			//default ascending order
			gradeCrit = GameList_SORT[gc_ind].Get_GameGrade();
			for (int i = 0; i < GameList_SORT.size() - 1; ++i)
			{
				
				if (gradeCrit < GameList_SORT[i + 1].Get_GameGrade())
				{
					gc_ind = i + 1;
					gradeCrit = GameList_SORT[gc_ind].Get_GameGrade();
					std::swap(GameList_SORT[i], GameList_SORT[i + 1]);
				}
			}
		}
		else
		{
			//flag checkk for descending order per user's requeset
			gc_ind = GameList_SORT.size() - 1;
			gradeCrit = GameList_SORT[gc_ind].Get_GameGrade();
			for (int i = gc_ind; i > 0; --i)
			{
				if (gradeCrit > GameList_SORT[i - 1].Get_GameGrade())
				{
					gc_ind--;
					gradeCrit = GameList_SORT[gc_ind].Get_GameGrade();
					std::swap(GameList_SORT[i], GameList_SORT[i - 1]);
				}
			}
		}
	}

	//Function that Transfers from INITIAL to SORTED
	//NOTE: SORT still requires SORTLIST function call
	void MadeList::TransferLists()
	{
		bool titleMatched = false;
		for (int i = 0; i < GameList_INIT.size(); ++i)
		{
			std::string titleCmp = GameList_INIT[i].Get_GameTitle();
			for (int j = i + 1; j < GameList_INIT.size(); ++j)
			{
				if (std::strcmp(titleCmp.c_str(), GameList_INIT[j].Get_GameTitle().c_str()) == 0)
				{
					//ISSUE: This only works with TWO Titles in INIT, but fails to work if there are more than 2
					GameList_SORT.push_back(GameList_INIT[i].CombineDupTitles(GameList_INIT[j]));
					if(j != GameList_INIT.size() - 1)
						std::swap(GameList_INIT[j], GameList_INIT[GameList_INIT.size() - 1]);
					GameList_INIT.pop_back();
					titleMatched = true;
				}
			}
			if (!titleMatched)
			{
				GameList_SORT.push_back(GameList_INIT[i]);
			}
			else
				titleMatched = false;
		}
		SortList(0);
	}
	void MadeList::CrunchList()
	{
		for (auto& g : GameList_SORT)
			g.CrunchTitleEntry(g);
	}
	void MadeList::AddToList(MS::MadeScore game)
	{
		GameList_INIT.push_back(game);
	}
	void MadeList::DisplayList()
	{
		for (auto& entry : GameList_SORT)
		{
			printf("TITLE : %s\n\nREVIEW STATS:\n", entry.Get_GameTitle().c_str());
			entry.Print_Menu();
		}
	}
}
