//Our main App folder
#include <iostream>
#include "MadeScore.h"
#include "MadeList.h"

//Main() is our backend testing function
int main() 
{
	using namespace ML;
	using namespace MS;
	MadeList GameTitleList;
	GameTitleList.ImportList();
	MadeScore testScore;

	//TankHead Score Emulation Test
	testScore.Set_Game_Title("TankHead");
	//M_DIVISION_CAT
	testScore.Set_CAT_Grade(0, testScore.Get_M_C1());
	testScore.Set_CAT_Weight(0, testScore.Get_M_C1());
	testScore.Set_CAT_Grade(0, testScore.Get_M_C2());
	testScore.Set_CAT_Weight(0, testScore.Get_M_C2());
	testScore.Set_CAT_Grade(0, testScore.Get_M_C3());
	testScore.Set_CAT_Weight(1, testScore.Get_M_C3());

	testScore.Set_DIV_Weight(4, testScore.Get_M());

	//A_DIVISION_CAT
	testScore.Set_CAT_Grade(0, testScore.Get_A_C1());
	testScore.Set_CAT_Weight(0, testScore.Get_A_C1());
	testScore.Set_CAT_Grade(0, testScore.Get_A_C2());
	testScore.Set_CAT_Weight(0, testScore.Get_A_C2());
	testScore.Set_CAT_Grade(0, testScore.Get_A_C3());
	testScore.Set_CAT_Weight(0, testScore.Get_A_C3());

	testScore.Set_DIV_Weight(4, testScore.Get_A());

	//D_DIVISION_CAT
	testScore.Set_CAT_Grade(0, testScore.Get_D_C1());
	testScore.Set_CAT_Weight(0, testScore.Get_D_C1());
	testScore.Set_CAT_Grade(0, testScore.Get_D_C2());
	testScore.Set_CAT_Weight(3, testScore.Get_D_C2());
	testScore.Set_CAT_Grade(0, testScore.Get_D_C3());
	testScore.Set_CAT_Weight(3, testScore.Get_D_C3());

	testScore.Set_DIV_Weight(3, testScore.Get_D());

	//E_DIVISION_CAT
	testScore.Set_CAT_Grade(0, testScore.Get_E_C1());
	testScore.Set_CAT_Weight(3, testScore.Get_E_C1());
	testScore.Set_CAT_Grade(0, testScore.Get_E_C2());
	testScore.Set_CAT_Weight(0, testScore.Get_E_C2());
	testScore.Set_CAT_Grade(0, testScore.Get_E_C3());
	testScore.Set_CAT_Weight(1, testScore.Get_E_C3());

	testScore.Set_DIV_Weight(3, testScore.Get_E());

	//Pre-Calculation Phase - Requires Transferrence from ScoreDIV.CAT to AGRCAT DS
	testScore.Add_To_AGRCAT(testScore.Get_M(), testScore.CalcDivCat(0));
	testScore.Add_To_AGRCAT(testScore.Get_A(), testScore.CalcDivCat(1));
	testScore.Add_To_AGRCAT(testScore.Get_D(), testScore.CalcDivCat(2));
	testScore.Add_To_AGRCAT(testScore.Get_E(), testScore.CalcDivCat(3));

	//END TEST GAME ENTRY

	//testScore.CrunchTitleEntry(testScore);
	//Duplicate Entry
	MadeScore testScore2 = testScore;
	MadeScore testScore3 = testScore;
	
	//Add testScore to ScoreList
	GameTitleList.AddToList(testScore);
	GameTitleList.AddToList(testScore2);
	GameTitleList.AddToList(testScore3);
	GameTitleList.TransferLists();
	GameTitleList.CrunchList();

	//Print Results!
	GameTitleList.DisplayList();

	return 0;
}