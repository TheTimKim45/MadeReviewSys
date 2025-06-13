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
		for (auto& entry : GameList)
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
		for (auto& g : GameList)
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
		if (GameList.size() <= 1)
			return;
		int gc_ind = 0;
		int gradeCrit = 0;
		if (!desc)
		{
			//default ascending order
			gradeCrit = GameList[gc_ind].Get_GameGrade();
			for (int i = 0; i < GameList.size() - 1; ++i)
			{
				
				if (gradeCrit < GameList[i + 1].Get_GameGrade())
				{
					gc_ind = i + 1;
					gradeCrit = GameList[gc_ind].Get_GameGrade();
					std::swap(GameList[i], GameList[i + 1]);
				}
			}
		}
		else
		{
			//flag checkk for descending order per user's requeset
			gc_ind = GameList.size() - 1;
			gradeCrit = GameList[gc_ind].Get_GameGrade();
			for (int i = gc_ind; i > 0; --i)
			{
				if (gradeCrit > GameList[i - 1].Get_GameGrade())
				{
					gc_ind--;
					gradeCrit = GameList[gc_ind].Get_GameGrade();
					std::swap(GameList[i], GameList[i - 1]);
				}
			}
		}
	}

	//Function that Transfers from INITIAL to SORTED
	//NOTE: SORT still requires SORTLIST function call
	void MadeList::FinalizeInitList()
	{
		bool titleMatched = false;
		for (int i = 0; i < GameList.size(); ++i)
		{
			std::string titleCmp = GameList[i].Get_GameTitle();
			for (int j = i + 1; j < GameList.size(); ++j)
			{
				if (std::strcmp(titleCmp.c_str(), GameList[j].Get_GameTitle().c_str()) == 0)
				{
					GameList[i] = GameList[i].CombineDupTitles(GameList[j]);
					if(j != GameList.size() - 1)
						std::swap(GameList[j], GameList[GameList.size() - 1]);
					GameList.pop_back();
					titleMatched = true;
					--j;
				}
			}
		}
		//SortList(0);
	}
	/*void MadeList::CrunchList()
	{
		for (auto& g : GameList)
			g.CrunchTitleEntry(g);
	}*/
	void MadeList::AddToList(MS::MadeScore game)
	{
		GameList.push_back(game);
	}
	void MadeList::DisplayList()
	{
		for (auto& entry : GameList)
		{
			printf("TITLE : %s\n\nREVIEW STATS:\n", entry.Get_GameTitle().c_str());
			entry.Print_Menu();
		}
	}
}
